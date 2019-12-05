class MergeSortArray():
    """A class performing merge sort algorithm."""
    def __init__(self, size):
        """Initializing parameters when construct class."""
        self.arr = list()
        self.end = size - 1
        self.size = size
        self.start = 0

    def Insert(self, number):
        """Inserting number into array."""
        self.arr.append(number)

    def Merge(self, start, middle, end):
        """Merging two arrays by ascending."""
        front = middle - start + 1
        rear = end - middle
        left = [self.arr[index] for index in range(start, middle+1)]
        right = [self.arr[index] for index in range(middle+1, end+1)]

        l = 0
        r = 0
        for index in range(start, end+1):
            if l < front and r < rear:
                if left[l] < right[r]:
                    self.arr[index] = left[l]
                    l += 1
                else:
                    self.arr[index] = right[r]
                    r += 1
            else:
                if l < front:
                    self.arr[index] = left[l]
                    l += 1
                else:
                    self.arr[index] = right[r]
                    r += 1

    def Show(self):
        """Show every element in the array separate by space."""
        for index in range(len(self.arr)):
            print(str(self.arr[index]) if index == len(self.arr)-1 else str(self.arr[index]) + " ", end='')

    def Sort(self, start, end):
        """Sort array into two arrays."""
        if start < end:
            middle = int((start + end) / 2)
            self.Sort(start, middle)
            self.Sort(middle+1, end)
            self.Merge(start, middle, end)


n = int(input())
numbers = MergeSortArray(n)
for number in list(map(int, input().split())):
    numbers.Insert(number)

numbers.Sort(0, n-1)
numbers.Show()
        