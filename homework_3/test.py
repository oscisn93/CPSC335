import unittest
from main import list_reversal, offline_ski_rental, set_difference, set_union


class TestMethods(unittest.TestCase):
  def test_set_union(self):
    # test cases
    inputs = [
      [[1, 2, 3], [2, 3, 4]],
      [[1, 2, 3], [4, 5, 6]],
      [[1, 2, 3], [1, 2, 3]],
    ]
    # expected outputs
    outputs = [
      [1, 2, 3, 4],
      [1, 2, 3, 4, 5, 6],
      [1, 2, 3],
    ]
    for i in range(len(inputs)):
      left = inputs[i][0]
      right = inputs[i][1]
      result = set_union(left, right)
      self.assertEqual(result, outputs[i])
  

  def test_set_difference(self):
    inputs = [
        [[1, 2, 3], [2, 3, 4]],
        [[1, 2, 3], [4, 5, 6]],
        [[1, 2, 3], [1, 2, 3]],
        [[1, 2, 3], [1, 2, 3, 4]]
    ]
    outputs = [
        [1], [1,2,3], [], []
    ]
    for i in range(len(inputs)):
        left = inputs[i][0]
        right = inputs[i][1]
        result = outputs[i]
        self.assertEqual(set_difference(left, right), result)
    
  
  def test_offline_ski_rental(self):
    inputs = [
        (10, 100, 10),
        (10, 100, 11),
        (10, 100, 9)
    ]
    outputs = [True, False, True]
    
    for i in range(len(inputs)):
        rental_price = inputs[i][0]
        purchase_price = inputs[i][1]
        days = inputs[i][2]
        result = outputs[i]
        self.assertEqual(offline_ski_rental(rental_price, purchase_price, days), result)

  
  def test_list_reversal(self):
    inputs = [
        [1,2,3],
        [1,2,3,4],
        [],
        [1],
        [1,2]
    ]
    outputs = [
        [3, 2, 1],
        [4, 3, 2, 1],
        [],
        [1],
        [2, 1]
    ]
    for i in range(len(inputs)):
        result = outputs[i]
        self.assertEqual(list_reversal(inputs[i]), result)


if __name__ == '__main__':
  unittest.main()

