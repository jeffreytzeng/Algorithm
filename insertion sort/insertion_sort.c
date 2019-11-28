#include <stdio.h>

void Sort(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && key <= arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main()
{
	int size = 0;
	scanf("%d", &size);
	int numbers[size];

	for (int i = 0; i < size; i++) {
		scanf("%d", numbers + i);
	}

	Sort(numbers, size);

	for (int i = 0; i < size; i++) {
		i == size-1 ? printf("%d", numbers[i]) : printf("%d ", numbers[i]);
	}
	return 0;
}