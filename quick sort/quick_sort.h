#ifndef QUICK_SORT
#define QUICK_SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CheckCorrect(int *arr, int *size);
int OrderedWithIn3(int *arr, int *start, int *end);
int Partition(int *arr, int *start, int *end, int *pivot);
void Show(int *arr, int *size);
void Sort(int *arr, int start, int end);
void Swap(int *arr, int *left, int *right);

#endif