#include "quick_sort.hpp"

int main()
{
	srand(time(NULL));
	int n = 16;
	QuickSortArray numbers(n);

	for (int i = 0; i < n; i++) {
		numbers.Insert(rand() % 199);
	}

	numbers.QuickSort();
	numbers.Show();
	numbers.CheckCorrect();
}