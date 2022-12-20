#include <stdio.h>

int ten2two(int a){
    if (a>=2)  {
        ten2two(a/2);
        printf("%d",a%2);
    }
    else printf("%d",a%2);
    return 0;
}
int mod16(int n){
    if (n<0) return n+16;
    else return n;
}
int main(void){
    int n;
    for (n=7;n>=-8;n--){
        printf("%d  ",n);
        for(int i=1;i<=3;i++){
            if(n<pow(2,i) && n>=0){
                printf("0");
            }
        }
        ten2two(mod16(n));printf("\n");}
}