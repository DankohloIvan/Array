#include <iostream>

class Array {
private:
	int size;
	int* array = nullptr;
public:
	Array(int size) {
		this->size = size;
		array = new int[size];
		for (int i = 0; i < size; ++i) {
			array[i] = 0;
		}
	}
	Array(const Array& other) {
		size = other.size;
		if (size > 0) {
			array = new int[size];
			for (int i = 0; i < size; ++i)
				array[i] = other.array[i];
		}
		else {
			array = nullptr;
		}
	}
	~Array() {
		delete[] array;
	}
	void print() {
		for (int i = 0; i < size; ++i) {
			std::cout << array[i] << ' ';
		}
		std::cout << '\n';
	}
	void placeValue(int index, int value) {
		array[index] = value;
	}
	void setSize(int value) {
		if (value != size) {
			int* newArray;
			if (value > 0) {
				newArray = new int[value];
			}
			else {
				newArray = nullptr;
			}
			int minSize;
			if (value < size) {
				minSize = value;
			}
			else {
				minSize = size;
			}
			for (int i = 0; i < minSize; ++i) {
				newArray[i] = array[i];
			}
			for (int i = minSize; i < value; ++i) {
				newArray[i] = 0;
			}

			delete[] array;
			array = newArray;
			size = value;
		}
	}
	void swap(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	void sort() {
		for (int i = 0; i < size - 1; ++i) {
			bool swapped = false;
			for (int j = 0; j < size - 1 - i; ++j) {
				if (array[j] > array[j + 1]) {
					swap(array[j], array[j + 1]);
					swapped = true;
				}
			}
			if (!swapped) {
				break;
			}
		}
	}
	int getMax() {
		int maxVal = array[0];
		for (int i = 1; i < size; ++i) {
			if (array[i] > maxVal) {
				maxVal = array[i];
			}
		}
		return maxVal;
	}

	int getMin() {
		int minVal = array[0];
		for (int i = 1; i < size; ++i) {
			if (array[i] < minVal) {
				minVal = array[i];
			}
		}
		return minVal;
	}
};

int main() {
	Array array(10);
	for (int i = 0; i < 10; ++i) {
		array.placeValue(i, i + 1);
	}
	array.setSize(11);
	array.placeValue(10, 1);
	array.sort();
	array.print();

	std::cout << array.getMin() << '\n';
	std::cout << array.getMax() << '\n';
	return 0;
}