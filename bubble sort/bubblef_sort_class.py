class BubbleArray():
    """Array with bubble sort function."""
    def __init__(self):
        """Initial array when construct."""
        self.array = list()

    def Insert(self, number):
        """Inserting number in array."""
        self.array.append(int(number))

    def Sort(self):
        """Sorting array with bubble sort."""
        for unsort in reversed(range(1, len(self.array))):
            for i in range(unsort):
                if self.array[i] > self.array[i+1]:
                    self.array[i], self.array[i+1] = self.array[i+1], self.array[i]

    def Print(self):
        """Show all elements in array."""
        for index in range(len(self.array)):
            print(str(self.array[index]) 
                  if index == len(self.array)-1
                  else str(self.array[index]) + " ", end='')


n = int(input())
strings = input().split()

arr = BubbleArray()

for string in strings:
    arr.Insert(string)

arr.Sort()
arr.Print()