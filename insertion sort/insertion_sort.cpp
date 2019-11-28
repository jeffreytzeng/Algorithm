#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int> &arr) {
	for (int i = 1; i < arr.size(); i++) {
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
	cin >> size;
	vector<int> numbers(size, 0);
	
	for (int i = 0; i < size; i++) {
		cin >> numbers[i];
	}
	
	Sort(numbers);
	
	for (int i = 0; i < size; i++) {
		cout << (i == size-1 ? to_string(numbers[i]) : to_string(numbers[i]) + " ");
	}
}
	