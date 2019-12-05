#ifndef QUICK_SORT
#define QUICK_SORT

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class QuickSortArray
{
	public:
		QuickSortArray(int size);

		void CheckCorrect();
		void Insert(int number);
		int OrderedWithIn3(int &start, int &end);
		int Partition(int &start, int &end, int &pivot);
		void QuickSort();
		void Show();
		void Sort(int start, int end);
		void Swap(int &left, int &right);

	private:
		int total_;
		std::vector<int> array_;
};

#endif