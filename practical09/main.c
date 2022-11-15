#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "magic_square.h"

/*get the number of rows*/
int get_nrows(FILE* fp) {
    int c, nrows = 0;
    while ((c = fgetc(fp)) != EOF) if (c == '\n') nrows++;
    nrows++;
    rewind(fp);
    return nrows;
}

/*get the number of columns*/
int get_ncols(FILE* fp) {
    int c, ncols = 0;
    while ((c = fgetc(fp)) != '\n') if (c == ' ') ncols++;
    ncols++;
    rewind(fp);
    return ncols;
}

/*scan the data for the matrix*/
int get_matrix (FILE *fp, int** a, int nrows, int ncols) {
    int i, j;
    for (i = 0; i < nrows; i++) {
        for (j = 0; j < ncols; j++) {
            if (fscanf (fp, "%d", &a[i][j]) != 1) {
                printf ("error reading a[%d][%d]\n", i, j);
                return 0;
            }
        }
    }
  return 1;
}

void print_matrix(int** a, int n, int m) {
    int i,j;
    printf("Print the matrix: \n");
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) printf("%d\t", a[i][j]);
        printf("\n");
    }
}

int main() {
    
    FILE* fp = fopen("m.txt", "r");
    if (fp==NULL) {
        printf("Failed to open the file. \n");
        exit(1);
    }
    
    int nrows = get_nrows(fp);
    int ncols = get_ncols(fp);
    if (nrows != ncols) {
        printf("This is not a square matrix! \n");
        //printf("nrows = %d \n", nrows);
        //printf("ncols = %d \n", ncols);
        return -1;
    }
    const int n = nrows;
    
    /*read the data from file and create a matrix*/
    int i;
    int** a;
    a = (int **)malloc(n * sizeof(int *));
    for (i=0;i<n;i++) a[i] = (int *)malloc(n * sizeof(int));
    get_matrix(fp, a, nrows, ncols);
    print_matrix(a, nrows, ncols);
    
    /*check if the matrix is magic square and calculate the time used*/
    clock_t start, end;
    start = clock();
    int result = isMagicSquare(a, n);
    end = clock();
    printf("time cost of isMagicSquare(a, n): %d ms \n", (int)(end-start));
    /*The time complexity of isMagicSquare(a, n) should apply to O(n^2),
     theta(n^2+n)*/
    
    if (result) printf("This is a magic square. \n");
    else printf("This is not a magic square. \n");
    
    for (i=0;i<n;i++) free(a[i]);
    free(a);
    fclose(fp);
    return 0;
}
