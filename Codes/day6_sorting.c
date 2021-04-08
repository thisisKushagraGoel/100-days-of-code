#include <stdio.h>
#include <stdlib.h>
#define MAX 50

//function prototypes
void selection_sort(int[], int);
void bubble_sort(int[], int);
void insertion_sort(int[], int);
void swap(int*, int*);

//main
void main()
{
    int size, i, ch;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements in the array: ");
    for(i=0;i<size;i++)
        scanf("%d", &arr[i]);
    
    //menu
    printf("\nPress 1 for bubble sort");
    printf("\nPress 2 for selection sort");
    printf("\nPress 3 for insertion sort");
    printf("\nPress 0 to exit");
    printf("\nPlease enter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 0: goto NOSORT; break;
        case 1: bubble_sort(arr, size); break;
        case 2: selection_sort(arr, size); break;
        case 3: insertion_sort(arr, size); break;
        default: printf("Exiting without sorting the array !!"); break;
    }
    if(ch==0) {
        NOSORT: {
            printf("Array not sorted !!");
        }
    }
    else {
        printf("\nThe sorted array: \n");
        for(i=0; i<size; i++)
            printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size) {
    int i, j;
    for(i=0; i<size-1; i++) {
        for(j=0; j<size-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }        
    }
}

void selection_sort(int arr[], int size) {
    int i, j, idx;
    for(i=0; i<size-1; i++) {
        idx = i;
        for(j=i+1; j<size; j++) {
            if(arr[j] < arr[idx])
                idx = j;
        }
        swap(&arr[idx], &arr[i]);
    }
}

void insertion_sort(int arr[], int size) {
    int i, j, k;
    for(i=1; i<size; i++) {
        k = arr[i];
        j = i - 1;
        while (j>=0 && arr[j]>k) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = k;
    }
}
