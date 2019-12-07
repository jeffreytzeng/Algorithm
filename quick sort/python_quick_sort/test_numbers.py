import unittest
from quick_sort import QuickSortArray

class NumbersTestCase(unittest.TestCase):
	def setUp(self):
		self.numbers = QuickSortArray()

	def sort_numbers(self, numbers):
		self.numbers.RandomNumbers(numbers)
		self.numbers.Sort(0, numbers-1)
		return self.numbers.CheckCorrect()

	def loop_sort_numbers(self, numbers, times):
		for t in range(times):
			result = self.sort_numbers(numbers)
			self.numbers.CleanArray()
			if result == False:
				break
		return result

	def test_sort_16_numbers(self):
		result = self.sort_numbers(16)
		self.assertTrue(result)

	def test_sort_16_numbers_10_times(self):
		result = self.loop_sort_numbers(16, 10)
		self.assertTrue(result)

	def test_sort_10000_numbers(self):
		result = self.sort_numbers(10000)
		self.assertTrue(result)

	def test_sort_10000_numbers_100_times(self):
		result = self.loop_sort_numbers(10000, 100)
		self.assertTrue(result)


unittest.main()