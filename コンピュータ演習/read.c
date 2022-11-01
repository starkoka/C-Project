#include <stdio.h>
/* test */
int
value(char    c){
    if (c=='\'') return 1;
    else if (c=='"') return 2;
    else if (c=='/') return 3;
    else if (c=='*') return 4;
    else if (c=='\\') return 5;
    else return 0;
}
main(){
    char c='"', d[10]="/*\'\\\"*/";
    printf("%c /* %c",c,d[0]);

    int    state[6][5];
/*  test2 */
    int    now,next,k=0;
/*
gets(buffer);
*/
    printf("/*");
/*test3*/



    printf(" \" */ ");
}