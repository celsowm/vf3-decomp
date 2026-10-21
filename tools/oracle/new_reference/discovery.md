# Official Flycast source discovery

- Target: https://github.com/flyinghead/flycast and its official GitHub API.
- Needed: exact public source revision, build options, pinned submodule commits.
- Source: Git repository and documented GitHub JSON API, not scraped HTML.
- Evidence: `gh api repos/flyinghead/flycast` identifies the official repository;
  `gh api repos/flyinghead/flycast/commits/master` returned
  `31697241b7c57c52df8382493e896667e654242c` on 2026-10-21.
- Retrieval: shallow clone, exact commit assertion, only required submodules.
  Git handles object pagination. API requests are single metadata reads.
- Load policy: no polling, no concurrent repeated fetches, preserve checkout and
  build cache. No browser is needed. No game assets are sent to a service.
- This is a new reference. It does not reproduce the missing historical oracle
  executables or validate their old seals.
