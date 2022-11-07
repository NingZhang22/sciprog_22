#include <stdio.h>
#include <time.h>

/*calculate Greatest Common Divisor using euclidian algorithm*/
int gcd1(int a, int b) {
    int temp;
    while (b!=0) {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

/*calculate Greatest Common Divisor using recursion*/
int gcd2(int a, int b) {
    if (b==0) return a;
    return gcd2(b, a%b);
}

/*calculate the time cost of running a function*/
void timing(int (*f)(int, int), int a, int b) {
    clock_t begin, end;
    double cost;
    int result;
    
    begin = clock();
    result = f(a, b);
    end = clock();
    
    cost = (double)(end-begin);
    printf("The calculation result is %d. \n", result);
    printf("time cost: %lf ms \n", cost);
}


int main() {
    int a, b;
    
    printf("Please input a: ");
    scanf("%d", &a);
    printf("Please input b: ");
    scanf("%d", &b);
    
    printf("The calculation result of using euclidian algorithm: \n");
    timing(gcd1, a, b);
    printf("The calculation result of using recursion: \n");
    timing(gcd2, a, b);
    
    return 0;
}
