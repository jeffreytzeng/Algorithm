#include <stdio.h>

void Sort(int *arr, int *size);

int main()
{
	int n = 0;
	scanf("%d", &n);
	int numbers[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}

	Sort(numbers, &n);

	for (int i = 0; i < n; i++) {
		i == n-1 ? printf("%d", numbers[i]) : printf("%d ", numbers[i]);
	}
	return 0;
}

void Sort(int *arr, int *size) {
	for (int unsort = *size-1; unsort > 0; unsort--) {
		for (int i = 0; i < unsort; i++) {
			if (arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}
