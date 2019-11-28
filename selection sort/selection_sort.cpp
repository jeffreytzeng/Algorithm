#include <iostream>
using namespace std;

void Sort(int *arr, int &size);

int main()
{
	int n = 0;
	cin >> n;

	int numbers[n];

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	Sort(numbers, n);

	for (int i = 0; i < n; i++) {
		cout << (i == n-1 ? to_string(numbers[i]) : to_string(numbers[i]) + " ");
	}
}

void Sort(int *arr, int &size) {
	for (int i = 0; i < size-1; i++) {
		int min = i;

		for (int j = i+1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
