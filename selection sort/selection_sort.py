def Sort(arr):
    """Selection sort algorithm."""
    for i in range(len(arr)-1):
        min = i

        for j in range(i+1, len(arr)):
            if arr[j] < arr[min]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]


n = int(input())
numbers = list(map(int, input().split()))

Sort(numbers)

for index in range(len(numbers)):
    print(str(numbers[index])
          if index == len(numbers)-1
          else str(numbers[index]) + " ",
          end='')
    