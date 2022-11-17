#include <stdio.h>
#include <math.h>
#include <malloc.h>

int NAND(int a,int b){
    return 1-a*b;
}



int AND(int a,int b){
    return NAND(NAND(a,b),NAND(a,b));
}



int NOT(int a){
    return NAND(a,a);
}



int OR(int a,int b){
    return NAND(NAND(a,a),NAND(b,b));
}


int XOR(int a,int b){
    //OR(AND(a,NOT(b)),AND(b,NOT(a)));
    //return NAND(NAND(AND(a,NOT(b)),AND(a,NOT(b))),NAND(AND(b,NOT(a)),AND(b,NOT(a))));
    return NAND(NAND(NAND(NAND(a,NAND(b,b)),NAND(a,NAND(b,b))),NAND(NAND(a,NAND(b,b)),NAND(a,NAND(b,b)))),NAND(NAND(NAND(b,NAND(a,a)),NAND(b,NAND(a,a))),NAND(NAND(b,NAND(a,a)),NAND(b,NAND(a,a)))));
}



int FA_2(int a,int b,int c)
{
    return (a+b+c)/2;
}



int FA_1(int a,int b,int c)
{
    return (a+b+c)%2;
}



int main(void){
    int A,B;
    printf("A, B, AND(A,B), XOR(A,B)\n");
    for (A=0;A<=1;A++)
        for(B=0;B<=1;B++)
            printf("%d  %d     %d        %d\n", A, B, AND(A,B), XOR(A,B));
    return 0;
}

/*
*/