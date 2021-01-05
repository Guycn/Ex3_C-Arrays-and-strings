#include <stdio.h>



shift_element(int* arr, int i) {
	for (int j = i-1; j >= 0; j--) {
		*(arr + j+1) = *(arr + j);
	}
}

insertion_sort(int* arr, int len) {
	int counter = 0, temp = 0;
	for (int i = 1; i < len; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (*(arr + i) < *(arr + j)) {
				counter++;
			}
			if (j == 0 || *(arr + i) > *(arr + j)) {
				if (counter > 0) {
					temp = *(arr + i);
					shift_element(arr + i-counter, counter);
					*(arr + i - counter) = temp;
					temp = 0;
					counter = 0;
				}
				else j = 0;
			}

		}
	}
}