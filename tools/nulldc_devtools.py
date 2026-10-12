"""Verify or serve the ignored nullDC DevTools snapshot on localhost."""
import argparse
import hashlib
import json
from functools import partial
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import urlsplit

ROOT = Path(__file__).resolve().parents[1]


class Handler(SimpleHTTPRequestHandler):
    def do_GET(self):
        # React routes need the entry page; missing assets remain genuine 404s.
        path = urlsplit(self.path).path
        if path == "/ws":
            self.send_error(503, "No compatible emulator debugger backend configured")
            return
        if path != "/" and not Path(path).suffix:
            self.path = "/index.html"
        super().do_GET()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="Verify files without starting a server")
    parser.add_argument("--port", type=int, default=8766)
    args = parser.parse_args()
    directory = ROOT / "refs" / "nulldc-devtools"
    manifest = json.loads((directory / "provenance.json").read_text(encoding="utf-8-sig"))
    for item in manifest["files"]:
        path = (directory / item["path"]).resolve()
        if not path.is_relative_to(directory.resolve()):
            raise ValueError("Snapshot manifest path escapes its directory")
        data = path.read_bytes()
        if len(data) != item["bytes"] or hashlib.sha256(data).hexdigest() != item["sha256"]:
            raise ValueError(f"Snapshot changed: {item['path']}")
    print(f"Verified {len(manifest['files'])} snapshot files", flush=True)
    if args.check:
        return
    print(f"Open http://127.0.0.1:{args.port}/ (live emulator backend unavailable)", flush=True)
    with ThreadingHTTPServer(("127.0.0.1", args.port), partial(Handler, directory=str(directory))) as server:
        try:
            server.serve_forever()
        except KeyboardInterrupt:
            pass


if __name__ == "__main__":
    main()
