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
    return AND(OR(OR(a,b),c),OR(AND(AND(a,b),c),OR(OR(AND(a,b),AND(b,c)),AND(c,a))));

}



int FA_1(int a,int b,int c)
{
    return AND(OR(OR(a,b),c),OR(AND(AND(a,b),c),NOT(OR(OR(AND(a,b),AND(b,c)),AND(c,a)))));
}



int main(void){
    int i,a,b,c,s,x;
    for (i=0;i<=7;i++){
        a=(i/2)/2;  b=(i/2)%2;c=i%2;
        s=FA_1(a,b,c); x=FA_2(a,b,c);
        printf("%d %d %d  %d %d\n",a,b,c,x,s );
    }
}