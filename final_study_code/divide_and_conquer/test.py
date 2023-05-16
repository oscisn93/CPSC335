import unittest
from main import summation, summation2, merge_sort

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
        self.assertEqual(summation2(test_inputs[idx]), exp)


  def test_sort(self):
    test_inputs = [
      [1],
      [1,2],
      [2,1],
      [1,32,3,55,1,0,-1,43]
    ]
    expected_output = [
      [1],
      [1,2],
      [1,2],
      [-1,0,1,1,3,32,43,55]
    ]
    for idx, exp in enumerate(expected_output):
      self.assertEqual(merge_sort(test_inputs[idx]), exp)
