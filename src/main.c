#include <stdio.h>
#include <time.h> 
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
    clock_t start_time, end_time;
    double cpu_time_used;

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
        printf("1. Bubble Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Heap Sort\n");
        printf("6. Smart Sort (Auto-Analyzer)\n");
        printf("Enter choice (1-6): ");
        scanf("%d", &algo_choice);

        // Start measuring time
        start_time = clock();

        switch(algo_choice) {
            case 1: 
                bubble_sort(arr, n); 
                end_time = clock();
                printf("\nSorted using Bubble Sort:\n"); 
                printf("Time Complexity: O(n) best-case, O(n^2) worst-case\n");
                printf("Space Complexity: O(1)\n");
                break;
            case 2: 
                merge_sort(arr, 0, n - 1); 
                end_time = clock();
                printf("\nSorted using Merge Sort:\n"); 
                printf("Time Complexity: O(n log n) [Worst, Average, Best]\n");
                printf("Space Complexity: O(n)\n");
                break;
            case 3: 
                insertion_sort(arr, n); 
                end_time = clock();
                printf("\nSorted using Insertion Sort:\n"); 
                printf("Time Complexity: O(n) best-case, O(n^2) worst-case\n");
                printf("Space Complexity: O(1)\n");
                break;
            case 4: 
                quick_sort(arr, 0, n - 1); 
                end_time = clock();
                printf("\nSorted using Quick Sort:\n"); 
                printf("Time Complexity: O(n log n) average-case, O(n^2) worst-case\n");
                printf("Space Complexity: O(log n)\n");
                break;
            case 5: 
                heap_sort(arr, n); 
                end_time = clock();
                printf("\nSorted using Heap Sort:\n"); 
                printf("Time Complexity: O(n log n) [Worst, Average, Best]\n");
                printf("Space Complexity: O(1)\n");
                break;
            case 6: 
                smart_sort(arr, n); // Smart sort handles its own time/space logging inside
                end_time = clock();
                break;
            default: 
                printf("Invalid sorting choice!\n"); 
                return 1;
        }

        // Calculate elapsed time in seconds (or milliseconds)
        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        
        if (algo_choice != 6) {
            printf("Time Taken to Sort: %.6f seconds\n", cpu_time_used);
            print_array(arr, n);
        } else {
            printf("Time Taken to Sort (via Smart Sort): %.6f seconds\n", cpu_time_used);
            printf("Final Sorted Array:\n");
            print_array(arr, n);
        }

    } else if (main_choice == 2) {
        printf("\nEnter the number to search for: ");
        scanf("%d", &target);

        printf("\nChoose a searching algorithm:\n");
        printf("1. Linear Search (Unsorted/Any configuration)\n");
        printf("2. Binary Search (Forces auto-sort first)\n");
        printf("Enter choice (1-2): ");
        scanf("%d", &algo_choice);

        // Start measuring search time
        start_time = clock();

        if (algo_choice == 1) {
            result = linear_search(arr, n, target);
            end_time = clock();
            printf("\nAlgorithm Chosen: Linear Search\n");
            printf("Time Complexity: O(n)\n");
            printf("Space Complexity: O(1)\n");
        } else if (algo_choice == 2) {
            printf("\n[Notice] Auto-sorting array using Quick Sort for Binary Search requirements...\n");
            quick_sort(arr, 0, n - 1);
            printf("Sorted array looks like: ");
            print_array(arr, n);
            
            result = binary_search(arr, n, target);
            end_time = clock();
            printf("\nAlgorithm Chosen: Binary Search (with Quick Sort prep)\n");
            printf("Time Complexity: O(log n) [Search] + O(n log n) [Sort Prep]\n");
            printf("Space Complexity: O(log n)\n");
        } else {
            printf("Invalid searching choice!\n");
            return 1;
        }

        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time Taken to Search: %.6f seconds\n", cpu_time_used);

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