#include <stdio.h>
#include <math.h>

double PI=3.1415926;
int N = 12;

double calculus(double (*f)(double), double a, double b) {
    double step = (b-a) / N;
    double sum = 0.0;
    
    if (step<0) {
        printf("Error! b<a! \n");
        return sum;
    }
    
    double x;
    for (x=a; x<=b; x += step) {
        sum += f(x);
    }
    sum = (2*sum - f(a) - f(b)) * (b-a) / (2*N);
    return sum;
}

int main(void) {
    
    double a = 0.0, b = PI/3;
    double sum = calculus(tan, a, b);
    printf("The calculus result of tan(x) is %lf. \n", sum);
    printf("log(2)=%lf. \n", log(2));
    
    return 0;

}
