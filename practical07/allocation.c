#include <stdio.h>
#include <stdlib.h>

/*allocate and return the one-dimension array*/
int* allocate_array(int n) {
    int* arr = (int *)malloc(n*sizeof(int *));
    return arr;
}

/*fill the elements in the one-dimension array with one*/
void fill_with_one(int* arr, int n) {
    int i;
    for (i=0;i<n;i++) *(arr+i) = 1;
}

/*print the one-dimension array*/
void print_array(int* arr, int n) {
    int i;
    for (i=0;i<n;i++) printf("arr[%d]=%d \n", i, *(arr+i));
}

/*free the allocated memory*/
void free_array(int* arr) {
    free(arr);
}

int main() {
    int s[3] = {3, 5, 10}; /*store the sizes of 3 different arrays*/
    int i, size;
    
    /*run with different size of arrays*/
    for (i=0;i<3;i++) {
        size = s[i];
        printf("Array with size %d: \n", size);
        int* arr = allocate_array(size);
        fill_with_one(arr, size);
        print_array(arr, size);
        free_array(arr);
    }
    
    return 0;
}
