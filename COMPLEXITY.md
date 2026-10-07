# Algorithm Complexity Analysis

This document outlines the Time and Space complexities for all the sorting and searching algorithms implemented in this library.

## 📊 Summary Table

| Algorithm | Best Time | Average Time | Worst Time | Space Complexity | Stable? |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Yes |
| **Quick Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | No |
| **Heap Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(1)$ | No |
| **Linear Search** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ | N/A |
| **Binary Search** | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ | N/A |

---

## 🔍 Detailed Explanations

### 1. Sorting Algorithms

*   **Bubble Sort:** 
    *   *Best case* happens when the array is already sorted ($O(n)$ with a modified flag).
    *   *Worst case* happens when the array is reversely sorted ($O(n^2)$).
*   **Insertion Sort:** 
    *   Highly efficient for small or almost-sorted datasets ($O(n)$ best case).
*   **Merge Sort:** 
    *   Guarantees $O(n \log n)$ performance across all cases, but requires $O(n)$ extra memory to hold temporary subarrays during the merge phase.
*   **Quick Sort:** 
    *   Extremely fast in practice (average $O(n \log n)$). However, if the pivot choice is poor (e.g., picking the smallest/largest element in a sorted array), performance drops to $O(n^2)$.
*   **Heap Sort:** 
    *   Combines the $O(1)$ space efficiency of Bubble/Insertion sort with the guaranteed $O(n \log n)$ time efficiency of Merge Sort.

### 2. Searching Algorithms

*   **Linear Search:** 
    *   Checks elements one by one. It requires no sorting but takes $O(n)$ time in the worst case.
*   **Binary Search:** 
    *   Cuts the search space in half with every single step ($O(\log n)$). It is incredibly fast but strictly requires the array to be sorted beforehand.
