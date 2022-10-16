#include <stdio.h>

/*Use *pre to store f(n-1) and *p to store f(n)*/

void fibonacci(int n, int* pre, int* p){
    
    int f0=0, f1=1;
    *pre = f0;
    *p = f1;
    int tmp;
    
    if (n<1) printf("Error! n<1! \n");
    
    while (n>1) {
        tmp = *pre + *p;
        *pre = *p;
        *p = tmp;
        n--;
    }
    
}

int main() {
    int n, pre, p;
    
    printf("Please input n: \n");
    scanf("%d", &n);
    fibonacci(n, &pre, &p);
    printf("f(%d)=%d \n", n, p);
    printf("f(%d)=%d \n", n-1, pre);
    
    return 0;
    
}
