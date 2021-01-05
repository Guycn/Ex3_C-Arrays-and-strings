#include <stdio.h>
#include "isort.h"
#define SIZE 50



int main() {
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &arr[i]);
	}
	insertion_sort(arr, SIZE);
	for (int j = 0; j < SIZE; j++) {
		if (j == 0)printf("%d", arr[j]);
		else printf(",%d", arr[j]);
	}

	
}