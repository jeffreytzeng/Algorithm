#include <stdio.h>

void Sort(int *arr, int size);

int main()
{
	int n = 0;
	scanf("%d", &n);
	int numbers[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}

	Sort(numbers, n);

	for (int i = 0; i < n; i++) {
		i == n-1 ? printf("%d", numbers[i]) : printf("%d ", numbers[i]);
	}
	return 0;
}

void Sort(int *arr, int size) {
	for (int i = 0; i < size-1; i++) {
		int min = i;

		for (int j = i+1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
		