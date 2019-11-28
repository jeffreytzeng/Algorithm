import java.util.Scanner;

class InsertionSort {
	static void Sort(int[] array) {
		for (int i = 1; i < array.length; i++) {
			int key = array[i];
			int j = i - 1;

			while (j >= 0 && array[j] >= key) {
				array[j+1] = array[j];
				j--;
			}
			array[j+1] = key;
		}
	}

	public static void main(String[] argv) {
		Scanner input = new Scanner(System.in);
        int size = input.nextInt();
        input.skip("\n");
		String[] str = input.nextLine().split(" ");
		int[] numbers = new int[str.length];

		for (int i = 0; i < str.length; i++) {
			numbers[i] = Integer.parseInt(str[i]);
		}

		Sort(numbers);

		for (int i = 0; i < numbers.length; i++) {
			System.out.print(i != numbers.length-1 ? numbers[i] + " " : numbers[i]);
		}
	}
}