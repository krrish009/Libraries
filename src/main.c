#include <stdio.h>
#include "../include/sorting.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    printf("\nRunning your selected algorithm...\n");

    switch(choice) {
        case 1:
            bubble_sort(arr, n);
            printf("Sorted array using Bubble Sort:\n");
            break;
        case 2:
            merge_sort(arr, 0, n - 1);
            printf("Sorted array using Merge Sort:\n");
            break;
        default:
            printf("Invalid choice! Please select 1 or 2.\n");
            return 1;
    }

    print_array(arr, n);
    return 0;
}
