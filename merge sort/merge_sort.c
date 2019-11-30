#include <stdio.h>

void Merge(int *arr, int *start, int *middle, int *end);
void Show(int *arr, int *size);
void Sort(int *arr, int start, int *end);

int main()
{
	int n = 0;
	scanf("%d", &n);
	int numbers[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}

	int end = n-1;
	Sort(numbers, 0, &end);
	Show(numbers, &n);
	return 0;
}

void Merge(int *arr, int *start, int *middle, int *end) {
	int front = *middle - *start + 1;
	int rear = *end - *middle;
	int left[front], right[rear];

	for (int i = *start; i <= *end; i++) {
        if (i <= *middle) {
            left[i - *start] = arr[i];
        } else {
          right[i - *middle-1] = arr[i];
        }
	}

	for (int i = *start, l = 0, r = 0; i <= *end; i++) {
		if ((l < front) && (r < rear)) {
			arr[i] = left[l] < right[r] ? left[l++] : right[r++];
		} else {
			arr[i] = l < front ? left[l++] : right[r++];
		}
	}
}

void Show(int *arr, int *size) {
	for (int i = 0; i < *size; i++) {
		i == *size - 1 ? printf("%d", arr[i]) : printf("%d ", arr[i]);
	}
	printf("\n");
}

void Sort(int *arr, int start, int *end) {
	if (start < *end) {
		int middle = (start + *end) / 2;
		Sort(arr, start, &middle);
		Sort(arr, middle+1, end);
		Merge(arr, &start, &middle, end);
	}
}