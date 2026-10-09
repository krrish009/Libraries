# C Sorting and Searching Utility Library

A robust, modular C library implementing classic sorting and searching algorithms from scratch, featuring dynamic user-defined array inputs, automated algorithm routing, and real-time performance benchmarking.

---

## 🚀 What This Project Does

This project provides an interactive command-line utility in C that allows users to input custom arrays and perform advanced operations:
- **Dynamic User Input:** Prompt the user to specify array sizes and enter custom integer elements at runtime.
- **Sorting Algorithms:** Sort data using a comprehensive suite of classic algorithms:
  1. Bubble Sort
  2. Insertion Sort
  3. Selection Sort
  4. Quick Sort
  5. Merge Sort
  6. Heap Sort
  7. **Smart Sort (Auto-Analyzer):** An intelligent wrapper that automatically profiles dataset size ($N$) and available system memory to choose the optimal sorting algorithm dynamically.
- **Searching Algorithms:** Find specific elements within the array using:
  - **Linear Search** (works on any array configuration)
  - **Binary Search** (optimized search with automatic sorting pre-requisite)
- **Performance Benchmarking:** Measures and displays execution time (via `<time.h>`), time complexity, and space complexity for every operation.

---

## 🧠 Smart Sort Decision Rules

The **Smart Sort** utility (Option 6) evaluates dataset characteristics before selecting a strategy:
- **Small Datasets ($N \le 20$):** Routes to **Insertion Sort** ($O(n)$ best-case, $O(1)$ space) due to extremely low overhead.
- **Medium Datasets ($20 < N \le 50$):** Routes to **Quick Sort** ($O(n \log n)$ average, $O(\log n)$ space) for efficient in-place sorting.
- **Large Datasets ($N > 50$):** Checks available system RAM using OS-level system calls (`sysinfo` / `sysctl`):
  - *Sufficient Memory:* Routes to **Merge Sort** ($O(n \log n)$ strict, $O(n)$ space) to guarantee stability.
  - *Memory-Constrained:* Falls back to **Quick Sort** ($O(n \log n)$ average, $O(\log n)$ space) to preserve buffer memory.

---

## 📂 Project Directory Structure

Following professional software engineering best practices, the project is organized into modular headers and source files[cite: 1, 2]:

```text
LIBRARIES/
├── .vscode/
├── include/
│   ├── searching/
│   │   └── searching.h
│   └── sorting/
│       └── sorting.h
├── src/
│   ├── searching/
│   │   ├── binary_search.c
│   │   └── linear_search.c
│   └── sorting/
│       ├── bubble_Sort.c
│       ├── insertion_sort.c
│       ├── merge_Sort.c
│       ├── quick_sort.c
│       ├── heap_sort.c
│       └── smart_sort.c
│   └── main.c
├── .gitignore
├── LICENSE
├── Makefile
├── program
└── README.md