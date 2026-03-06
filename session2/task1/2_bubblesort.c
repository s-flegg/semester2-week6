#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int array[], int n);

int main(void) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bubbleSort(arr, n);

  printf("After sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

/**
 * @brief Sorts an array of integers in ascending order using the bubble sort algorithm.
 * 
 * @param arr The array of integers to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int array[], int n) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (int i=0; i<n-1; i++) {
      if (array[i+1] < array[i]) {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        sorted = false;
      }
    }
  }
}