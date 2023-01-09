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



int FA_2(int a,int b,int c){
    return OR(OR(AND(a,b),AND(b,c)),AND(c,a));
}



int FA_1(int a,int b,int c){
    return AND(OR(OR(a,b),c),OR(NOT(OR(OR(AND(a,b),AND(b,c)),AND(c,a))),AND(AND(a,b),c)));
}
int main ()
{

    int a[4]={1,1,0,1};
    int b[4]={0,1,1,1};
    int k=0;
    int c[sizeof(a)/sizeof(int)];
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        c[sizeof(a)/sizeof(int)-i-1]=FA_1(a[sizeof(a)/sizeof(int)-i-1],b[sizeof(a)/sizeof(int)-i-1],k);
        k=FA_2(a[sizeof(a)/sizeof(int)-i-1],b[sizeof(a)/sizeof(int)-i-1],k);
    }

    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        printf("%d",a[i]);
    }
    printf("\n+)");
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        printf("%d",b[i]);
    }
    printf("\n------\n%d",k);
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        printf("%d",c[i]);
    }

    return 0;
}