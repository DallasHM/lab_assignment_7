#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int num;
    int moves;
} Number;

void swap(Number *a, Number *b) {
    Number temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Number arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].num > arr[j + 1].num) {
                swap(&arr[j], &arr[j + 1]);
                arr[j].moves++;
                arr[j + 1].moves++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}


void selectionSort(Number arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].num < arr[min_idx].num) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
            arr[i].moves++;
            arr[min_idx].moves++;
        }
    }
}

void printArray(Number arr[], int n) {
    int total_swaps = 0;
    for (int i = 0; i < n; i++) {
        printf("%d (moved %d times)\n", arr[i].num, arr[i].moves);
        total_swaps += arr[i].moves;
    }
    printf("Total swaps: %d\n\n", total_swaps);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Number array[size];

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &array[i].num);
        array[i].moves = 0;
    }

    printf("\nSorting using Bubble Sort:\n");
    bubbleSort(array, size);
    printArray(array, size);

    printf("Sorting using Selection Sort:\n");
    selectionSort(array, size);
    printArray(array, size);

    return 0;
}
