import java.util.Scanner;

class BubbleSort {
	static void Sort(int[] arr) {
		for (int unsort = arr.length-1; unsort > 0; unsort--) {
			for (int i = 0; i < unsort; i++) {
				if (arr[i] > arr[i+1]) {
					int temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
				}
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