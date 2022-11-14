#include <stdio.h>
#include <stdlib.h>

#define N 100 /*the capacity of the stack*/

typedef struct Stack{
    int* arr; /*the address of the first element*/
    int top;
}ST;

/*initialize the stack*/
void initialize(ST* st) {
    int* a = (int *)malloc(N*sizeof(int));
    st->arr = a;
    st->top = 0;
}

/*destroy the stack*/
void destroy(ST* st) {
    free(st->arr);
    st->arr=NULL;
    st->top=0;
}

void push(ST* st, int element) {
    if (st->top>=N) {
        printf("Error! The stack is full! \n");
        return;
    }
    
    *(st->arr + st->top) = element;
    st->top++;
}

int pop(ST* st) {
    if (st->top<=0) {
        printf("Error! The stack is empty! \n");
        return 0;
    }
    
    int tmp = *(st->arr + st->top - 1);
    st->top--;
    return tmp;
}

/*print the numbers from top to bottom*/
void print_element(ST* st) {
    if (st->top<=0) {
        printf("The stack is empty! \n");
        return;
    }
    
    int i;
    for (i=0;i<st->top;i++) printf("arr[%d]=%d \n", st->top-i-1, *(st->arr+st->top-i-1));
}
