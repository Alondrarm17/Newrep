/* Programmer: Alondra Rodriguez Manzueta
COP3502C: Lab assignment 7
Due date: March 7th 2024*/

#include <stdio.h>

// Function to swap two integer values
void swap(int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on an array
void bubbleSort(int *array, int n) {
    int i, j, temp;
    int swaps[100] = {0}; // Array to store frequency of swaps for each element
    int count = 0; // Variable to store total number of swaps

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j],&array[j+1]);
                swaps[array[j+1]]++;
                swaps[array[j]]++;
                count++;
            }
        }
    }

    // Printing sorted array and frequency of swaps for each element
    for (int k = 0; k < n ; k++) {
        printf("%d: is swapped %d times\n", array[k], swaps[array[k]]);
    }
    printf("The total number of swaps is: %d\n", count);
}

// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    int freq[100] = {0}; // Array to store frequency of swaps for each element
    int count = 0; // Variable to store total number of swaps

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;

            freq[arr[i]]++;
            freq[arr[min_idx]]++;
            count++;
        }
    }

    // Printing sorted array and frequency of swaps for each element
    for (int k = 0; k < n ; k++) {
        printf("%d: is swapped %d times\n", arr[k], freq[arr[k]]);
    }
    printf("The total number of swaps is: %d\n", count);
}

int main() {
    int number = 9; // Size of the arrays
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Bubble sort on array1
    printf("array1 bubble sort:\n");
    bubbleSort(array1, number);

    // Bubble sort on array2
    printf("\narray2 bubble sort:\n");
    bubbleSort(array2, number);

    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Selection sort on array3
    printf("\narray3 selection sort:\n");
    selectionSort(array3, number);

    // Selection sort on array4
    printf("\narray4 selection sort:\n");
    selectionSort(array4, number);

    return 0;
}
