#include <stdio.h>
#include <stdlib.h>

/*return the factorial restlt of n*/
int factorial(int n) {
    if (n<0) {
        printf("Error! n<0! \n");
        return -1;
    }
    
    if (n==0) {return 1;}
    
    int result=1, i=1;
    for (;i<=n;i++) result *= i;
    return result;
}

/*return the estimate of e according to the order n*/
double estimate(int n) {
    double sum=0.0;
    int i;
    
    for (i=0;i<=n;i++) sum += (double)1.0000/factorial(i);
    
    return sum;
}

/*allocate the one-dimension array storing the value of polynomials with different orders*/
double* allocate_array(int n) {
    double* arr = (double *)malloc(n*sizeof(double *));
    return arr;
}

/*print the one-dimension array*/
void print_array(double* arr, int n) {
    int i;
    for (i=0;i<n;i++) printf("f(%d)=%lf \n", i+1, *(arr+i));
}

int main() {
    int i,n;
    printf("Please input the order of the polynomial: ");
    scanf("%d", &n);
    
    double* arr = allocate_array(n);
    for (i=0;i<n;i++) *(arr+i) = estimate(i);
    print_array(arr, n);
    free(arr);
    
    return 0;
}
