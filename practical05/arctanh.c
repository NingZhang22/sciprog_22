#include <stdio.h>
#include <math.h>

double arctanh1(double x, double delta) {
    double sum=0.0;
    
    if (fabs(x) >= 1.0) {
        printf("Error! The abs of x is larger than 1! \n");
        return sum;
    }
    
    if (delta <= 0.0) {
        printf("Error! delta <= 0! \n");
        return sum;
    }
    
    int n=0;
    int tmp1;
    double tmp2;
    while (1) {
        tmp1 = 2*n + 1;
        tmp2 = (double)pow(x, tmp1) / (double)tmp1;
        if (fabs(tmp2)<delta) break;
        sum += tmp2;
        n++;
    }
    return sum;
    
}

double arctanh2(double x) {
    
    if (fabs(x) >= 1.0) {
        printf("Error! The abs of x is larger than 1! \n");
        return 0.0;
    }
    
    return 0.5 * (log(1+x)-log(1-x));
}

int main() {
    
    double delta;
    double x=-0.9;
    double arr1[191], arr2[191];
    double* p1=arr1;
    double* p2=arr2;
    
    printf("Please enter a real positive number: ");
    scanf("%lf", &delta);
    
    for (;x<=0.9;x+=0.01) {
        *p1 = arctanh1(x, delta);
        *p2 = arctanh2(x);
        if (x<-0.8) printf("arctan1(%lf)=%lf\tarctan2(%lf)=%lf \n", x, *p1, x, *p2);
        p1++;
        p2++;
    }
    
    return 0;
}
