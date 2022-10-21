#include <stdio.h>
#include <stdlib.h>

/*define multiply method of matrix*/
double** multiply (double* a, double* b, int n, int p, int q) {
    int i, j, k;
    double** c;
    c = (double **)malloc(n * sizeof(double *));
    for (i=0;i<n;i++) c[i] = (double *)malloc(q * sizeof(double));
    
    
    for (i=0;i<n;i++) {
        for(j=0;j<q;j++) {
            c[i][j] = 0.0;
            for(k=0;k<p;k++) c[i][j] += (*(a+i*p+k)) * (*(b+k*q+j));
        }
    }
         
    return c;
        
}

void print_matrix(double* a, int n, int m) {
    int i,j;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) printf("%lf\t", *(a+i*m+j));
        printf("\n");
    }
}
