#include <stdio.h>
#include "stack.h"

/*push all the elements poped from stack 1 to stack 3*/
void hanoi(int n, ST* st1, ST* st2, ST* st3) {
    if (n==1) {
        push(st3, pop(st1));
    }
    else {
        hanoi(n-1, st1, st3, st2);
        push(st3, pop(st1));
        hanoi(n-1, st2, st1, st3);
    }
}

int main() {
    int i, n;
    
    printf("Please input n: ");
    scanf("%d", &n);
    if (n<1 || n>N) {
        printf("n is out of range! \n");
        exit(1);
    }
    
    ST st1, st2, st3;
    initialize(&st1);
    initialize(&st2);
    initialize(&st3);
    
    /*push the numbers from n to 1 to stack 1*/
    for (i=0;i<n;i++) push(&st1, n-i);
    /*push all the elements poped from stack 1 to stack 3*/
    hanoi(n, &st1, &st2, &st3);
    
    /*print the numbers from top to bottom*/
    printf("printing the elements in stack 3: \n");
    print_element(&st3);
    
    destroy(&st1);
    destroy(&st2);
    destroy(&st3);
    
    return 0;
}
