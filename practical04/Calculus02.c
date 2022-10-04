#include <stdio.h>
#include <math.h>

#define N 12
double ARR[N+1]; /*store f(x) in array*/
double* P = ARR;

/*calculate the area under the curve of f(x) from a to b using the Trapezodial Rule*/
double calculus(double (*f)(double), double a, double b) {
    double step = (b-a) / N;
    double sum = 0.0;
    
    if (step<0) {
        printf("Error! b<a! \n");
        return sum;
    }
    
    double x;
    for (x=a; x<=b; x += step) {
        *P = f(x); /*store f(x) in array*/
        sum += *P;
        P++;
    }
    P -= N+1; /*back to ARR[0]*/
    // printf("%lf \n", *P);
    
    sum = (2*sum - f(a) - f(b)) * (b-a) / (2*N);
    return sum;
}

/*convert degree to radian*/
double convert_to_radian(double x) {
    return x*M_PI/180.0;
}

/*print the array*/
void print_array() {
    
    int i=0;
    printf("Print the array: \n");
    for(;i<N+1;i++) printf("ARR[%d]=%lf \n", i, *(P+i));
    
}

int main(void) {
    
    double a = 0.0, b = 60.0;
    double sum = calculus(tan, convert_to_radian(a), convert_to_radian(b));
    printf("The calculus result of tan(x) is %lf. \n", sum);
    print_array();
    
    return 0;

}
