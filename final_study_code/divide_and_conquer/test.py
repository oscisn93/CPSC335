import unittest
from main import summation


class TestAlgorithms(unittest.TestCase):

    def test_summation(self):
        test_inputs = [
            [1,3,2,4],
            [1,-1]
        ]
        expected_output = [10, 0]
        for idx, exp in enumerate(expected_output):
            self.assertEqual(summation(test_inputs[idx]), exp)

    def test_sum(self):
        test_inputs = [
            [1,3,2,4],
            [1,-1]
        ]
        expected_output = [10, 0]
        for idx, exp in enumerate(expected_output):
            self.assertEqual(summation(test_inputs[idx]), exp)

