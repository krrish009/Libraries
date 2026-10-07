#include <stdio.h>
#include "../include/sorting.h"

// Helper function to print arrays
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("--- Testing Sorting Algorithms ---\n\n");

    // 1. Test Bubble Sort
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array for Bubble Sort:\n");
    print_array(arr1, n1);
    
    bubble_sort(arr1, n1);
    
    printf("Sorted array using Bubble Sort:\n");
    print_array(arr1, n1);
    printf("\n");

}
