def Merge(arr, start, middle, end):
	"""Merging two arrays by ascending order."""
	front = middle - start + 1
	rear = end - middle
	left = [arr[i+start] for i in range(front)]
	right = [arr[i+middle+1] for i in range(rear)]
	l = 0
	r = 0

	for i in range(start, end+1):
		if l < front and r < rear:
			if left[l] < right[r]:
				arr[i] = left[l]
				l += 1
			else:
				arr[i] = right[r]
				r += 1
		else:
			if l < front:
				arr[i] = left[l]
				l += 1
			else:
				arr[i] = right[r]
				r += 1

				
def Show(arr):
	"""Display all elements in an array."""
	for i in range(len(arr)):
		print(str(arr[i]) if i == len(arr)-1 else str(arr[i]) + ' ', end='')


def Sort(arr, start, end):
	"""Sorting array to two arrays."""
	if start < end:
		middle = int((start + end) / 2)
		Sort(arr, start, middle)
		Sort(arr, middle+1, end)
		Merge(arr, start, middle, end)


n = int(input())
numbers = list(map(int, input().split()))
Sort(numbers, 0, n-1)
Show(numbers)