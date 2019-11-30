#include <iostream>
using namespace std;

void Merge(int *arr, int &start, int &middle, int &end);
void Show(int *arr, int &size);
void Sort(int *arr, int start, int &end);

int main()
{
	int n = 0; 
	cin >> n;
	int numbers[n];

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int start = 0;
	int end = n-1;
	Sort(numbers, start, end);
	Show(numbers, n);
}

void Merge(int *arr, int &start, int &middle, int &end) {
	int front = middle - start + 1;
	int rear = end - middle;
	int left[front], right[rear];

	for (int i = start; i <= end; i++) {
		i <= middle ? left[i - start] = arr[i] : right[i - middle - 1] = arr[i];
	}

	for (int i = start, l = 0, r = 0; i <= end; i++) {
		if ((l < front) && (r < rear)) {
			arr[i] = left[l] < right[r] ? left[l++] : right[r++];
		} else {
			arr[i] = l < front ? left[l++] : right[r++];
		}
	}
}

void Show(int *arr, int &size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << (i == size-1 ? "" : " ");
	}
}

void Sort(int *arr, int start, int &end) {
	if (start < end) {
		int middle = (start + end) / 2;
		Sort(arr, start, middle);
		Sort(arr, middle+1, end);
		Merge(arr, start, middle, end);
	}
}
