"""Candidate planning must subtract accepted and overlapping address ranges."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import candidate_margin


class CandidateMarginTests(unittest.TestCase):
    def measure(self,owners,spans):
        with tempfile.TemporaryDirectory() as name:
            coverage=Path(name)/'coverage.json'
            coverage.write_text(json.dumps(dict(ported_spans=[[100,110]],ported_unique_bytes=10)))
            with patch.object(candidate_margin,'body_spans',return_value=spans),patch.object(candidate_margin,'reference',return_value={}):
                return candidate_margin.measure(owners,coverage,30)

    def test_existing_bytes_have_zero_margin(self):
        result=self.measure([1],{1:[(102,108)]})
        self.assertEqual(result['candidates'][0]['frozen_bytes'],6)
        self.assertEqual(result['potential_unique_bytes'],0)
        self.assertEqual(result['potential_shortfall'],20)

    def test_overlapping_and_repeated_candidates_count_once(self):
        result=self.measure([1,2,1],{1:[(105,120)],2:[(115,125)]})
        self.assertEqual(result['potential_unique_bytes'],15)
        self.assertEqual(result['potential_shortfall'],5)
        self.assertEqual(len(result['candidates']),2)

    def test_unknown_owner_is_rejected(self):
        with self.assertRaises(ValueError):self.measure([1],{})


if __name__=='__main__':unittest.main()
