#include <stdio.h>
#include "mm.h"

int main() {
    int n=5,p=3,q=4;
    int i,j;
    double a[5][3], b[3][4];
    
    for (i=0;i<n;i++) for(j=0;j<p;j++) a[i][j] = i+j;
    for (i=0;i<p;i++) for(j=0;j<q;j++) b[i][j] = i-j;
    double** c = multiply(&a[0][0], &b[0][0], n, p, q);
    printf("matrix c: \n");
    print_matrix(&c[0][0], n, q);
    printf("matrix a: \n");
    print_matrix(&a[0][0], n, p);
    printf("matrix b: \n");
    print_matrix(&b[0][0], p, q);
    
    return 0;
}
