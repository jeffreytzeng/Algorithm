#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CheckCorrect(int *arr, int *size);
int OrderedWithIn3(int *arr, int *start, int *end);
int Partition(int *arr, int *start, int *end, int *pivot);
void Show(int *arr, int *size);
void Sort(int *arr, int start, int end);
void Swap(int *arr, int *left, int *right);

int main()
{
	srand(time(NULL));
	int n = 16;
	int numbers[n];

	for (int i = 0; i < n; i++) {
		numbers[i] = rand() % 199;
	}

	Sort(numbers, 0, n-1);
	Show(numbers, &n);
	CheckCorrect(numbers, &n);	// Check is array in ascending order
	return 0;
}

void CheckCorrect(int *arr, int *size) {
	enum check {False, True};
	enum check correct = True;

	for (int i = 0; i < *size-1; i++) {
		if (arr[i] > arr[i+1]) {
			correct = False;
		}
	}

	correct ? printf("True") : printf("False");
}

/*
	Elimination of O(n^2) situation when data is in descending order.
	And using last item for pivot value when items are less than 3.
*/
int OrderedWithIn3(int *arr, int *start, int *end) {
	int length = *end - *start + 1;
	int median = *end;

	switch (length) {
		case 1:
			break;
		case 2:
			if (arr[*start] > arr[*end]) {
				Swap(arr, start, end);
			}
			break;
		case 3:
			median = (*start + *end) / 2;

			if (arr[*start] > arr[*end]) {
				Swap(arr, start, end);
			}
			if (arr[median] > arr[*end]) {
				Swap(arr, &median, end);
			}
			if (arr[*start] > arr[median]) {
				Swap(arr, start, &median);
			}
			break;
	}
	return median;
}

int Partition(int *arr, int *start, int *end, int *pivot) {
	int left = *start-1;
	int right = *end;			// Last item no needs to compare with itself.

	while (1) {
		while (left < *end && arr[++left] < arr[*pivot]) {
		}						// Do nothing and exit when item bigger than pivot.
		while (right > *start && arr[--right] > arr[*pivot]) {
		}						// Exiting when find item smaller than pivot.

		if (left >= right) {
			break;
		} else {
			Swap(arr, &left, &right);
		}
	}
	Swap(arr, &left, pivot);	// Swap pivot to middle after all compare.
	return left;
}

void Show(int *arr, int *size) {
	for (int i = 0; i < *size; i++) {
		i == *size - 1 ? printf("%d", arr[i]) : printf("%d ", arr[i]);
	}
	printf("\n");
}

void Sort(int *arr, int start, int end) {
	int pivot = OrderedWithIn3(arr, &start, &end);
	if (end - start >= 0) {
		int partition = Partition(arr, &start, &end, &pivot);
		Sort(arr, start, partition-1);	// Pivot already in position no need to sort again.
		Sort(arr, partition+1, end);	// Same as above.
	}
}

void Swap(int *arr, int *left, int *right) {
	int temp = arr[*left];
	arr[*left] = arr[*right];
	arr[*right] = temp;
}