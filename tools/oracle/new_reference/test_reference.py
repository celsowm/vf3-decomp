#!/usr/bin/env python3
"""Local fixtures for cache projection and bounded capture argument handling."""
import json
from pathlib import Path
import struct
import subprocess
import sys
import unittest

from cache_overlay import project


class CacheProjection(unittest.TestCase):
    def setUp(self):
        self.raw=bytes(0x1000000)
        self.cache=bytearray(30744)
        struct.pack_into('<II',self.cache,0,854,len(self.raw))
        self.metadata=dict(ccr=1,mmucr=0,cache_serializer_version=854)

    def line(self,index,physical,dirty,fill):
        offset=8+256*40+index*40
        struct.pack_into('<BB2xI',self.cache,offset,1,dirty,physical>>10)
        self.cache[offset+8:offset+40]=bytes([fill])*32

    def test_dirty_and_clean_stale_lines_are_both_cpu_visible(self):
        self.line(0,0x0c000000,1,0x31)
        self.line(1,0x0c000020,0,0x52)
        before=bytes(self.cache)
        data,report=project(self.metadata,self.raw,self.cache)
        self.assertEqual(data[:64],bytes([0x31])*32+bytes([0x52])*32)
        self.assertEqual(report['changed_bytes'],64)
        self.assertEqual(bytes(self.cache),before)

    def test_disabled_cache_is_raw_ram(self):
        self.line(0,0x0c000000,1,0x31)
        self.metadata['ccr']=0
        data,report=project(self.metadata,self.raw,self.cache)
        self.assertEqual(data,self.raw)
        self.assertFalse(report['rows'][0]['applied'])

    def test_wrong_index_cannot_override_matching_line(self):
        self.line(32,0x0c000400,1,0x31)
        self.line(64,0x0c000400,1,0x52)
        data,report=project(self.metadata,self.raw,self.cache)
        self.assertEqual(data[0x400:0x420],bytes([0x31])*32)
        self.assertFalse(report['rows'][1]['applied'])

    def test_ora_reserved_line_and_oix(self):
        self.line(128,0x0c001000,1,0x31)
        self.metadata['ccr']=0x21
        self.assertEqual(project(self.metadata,self.raw,self.cache)[0],self.raw)
        self.metadata['ccr']=0x81
        self.assertEqual(project(self.metadata,self.raw,self.cache)[0][0x1000:0x1020],bytes([0x31])*32)

    def test_wrong_abi_version_flags_fail_closed(self):
        with self.assertRaises(ValueError): project(self.metadata,self.raw,self.cache[:-1])
        self.metadata['cache_serializer_version']=853
        with self.assertRaises(ValueError): project(self.metadata,self.raw,self.cache)
        struct.pack_into('<I',self.cache,0,853)
        with self.assertRaises(ValueError): project(self.metadata,self.raw,self.cache)
        struct.pack_into('<I',self.cache,0,854)
        self.metadata['cache_serializer_version']=854
        self.cache[8+256*40]=2
        with self.assertRaises(ValueError): project(self.metadata,self.raw,self.cache)


class CaptureBounds(unittest.TestCase):
    def test_bad_bounds_rejected_before_loading_inputs(self):
        script=Path(__file__).with_name('capture.py')
        prefix=[sys.executable,str(script),'--work-dir','/nonexistent/reference',
                '--gdi','/nonexistent/media.gdi','--out','/nonexistent/output','--pc','0xc010000']
        for option,value in [('--frames','0'),('--frames','-1'),('--instructions','0'),
                             ('--instructions','2000000001'),('--timeout','-1'),
                             ('--timeout','1801'),('--snapshots','17')]:
            result=subprocess.run(prefix+[option,value],capture_output=True,text=True)
            self.assertEqual(result.returncode,2,(option,result.stderr))
            self.assertNotIn('Traceback',result.stderr)
        result=subprocess.run(prefix+['--pc','0x8c010000'],capture_output=True,text=True)
        self.assertEqual(result.returncode,2)
        self.assertIn('duplicate canonical',result.stderr)


if __name__=='__main__': unittest.main()
