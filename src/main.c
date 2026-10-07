#include <stdio.h>
#include "sorting.h"
#include "searching.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int main_choice, algo_choice, n, target, result;

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

    printf("\n--- Select Main Operation ---\n");
    printf("1. Sort the Array\n");
    printf("2. Search for an Element\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &main_choice);

    if (main_choice == 1) {
        printf("\nChoose a sorting algorithm:\n");
        printf("1. Bubble Sort\n2. Merge Sort\n3. Insertion Sort\n4. Quick Sort\n5. Heap Sort\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &algo_choice);

        switch(algo_choice) {
            case 1: bubble_sort(arr, n); printf("Sorted using Bubble Sort:\n"); break;
            case 2: merge_sort(arr, 0, n - 1); printf("Sorted using Merge Sort:\n"); break;
            case 3: insertion_sort(arr, n); printf("Sorted using Insertion Sort:\n"); break;
            case 4: quick_sort(arr, 0, n - 1); printf("Sorted using Quick Sort:\n"); break;
            case 5: heap_sort(arr, n); printf("Sorted using Heap Sort:\n"); break;
            default: printf("Invalid sorting choice!\n"); return 1;
        }
        print_array(arr, n);

    } else if (main_choice == 2) {
        printf("\nEnter the number to search for: ");
        scanf("%d", &target);

        printf("\nChoose a searching algorithm:\n");
        printf("1. Linear Search (Unsorted/Any configuration)\n");
        printf("2. Binary Search (Forces auto-sort first)\n");
        printf("Enter choice (1-2): ");
        scanf("%d", &algo_choice);

        if (algo_choice == 1) {
            result = linear_search(arr, n, target);
        } else if (algo_choice == 2) {
            printf("\n[Notice] Auto-sorting array using Quick Sort for Binary Search requirements...\n");
            quick_sort(arr, 0, n - 1);
            printf("Sorted array looks like: ");
            print_array(arr, n);
            result = binary_search(arr, n, target);
        } else {
            printf("Invalid searching choice!\n");
            return 1;
        }

        if (result != -1) {
            printf("\nSuccess! Element %d found at index position: %d\n", target, result);
        } else {
            printf("\nElement %d was not found in the array.\n", target);
        }
    } else {
        printf("Invalid main choice!\n");
        return 1;
    }

    return 0;
}
