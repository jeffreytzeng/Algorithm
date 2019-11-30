def Sort(arr):
    for unsort in reversed(range(1, len(arr))):
        for i in range(unsort):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]


n = int(input())
numbers = list(map(int, input().split()))
Sort(numbers)

for index in range(len(numbers)):
    print(numbers[index] if index == len(numbers)-1 else str(numbers[index]) + " ", end='')
