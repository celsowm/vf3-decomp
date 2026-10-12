"""Reject independent-state or input reuse before scene promotion."""
import unittest
from scene_batch_acceptance_audit import require_independent


class IndependenceTests(unittest.TestCase):
    def setUp(self):
        self.development = {'scenarios': [{'state_sha256': 'a'}, {'state_sha256': 'b'}]}
        self.acceptance = {'scenarios': [{'state_sha256': 'c'}, {'state_sha256': 'd'}]}

    def test_distinct_states_do_not_allow_reused_inputs(self):
        with self.assertRaisesRegex(AssertionError, 'input reused'):
            require_independent(self.development, self.acceptance, {'same'}, {'same'})

    def test_distinct_inputs_do_not_allow_reused_state(self):
        self.acceptance['scenarios'][0]['state_sha256'] = 'a'
        with self.assertRaisesRegex(AssertionError, 'state reused'):
            require_independent(self.development, self.acceptance, {'first'}, {'second'})

    def test_complete_independent_sets(self):
        self.assertEqual(require_independent(self.development, self.acceptance, {'first'}, {'second'}), {'c', 'd'})


if __name__ == '__main__':
    unittest.main()
