import java.util.Random;

class QuickSort {
	private static int[] array_;
	private static int size_;

	static void CheckCorrect() {
		boolean correct = true;

		for (int i = 0; i < size_-1; i++) {
			if (array_[i] > array_[i+1]) {
				correct = false;
			}
		}
		System.out.println(correct ? "True" : "False");
	}

	static int OrderedWithIn3(int start, int end) {
		int length = end - start + 1;
		int middle = end;

		switch (length) {
			case 1:
				break;
			case 2:
				if (array_[start] > array_[end]) {
					Swap(start, end);
				}
				break;
			case 3:
				middle = (start + end) / 2;

				if (array_[start] > array_[end]) {
					Swap(start, end);
				}
				if (array_[middle] > array_[end]) {
					Swap(middle, end);
				}
				if (array_[start] > array_[middle]) {
					Swap(start, middle);
				}
		}
		return middle;
	}

	static int Partition(int start, int end, int pivot) {
		int left = start - 1;
		int right = end;

		while (true) {
			while (left < end && array_[++left] < array_[pivot]) {
			}
			while (right > start && array_[--right] > array_[pivot]) {
			}

			if (left >= right) {
				break;
			} else {
				Swap(left, right);
			}
		}
		Swap(left, pivot);
		return left;
	}

	static void Show() {
		for (int i = 0; i < array_.length; i++) {
			System.out.print(i == array_.length-1 ? array_[i] : array_[i] + " ");
		}
		System.out.println();
	}

	static void Sort(int start, int end) {
		int median = OrderedWithIn3(start, end);

		if (end - start >= 0) {
			int partition = Partition(start, end, median);
			Sort(start, partition-1);
			Sort(partition+1, end);
		}
	}

	static void Swap(int left, int right) {
		int temp = array_[left];
		array_[left] = array_[right];
		array_[right] = temp;
	}

	public static void main(String[] args) {
		Random rand = new Random();
		size_ = 16;
		array_ = new int[size_];

		for (int i = 0; i < array_.length; i++) {
			array_[i] = rand.nextInt(199);
		}

		Sort(0, size_-1);
		Show();
		CheckCorrect();
	}
}
		