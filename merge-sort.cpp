/* C++ program for Merge Sort Algorithm */

#include <stdio.h> 
#include <stdlib.h> 
  
// Merges two subarrays of arr[]: arr[start-n] and arr[n+1,end]
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
    {
       L[i] = arr[l + i]; 
    }
    
    for (j = 0; j < n2; j++) 
    {
        R[j] = arr[m + 1 + j]; 
    }    
  
    i = 0;  
    j = 0; 
    k = l;
    
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of L[], if any
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[], if any
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
// l:left index r: right index 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        
        int n = l + (r - l) / 2; 
  
        // sorts two halves
        mergeSort(arr, l, n); 
        mergeSort(arr, n + 1, r); 
  
        // merge resulting seprate arrays (logical)
        merge(arr, l, n, r); 
    } 
} 
  

// Utility function to print an array
void printArray(int a[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
    {
        printf("%d ", a[i]); 
    }
    printf("\n"); 
} 
  
// Driver program
int main() 
{ 
    int arr[] = { 31, 2, 11, 7, 1, 18, 23, 9, 11}; 
    int arrSize = sizeof(arr) / sizeof(arr[0]); 
  
    printf("\n Input array:\n"); 
    printArray(arr, arrSize); 
  
    mergeSort(arr, 0, arrSize - 1); 
  
    printf("\n Sorted array: \n"); 
    printArray(arr, arrSize); 
    return 0; 
} 
