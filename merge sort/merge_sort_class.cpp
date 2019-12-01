#include <iostream>
using namespace std;

class MergeSortArray
{
	public:
		MergeSortArray();
		MergeSortArray(int size);
		~MergeSortArray();

		void Insert(int num);
		void Merge(int &start, int &middle, int &end);
		void Show();
		void Sort(int start, int &end);

	private:
		int capacity_;
		int end_;
		int size_;
		int start_;
		int *arr_;
};

MergeSortArray::MergeSortArray():
	MergeSortArray(0)
{
}

MergeSortArray::MergeSortArray(int size):
	capacity_(size*2),
	end_(size-1),
	size_(0),
	start_(0)
{
	arr_ = new int[size_];
}

MergeSortArray::~MergeSortArray()
{
    delete [] arr_;
}

void MergeSortArray::Insert(int num) {
	if (size_ < capacity_) {
		arr_[size_] = num;
        size_++;
	} else {
		capacity_ *= 2;
		int *array = new int[capacity_];
		for (int i = 0; i < size_; i++) {
			array[i] = arr_[i];
		}
		array[size_] = num;
		delete [] arr_;
		arr_ = array;
        size_++;
	}
}

void MergeSortArray::Merge(int &start, int &middle, int &end) {
	int front = middle - start + 1;
	int rear = end - middle;
	int left[front], right[rear];

	for (int i = start; i <= end; i++) {
		i <= middle ? left[i - start] = arr_[i] : right[i - middle - 1] = arr_[i];
	}

    for (int i = start, l = 0, r = 0; i <= end; i++) {
		if ((l < front) && (r < rear)) {
			arr_[i] = left[l] < right[r] ? left[l++] : right[r++];
		} else {
			arr_[i] = l < front ? left[l++] : right[r++];
		}
	}
}

void MergeSortArray::Show() {
	for (int i = 0; i < size_; i++) {
		cout << arr_[i] << (i == size_-1 ? "" : " ");
	}
	cout << endl;
}

void MergeSortArray::Sort(int start, int &end) {
	if (start < end) {
		int middle = (start + end) / 2;
		Sort(start, middle);
		Sort(middle+1, end);
		Merge(start, middle, end);
	}
}


int main()
{
	int n = 0;
	cin >> n;
	MergeSortArray numbers(n);
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		numbers.Insert(num);
	}
	int start = 0;
	int end = n-1;
	numbers.Sort(start, end);
	numbers.Show();
}