#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

#if defined(__linux__)
#include <sys/sysinfo.h>
#elif defined(__APPLE__) || defined(__MACH__)
#include <sys/types.h>
#include <sys/sysctl.h>
#endif

// Helper function to check available system memory
int has_enough_memory() {
    long long free_memory = -1;

#if defined(__linux__)
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        free_memory = (long long)info.freeram * info.mem_unit;
    }
#elif defined(__APPLE__) || defined(__MACH__)
    int64_t memsize = 0;
    size_t len = sizeof(memsize);
    if (sysctlbyname("hw.memsize", &memsize, &len, NULL, 0) == 0) {
        free_memory = memsize / 2; 
    }
#else
    free_memory = 1024LL * 1024LL * 1024LL; // 1 GB fallback assumption
#endif

    long long threshold = 50LL * 1024LL * 1024LL; // 50 MB threshold
    
    if (free_memory != -1) {
        printf("[Memory Check] Available System Memory: %.2f MB\n", (double)free_memory / (1024 * 1024));
    }
    
    return (free_memory == -1 || free_memory >= threshold);
}

void smart_sort(int arr[], int n) {
    printf("\n--- Smart Sort Analyzer ---\n");
    printf("[Dataset Info] Array Size (N) = %d elements\n", n);
    
    if (n <= 1) {
        printf("Algorithm Chosen: None (Already sorted or empty)\n");
        printf("Rationale: Array size is %d, requiring no sorting operations.\n", n);
        printf("Time Complexity: O(1)\n");
        printf("Space Complexity: O(1)\n");
        printf("---------------------------\n");
        return;
    }

    // 1. Small dataset check -> Insertion Sort
    if (n <= 20) {
        printf("Algorithm Chosen: Insertion Sort\n");
        printf("Rationale: Dataset size (N = %d) is small (<= 20). Insertion Sort dominates due to very low overhead and O(n) adaptation.\n", n);
        printf("Time Complexity: O(n) best-case, O(n^2) worst-case\n");
        printf("Space Complexity: O(1)\n");
        insertion_sort(arr, n);
        printf("---------------------------\n");
        return;
    }

    // 2. Medium dataset check (20 < N <= 50) -> Quick Sort default
    if (n <= 50) {
        printf("Algorithm Chosen: Quick Sort\n");
        printf("Rationale: Medium dataset size (20 < N <= 50). Quick Sort provides great in-place performance with minimal stack overhead.\n");
        printf("Time Complexity: O(n log n) average-case, O(n^2) worst-case\n");
        printf("Space Complexity: O(log n)\n");
        quick_sort(arr, 0, n - 1);
        printf("---------------------------\n");
        return;
    }

    
    printf("---------------------------\n");
}