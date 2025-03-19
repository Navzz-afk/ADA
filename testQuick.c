#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;


    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }


    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    clock_t start, end;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);


    int arr[n];

    srand(time(NULL));


    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;
    }


    printf("Original Array: ");
    print(arr, n);


    start = clock();


    quickSort(arr, 0, n - 1);

    end = clock();


    printf("Sorted Array: ");
    print(arr, n);


    printf("Time taken: %f seconds\n",1000* (double)(end - start) / CLOCKS_PER_SEC);




    return 0;
}

