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
		cout << (i == n-1 ? to_string(numbers[i]) : to_string(numbers[i]) + " " );
	}
}

void Sort(int *arr, int &size) {
	for (int unsort = size-1; unsort > 0; unsort--) {
		for (int i = 0; i < unsort; i++) {
			if (arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}