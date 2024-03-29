import random

class QuickSortArray():
	def __init__(self):
		self.array = list()

	def CheckCorrect(self):
		correct = True
		for index in range(len(self.array)-1):
			if self.array[index] > self.array[index+1]:
				correct = False

		return correct

	def CleanArray(self):
		self.array.clear()

	def Insert(self, number):
		self.array.append(number)

	def OrderedWithIn3(self, start, end):
		length = end - start + 1
		middle = end

		if length == 2:
			if self.array[start] > self.array[end]:
				self.array[start], self.array[end] = self.array[end], self.array[start]
		elif length == 3:
			middle = int((start + end) / 2)

			if self.array[start] > self.array[end]:
				self.array[start], self.array[end] = self.array[end], self.array[start]
			if self.array[middle] > self.array[end]:
				self.array[middle], self.array[end] = self.array[end], self.array[middle]
			if self.array[start] > self.array[middle]:
				self.array[start], self.array[middle] = self.array[middle], self.array[start]

		self.array[middle], self.array[end] = self.array[end], self.array[middle]
		return middle

	def Partition(self, start, end, pivot):
		left = start
		right = end

		while True:
			for l in range(left, end+1):
				left = l
				if self.array[l] > self.array[pivot]:
					break

			for r in reversed(range(start, right)):
				right = r
				if self.array[r] < self.array[pivot]:
					break

			if left >= right:
				break
			else:
				self.array[left], self.array[right] = self.array[right], self.array[left]

		self.array[left], self.array[pivot] = self.array[pivot], self.array[left]
		return left

	def RandomNumbers(self, numbers):
		for i in range(numbers):
			self.Insert(random.randrange(199))

	def Show(self):
		for index in range(len(self.array)):
			print(str(self.array[index]) if index == len(self.array)-1 else str(self.array[index]) + " ", end='')

		print('')

	def Sort(self, start, end):
		median = self.OrderedWithIn3(start, end)

		if end - start >= 0:
			partition = self.Partition(start, end, median)
			self.Sort(start, partition-1)
			self.Sort(partition+1, end)
