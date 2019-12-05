#include "quick_sort.hpp"
using namespace std;

QuickSortArray::QuickSortArray(int size):
	total_(0)
{
	array_.resize(size);
}

void QuickSortArray::CheckCorrect() {
	bool correct = true;

	for (int i = 0; i < array_.size()-1; i++) {
		if (array_[i] > array_[i+1]) {
			correct = false;
		}
	}
	cout << (correct ? "Ture" : "False");
}

void QuickSortArray::Insert(int number) {
	array_[total_++] = number;
}

int QuickSortArray::OrderedWithIn3(int &start, int &end) {
	int length = end - start + 1;
	int middle = end;

	switch (length) {
		case 1:
			break;
		case 2:
			if (array_[start] > array_[end]) {
				Swap(start, end);
			}
			break;
		case 3:
			middle = (start + end) / 2;

			if (array_[start] > array_[end]) {
				Swap(start, end);
			}
			if (array_[middle] > array_[end]) {
				Swap(middle, end);
			}
			if (array_[start] > array_[middle]) {
				Swap(start, middle);
			}
			break;
	}
	return middle;
}

int QuickSortArray::Partition(int &start, int &end, int &pivot) {
	int left = start - 1;
	int right = end;

	while (true) {
		while (left < end && array_[++left] < array_[pivot]) {
		}
		while (right > start && array_[--right] > array_[pivot]) {
		}

		if (left >= right) {
			break;
		} else {
			Swap(left, right);
		}
	}
	Swap(left, pivot);
	return left;
}

void QuickSortArray::QuickSort() {
	Sort(0, array_.size()-1);
}

void QuickSortArray::Show() {
	for (int i = 0; i < array_.size(); i++) {
		cout << array_[i] << (i == array_.size()-1 ? "" : " ");
	}
	cout << endl;
}

void QuickSortArray::Sort(int start, int end) {
	int median = OrderedWithIn3(start, end);

	if (end - start >= 0) {
		int partition = Partition(start, end, median);
		Sort(start, partition-1);
		Sort(partition+1, end);
	}
}

void QuickSortArray::Swap(int &left, int &right) {
	int temp = array_[left];
	array_[left] = array_[right];
	array_[right] = temp;
}
