#include <stdio.h>

int main() {
    FILE *fp = fopen("read.c", "r");
    char read[BUFSIZ];
    char clist[1000][1000];
    if (fp == NULL) {
        perror("開きたいファイル名.拡張子 を開けませんでした。");
        return 1;
    }

    int chr;
    int n,comment=0,txt=0,x=0,y=0;
    char before;
    for(n=0;(chr = fgetc(fp)) != EOF;n++) {
        if(chr!='\n'){
            read[n]=chr;
        }
        if(chr=='\"' && read[n-1]!='\\' && txt!=2){
            if(txt==0){
                txt=1;
            }
            else{
                txt=0;
            }
        }
        else if(chr=='\"' && read[n-1]!='\\' && txt!=1){
            if(txt==0){
                txt=2;
            }
            else{
                txt=0;
            }
        }
        if(comment==1){
            clist[x][y]=chr;
            y++;
        }
        if(read[n]=='*' && read[n-1]=='/' && txt!=1){
            comment=1;
        }
        if(comment==1 && read[n]=='/' && read[n-1]=='*' && txt!=1){
            comment=0;
            x++;
            y=0;
        }

    }

    printf("--------------read.c--------------\n");
    for(int i=0;i<n;i++){
        putchar(read[i]);
    }
    printf("\n\n");
    printf("-------------comment-------------\n");
    for(int i=0;i<x;i++){
        for(int j=0;j<1000;j++){
            if(clist[i][j]!='*' && clist[i][j+1]!='/'){
                putchar(clist[i][j]);
            }
            else{
                break;
            }
        }
        printf("\n");
    }

    fclose(fp);
}