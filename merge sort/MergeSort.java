import java.util.Scanner;

class MergeSort {
	static void Merge(int[] arr, int start, int middle, int end) {
		int front = middle - start + 1;
		int rear = end - middle;
		int[] left = new int[front];
        int[] right = new int[rear];

		for (int i = start; i <= end; i++) {
			if (i <= middle) {
              left[i - start] = arr[i];
            } else {
              right[i - middle - 1] = arr[i];
            }
		}

		for (int i = start, l = 0, r = 0; i <= end; i++) {
			if ((l < front) && (r < rear)) {
				arr[i] = left[l] < right[r] ? left[l++] : right[r++];
			} else {
				arr[i] = l < front ? left[l++] : right[r++];
			}
		}
	}

	static void Show(int[] arr, int size) {
		for (int i = 0; i < size; i++) {
			System.out.print(i == size-1 ? arr[i] : arr[i] + " ");
		}
	}

	static void Sort(int[] arr, int start, int end) {
		if (start < end) {
			int middle = (start + end) / 2;
			Sort(arr, start, middle);
			Sort(arr, middle+1, end);
			Merge(arr, start, middle, end);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int[] numbers = new int[n];

		for (int i = 0; i < n; i++) {
			numbers[i] = input.nextInt();
		}

		Sort(numbers, 0, n-1);
		Show(numbers, n);
	}
}