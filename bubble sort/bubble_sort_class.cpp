#include <iostream>
using namespace std;

class BubbleArray
{
	public:
		BubbleArray();
		BubbleArray(int n);
		~BubbleArray();

		void Append(int n);
		void Print();
		void Sort();
		void Swap(int &a, int &b);

	private:
		int *array_;
		int capacity_;
		int size_;
};

BubbleArray::BubbleArray():
	BubbleArray(0)
{}

BubbleArray::BubbleArray(int n): size_(0), capacity_(n*2)
{
	array_ = new int[capacity_];
}

BubbleArray::~BubbleArray()
{
	delete [] array_;
}

void BubbleArray::Append(int num) {
	if (size_ < capacity_) {
		array_[size_] = num;
		size_++;
	} else {
		capacity_ *= 2;
		int *arr = new int[capacity_];
		for (int i = 0; i < sizeof(array_)/sizeof(int); i++) {
			arr[i] = array_[i];
		}
		arr[size_] = num;
		size_++;
		delete [] array_;
		array_ = arr;
	}
}

void BubbleArray::Print() {
	for (int i = 0; i < size_; i++) {
		cout << (i == size_ - 1 ? to_string(array_[i]) : to_string(array_[i]) + " ");
	}
}

void BubbleArray::Sort() {
	for (int unsort = size_ - 1; unsort > 0; unsort--) {
		for (int i = 0; i < unsort; i++) {
			if (array_[i] > array_[i+1]) {
				Swap(array_[i], array_[i+1]);
			}
		}
	}
}

void BubbleArray::Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n = 0;
	cin >> n;
	BubbleArray *bubble = new BubbleArray(n);

	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		bubble->Append(num);
	}

	bubble->Sort();
	bubble->Print();
	delete bubble;
}