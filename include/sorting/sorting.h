#ifndef SORTING_H
#define SORTING_H

void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n); // if you have it
void merge_sort(int arr[], int left, int right);
void quick_sort(int arr[], int low, int high);
void heap_sort(int arr[], int n);

// Newly added Smart Sort wrapper
void smart_sort(int arr[], int n);

#endif