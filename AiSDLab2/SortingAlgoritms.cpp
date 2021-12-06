#include "SortingAlgoritms.h"
#include <stdexcept>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
	return;
}

int binary_search(int* array, int array_size, int necessary_item) {
	//Check is array actually sorted
	for (int i = 0; i < array_size-1; i++) {
		if (array[i] > array[i + 1]) {
			throw std::invalid_argument("Array need to be sorted");
		}
	}
	//Search
	int left_border = -1;
	int right_border = array_size;
	bool found = false;
	while (true) {
		if (left_border >= right_border-1) {
			throw std::domain_error("There is no searhing item in array");
		}
		int middle = (left_border + right_border) / 2;
		if (array[middle] == necessary_item) {
			return middle;
		}
		if (array[middle] > necessary_item) {
			right_border = middle;
		}
		else {
			left_border = middle;
		}
	}
}

void bubble_sort(int* array, int array_size) {
	bool sorted = false;
	while(!sorted) {
		sorted = true;
		int i = 0;
		while (i < array_size-1) {
			//swap
			if (array[i] > array[i + 1]) {
				sorted = false; //if at least one swap has been made, the array will be proceeded again
				swap(array[i], array[i + 1]);
			}
			i++;
		}
	}
	return;
}

void quick_sort(int* array, int array_size) {
	if (array_size <= 1) {
		return;
	} //If array size is 1, it sorted ( no way :) )
	int* pivot = &(array[array_size-1]);
	int* pointer = nullptr;
	int pointer_index = array_size - 1;
	bool flag = true;
	//Splitting the array
	while (flag) {
		int i = 0;
		while (i < array_size) {
			if (array[i] > *pivot) {
				pointer = &array[i];
				pointer_index = i;
				i++;
				break;
			}
			i++;
		}
		if (pointer == nullptr) {
			break;
		}
		while (i < array_size) {
			if (array[i] <= *pivot) {
				if (i == array_size - 1) {
					flag = false;
				}
				swap(array[i], *pointer);
				break;
			}
			i++;
		}
	}
	//Quick sort for each part of array
	quick_sort(array, pointer_index);
	quick_sort(&array[pointer_index + 1], array_size - pointer_index - 1);
}

void bogo_sort(int* array, int array_size) {
	while (true) {
		int isSorted = true;
		for (int i = 0; i < array_size-1; i++) {
			if (array[i] > array[i + 1]) {
				isSorted = false;
				break;
			}
		}
		if (isSorted) {
			return;
		} //If array is sorted - return
		for (int i = 0; i < array_size; i++) {
			swap(array[i], array[rand() % array_size]);
		}//Else - shuffle array
	}
}

void counting_sort(char* array, int array_size) {
	//count
	int counters[256] = { 0 };
	for (int i = 0; i < array_size; i++) {
		counters[array[i]]++;
	}
	//fill
	int index = 0;
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < counters[i]; j++) {
			array[index] = i;
			index++;
		}
	}
}

