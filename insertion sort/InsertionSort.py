def Sort(arr):
    """Algorithm insertion sort from low to high."""
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while (j >= 0 and key <= arr[j]):
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = key

size = int(input())
numbers = list(map(int, input().split()))

Sort(numbers)

print(' '.join(map(str, numbers)))