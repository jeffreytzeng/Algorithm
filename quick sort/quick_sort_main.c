#include "quick_sort.c"

int main()
{
	srand(time(NULL));
	int n = 16;
	int numbers[n];

	for (int i = 0; i < n; i++) {
		numbers[i] = rand() % 199;
	}

	Sort(numbers, 0, n-1);
	Show(numbers, &n);
	CheckCorrect(numbers, &n);	// Check is array in ascending order
	return 0;
}
