#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int &start, int &middle, int &end);
void Show(vector<int> &arr);
void Sort(vector<int> &arr, int start, int &end);

int main()
{
	int n = 0;
	cin >> n;
	vector<int> numbers(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int start = 0;
	int end = n-1;
	Sort(numbers, start, end);
	Show(numbers);
}

void Merge(vector<int> &arr, int &start, int &middle, int &end) {
	int front = middle - start + 1;
	int rear = end - middle;
	vector<int> left(front, 0), right(rear, 0);

	for (int i = start; i <= end; i++) {
		i <= middle ? left[i-start] = arr[i] : right[i-middle-1] = arr[i];
	}

	for (int i = start, l = 0, r = 0; i <= end; i++) {
		if ((l < front) && (r < rear)) {
			arr[i] = left[l] < right[r] ? left[l++] : right[r++];
		} else {
			arr[i] = l < front ? left[l++] : right[r++];
		}
	}
}

void Show(vector<int> &arr) {
	for (auto it = arr.begin(); it < arr.end(); it++) {
		cout << *it << (it == arr.end() - 1 ? "" : " ");
	}
	cout << endl;
}

void Sort(vector<int> &arr, int start, int &end) {
	if (start < end) {
		int middle = (end + start)/2;
		Sort(arr, start, middle);
		Sort(arr, middle+1, end);
		Merge(arr, start, middle, end);
	}
}