#include <stdio.h>
#include "sorting.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array entered:\n");
    print_array(arr, n);

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice (1-4): ");
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
        case 3:
            insertion_sort(arr, n);
            printf("Sorted array using Insertion Sort:\n");
            break;
        case 4:
            quick_sort(arr, 0, n - 1);
            printf("Sorted array using Quick Sort:\n");
            break;
        default:
            printf("Invalid choice! Please select 1, 2, 3, or 4.\n");
            return 1;
    }

    print_array(arr, n);
    return 0;
}
