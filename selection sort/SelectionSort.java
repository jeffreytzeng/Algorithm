import java.util.Scanner;

class SelectionSort {
	static void Sort(int[] arr) {
		for (int i = 0; i < arr.length-1; i++) {
			int min = i;

			for (int j = i+1; j < arr.length; j++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			}

			if (min != i) {
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int[] numbers = new int[n];

		for (int i = 0; i < n; i++) {
			numbers[i] = input.nextInt();
		}

		Sort(numbers);

		for (int i = 0; i < n; i++) {
			System.out.print(i == n-1 ? numbers[i] : numbers[i] + " ");
		}
	}
}