# C Sorting and Searching Utility Library

A robust, modular C library implementing classic sorting and searching algorithms from scratch, featuring dynamic user-defined array inputs and clean software engineering practices.

##  What This Project Does
This project provides an interactive command-line utility in C that allows users to input their own custom arrays and perform various operations:
* **Dynamic User Input:** Prompt the user to specify the array size and enter custom integer elements at runtime.
* **Sorting Algorithms:** Sort the user-defined array using classic algorithms:
  1. Bubble Sort
  2. Insertion Sort
  3. Selection Sort
  4. Quick Sort
  5. Merge Sort
  6. Heap Sort
* **Searching Algorithms:** Find specific elements within the array using:
  * **Linear Search** (works on any array configuration)
  * **Binary Search** (optimized search requiring a pre-sorted array)

The repository is structured with separated headers (`include/`) and implementation files (`src/`), accompanied by an automated `Makefile` for streamlined compilation.

---

## 📂 Project Directory Structure
Following professional software engineering best practices, the project is organized to match your exact directory layout[cite: 1, 2]:

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
│       └── ... (other sorting source files)
│   └── main.c
├── .gitignore
├── LICENSE
├── Makefile
├── program
└── README.md