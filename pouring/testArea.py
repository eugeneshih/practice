import unittest
import area

class testArea(unittest.TestCase):

    def setUp(self):
        self.ushaped_array = [10, 9, 8, 7, 6, 7, 8, 9]
        self.wshaped_array = [8, 7, 9, 9, 5, 6, 7, 8, 9]
        self.lshaped_array = [5, 6, 7, 10, 12, 10, 7, 4, 3]

    def test_find_maximum_left_linear_basic(self):
        test_max_left = [10, 10, 10, 10, 10, 10, 10, 10]
        result = area.find_maximum_left_linear(self.ushaped_array)
        self.assertEquals(test_max_left, result)

    def test_find_maximum_left_linear_bumps(self):
        test_max_left = [8, 8, 9, 9, 9, 9, 9, 9, 9]
        result = area.find_maximum_left_linear(self.wshaped_array)
        self.assertEquals(test_max_left, result)

    def test_find_maximum_left_linear_spike(self):
        test_max_left = [5, 6, 7, 10, 12, 12, 12, 12, 12]
        result = area.find_maximum_left_linear(self.lshaped_array)
        self.assertEquals(test_max_left, result)

    def test_area_basic(self):
        result = area.find_area(self.ushaped_array)
        expected = 1 + 2 + 3 + 2 + 1
        self.assertEquals(result, expected)

if __name__ == '__main__':
    unittest.main()

