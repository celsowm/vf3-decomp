#!/usr/bin/env python3
"""Install the isolated passive reference overlay into its exact official pin."""
import argparse
from pathlib import Path
import shutil
import subprocess

PIN = '31697241b7c57c52df8382493e896667e654242c'

def install(root):
    actual = subprocess.check_output(['git', '-C', str(root), 'rev-parse', 'HEAD'], text=True).strip()
    if actual != PIN:
        raise ValueError(f'Expected official Flycast {PIN}, got {actual}')
    def replace(name, old, new):
        path = root / name
        text = path.read_text()
        if new in text:
            return
        if text.count(old) != 1:
            raise ValueError(f'Expected one pinned anchor: {name}: {old!r}')
        path.write_text(text.replace(old, new), encoding='utf-8')
    here = Path(__file__).resolve().parent
    for source, destination in [('observer.cpp', 'vf3_new_reference.cpp'), ('observer.h', 'vf3_new_reference.h')]:
        shutil.copyfile(here/source, root/'core'/destination)
    replace('core/hw/sh4/interpr/sh4_interpreter.cpp', '#include "../sh4_cycles.h"',
            '#include "../sh4_cycles.h"\n#include "vf3_new_reference.h"')
    replace('core/hw/sh4/interpr/sh4_interpreter.cpp', '\treturn IReadMem16(addr);',
            '\tu16 op = IReadMem16(addr);\n\tvf3NewReferenceBefore(addr, op, ctx);\n\treturn op;')
    replace('core/hw/sh4/sh4_interrupts.cpp', '#include "types.h"',
            '#include "types.h"\n#include "vf3_new_reference.h"')
    replace('core/hw/sh4/sh4_interrupts.cpp', 'static void Do_Interrupt(Sh4ExceptionCode intEvn)\n{',
            'static void Do_Interrupt(Sh4ExceptionCode intEvn)\n{\n\tvf3NewReferenceEvent(true,(unsigned)intEvn,Sh4cntx.pc);')
    replace('core/hw/sh4/sh4_interrupts.cpp', 'void Do_Exception(u32 epc, Sh4ExceptionCode expEvn)\n{',
            'void Do_Exception(u32 epc, Sh4ExceptionCode expEvn)\n{\n\tvf3NewReferenceEvent(false,(unsigned)expEvn,epc);')
    replace('shell/libretro/libretro.cpp', '\tif (!foundRenderApi)\n\t\treturn false;',
            '\t// VF3_NEW_REFERENCE: null rendering requires no host graphics context.\n'
            '\tfoundRenderApi = rend_init_renderer();\n'
            '\tif (!foundRenderApi)\n\t\treturn false;')
    replace('shell/libretro/libretro.cpp', '\t\temu.loadGame(game_data.c_str());',
            '\t\t// VF3_NEW_REFERENCE: reference policy, not guest instruction changes.\n'
            '\t\tconfig::DynarecEnabled.override(false);\n'
            '\t\tconfig::ThreadedRendering.override(false);\n'
            '\t\tconfig::UseReios.override(true);\n'
            '\t\tconfig::GGPOEnable.override(false);\n'
            '\t\tconfig::EmulateBBA.override(false);\n'
            '\t\temu.loadGame(game_data.c_str());')
    replace('core/reios/gdrom_hle.cpp', 'static gdrom_hle_state_t gd_hle_state;',
            '''static gdrom_hle_state_t gd_hle_state;
// VF3_NEW_REFERENCE: explicit passive field snapshot; no serializer offsets.
void vf3NewGdSnapshot(unsigned out[22]) {
    const auto &s = gd_hle_state;
    unsigned v[22] = {s.last_request_id,s.next_request_id,(unsigned)s.status,(unsigned)s.command,
        s.params[0],s.params[1],s.params[2],s.params[3],s.result[0],s.result[1],s.result[2],s.result[3],
        s.cur_sector,s.multi_read_sector,s.multi_read_offset,s.multi_read_count,
        s.multi_read_total,s.multi_callback,s.multi_callback_arg,(unsigned)s.dma_trans_ended,
        (unsigned)s.xfer_end_time,(unsigned)(s.xfer_end_time>>32)};
    std::copy(v,v+22,out);
}''')
    path=root/'CMakeLists.txt'
    text=path.read_text()
    marker='# VF3_NEW_REFERENCE passive interpreter overlay'
    if text.count(marker)>1: raise ValueError('duplicate reference CMake overlay')
    # This marked tail belongs entirely to this installer, including upgrades.
    prefix=text.split(marker)[0].rstrip()
    path.write_text(prefix+'\n\n'+marker+'\n'
        'target_sources(${PROJECT_NAME} PRIVATE core/vf3_new_reference.cpp)\n'
        'target_compile_definitions(${PROJECT_NAME} PRIVATE NO_REND)\n'
        'option(VF3_REFERENCE_STRICT "Enable upstream SH4 cache and strict semantics" ON)\n'
        'if(VF3_REFERENCE_STRICT)\n'
        '  target_compile_definitions(${PROJECT_NAME} PRIVATE STRICT_MODE TARGET_NO_REC)\n'
        'endif()\n')
    path=root/'shell/libretro/libretro.osx.def'
    text=path.read_text()
    if '_vf3_new_reference_done' not in text:
        path.write_text(text+'\n_vf3_new_reference_done\n')
    path=root/'shell/libretro/link.T'
    text=path.read_text()
    replace('shell/libretro/link.T', 'retro_*;', 'retro_*; vf3_new_reference_done;')

if __name__ == '__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path)
    install(parser.parse_args().source.resolve())
