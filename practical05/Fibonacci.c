#include <stdio.h>
#include <stdlib.h>

/*Use *pre to store f(n-1) and *p to store f(n)*/

void fibonacci(int* pre, int* p){
    
    int tmp;
    
    tmp = *pre + *p;
    *pre = *p;
    *p = tmp;
    
}

int main() {
    int n, pre=0, p=1;
    
    printf("Please input n: ");
    scanf("%d", &n);
    
    if (n<1) {
        printf("Error! n<1! \n");
        exit(1);
    }
    
    printf("The Fibonacci sequence is : \n");
    printf("%d \n", pre);
    printf("%d \n", p);
    
    while (n>1) {
        fibonacci(&pre, &p);
        printf("%d \n", p);
        n--;
    }
    
    return 0;
    
}
