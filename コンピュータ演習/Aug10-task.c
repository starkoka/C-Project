#include <stdio.h>
#include <string.h>



int main(char){
    /*初期化、および英文の取得*/
    int c=0,n=-1,m=0,i;
    char S[BUFSIZ];
    char cmd;
    printf("英文を入力してください ");
    fgets(S,BUFSIZ,stdin);

    /*最長の単語数を取得してnに入れる*/
    for(i=0;i<sizeof(S) / sizeof(char);i++){
        if(S[i]==' ' || S[i]=='\000'){
            c++;
            if(m==0){
                n=i-m;
            }
            else{
                if(n<i-m-1){n=i-m-1;}
            }
            m=i;
        }
        if(S[i]=='\000'){m=-1;break;}
    }
    if(i-m>n && m>=0){
        if(m==0){
            n=i-m;
        }
        else{
            n=i-m-1;
        }
    }

    /*配列に単語を入れる*/
    /*cは単語数、nは単語の最大の長さ*/
    m=-1; /*今何文字目?*/
    char list[c][n];
    char oldlist[c][n];
    for(i=0;i<c;i++){
        for(int j=0;j<n+1;j++){
            m++;
            if(S[m]==' ' || S[m]=='\000' || S[m]=='\n'){
                for(int k=0;k<n-j;k++){
                    list[i][j+k]='\000';
                    oldlist[i][j+k]='\000';
                }
                break;
            }
            else{
                list[i][j]=S[m];
                oldlist[i][j]=S[m];
            }
        }
    }


    printf("\n\n------------HELP------------\n");
    printf("h  ヘルプを表示\n");
    printf("p  現在の単語リストを表示\n");
    printf("q  原文を表示\n");
    printf("s  辞書順にソート\n");
    printf("t  逆順にソート\n");
    printf("a  プロググラムの概要\n");
    printf("z  プログラムを終了\n");
    printf("----------------------------\n\n");
    while(cmd!='z'){
        printf("(command)> ");
        scanf("%c",&cmd);
        getchar();
        if(cmd=='h'){
            printf("\n\n------------HELP------------\n");
            printf("h  ヘルプを表示\n");
            printf("p  現在の単語リストを表示\n");
            printf("q  原文を表示\n");
            printf("s  辞書順にソート\n");
            printf("t  逆順にソート\n");
            printf("a  プロググラムの概要\n");
            printf("z  プログラムを終了\n");
            printf("----------------------------\n\n");
        }
        else if(cmd=='a'){
            printf("8月10日提出のコンピューター演習1の課題(4)のプログラムです。\n");
        }
        else if(cmd=='p'){
            for(i=0;i<c;i++){
                for(int j=0;j<n;j++){
                    if(list[i][j]=='\000'){break;}
                    else{printf("%c",list[i][j]);}
                }
                printf("\n");
            }
        }
        else if(cmd=='q'){
            for(i=0;i<c;i++){
                for(int j=0;j<n;j++){
                    if(oldlist[i][j]=='\000'){break;}
                    else{printf("%c",oldlist[i][j]);}
                }
                printf("\n");
            }
        }
        else if(cmd=='t'){
            int o=1,n1=n,n2=n;
            /*一つ右隣りと比較して、アルファベット順に並び変える*/
            for(i=0;i<c-1;i++){
                for (int j = 0; j <n; ++j) {
                    if(list[i][j]=='\000'){
                        n1=j+1;
                        break;
                    }
                }
                for (int j = 0; j <n; ++j) {
                    if(list[i+1][j]=='\000'){
                        n2=j+1;
                        break;
                    }
                }
                char check1[n1];
                char check2[n2];
                for(int j=0;j<n1;j++){
                    if(list[i][j]=='\000'){break;}
                    else{
                        if(list[i][j]>96){
                            check1[j]=list[i][j]-32;
                        }
                        else{
                            check1[j]=list[i][j];
                        }
                    }
                }
                for (int j = 0; j < n2; ++j) {
                    if(list[i][j]>96){
                        check2[j]=list[i+1][j]-32;
                    }
                    else{
                        check2[j]=list[i+1][j];
                    }
                }
                if(strcmp(check1,check2)<0){
                    o=0;
                    char m[n];
                    for(int j=0;j<n;j++){
                        m[j]=list[i][j];
                    }
                    for(int j=0;j<n;j++){
                        list[i][j]=list[i+1][j];
                    }
                    for(int j=0;j<n;j++){
                        list[i+1][j]=m[j];
                    }
                }
            }
            /*並び替えが生じなくなるまで比較・入れ替えを繰り返す*/
            while(o==0) {
                o = 1;
                for (i = 0; i < c - 1; i++) {
                    for (int j = 0; j < n; ++j) {
                        if (list[i][j] == '\000') {
                            n1 = j + 1;
                            break;
                        }
                    }
                    for (int j = 0; j < n; ++j) {
                        if (list[i + 1][j] == '\000') {
                            n2 = j + 1;
                            break;
                        }
                    }
                    char check1[n1];
                    char check2[n2];
                    for (int j = 0; j < n1; j++) {
                        if (list[i][j] == '\000') { break; }
                        else {
                            if (list[i][j] > 96) {
                                check1[j] = list[i][j] - 32;
                            } else {
                                check1[j] = list[i][j];
                            }
                        }
                    }
                    for (int j = 0; j < n2; ++j) {
                        if (list[i][j] > 96) {
                            check2[j] = list[i + 1][j] - 32;
                        } else {
                            check2[j] = list[i + 1][j];
                        }
                    }
                    if (strcmp(check1, check2) < 0) {
                        o = 0;
                        char m[n];
                        for (int j = 0; j < n; j++) {
                            m[j] = list[i][j];
                        }
                        for (int j = 0; j < n; j++) {
                            list[i][j] = list[i + 1][j];
                        }
                        for (int j = 0; j < n; j++) {
                            list[i + 1][j] = m[j];
                        }
                    }
                }
            }
        }
        else if(cmd=='s'){
            int o=1,n1=n,n2=n;
            /*一つ右隣りと比較して、アルファベット順に並び変える*/
            for(i=0;i<c-1;i++){
                for (int j = 0; j <n; ++j) {
                    if(list[i][j]=='\000'){
                        n1=j+1;
                        break;
                    }
                }
                for (int j = 0; j <n; ++j) {
                    if(list[i+1][j]=='\000'){
                        n2=j+1;
                        break;
                    }
                }
                char check1[n1];
                char check2[n2];
                for(int j=0;j<n1;j++){
                    if(list[i][j]=='\000'){break;}
                    else{
                        if(list[i][j]>96){
                            check1[j]=list[i][j]-32;
                        }
                        else{
                            check1[j]=list[i][j];
                        }
                    }
                }
                for (int j = 0; j < n2; ++j) {
                    if(list[i][j]>96){
                        check2[j]=list[i+1][j]-32;
                    }
                    else{
                        check2[j]=list[i+1][j];
                    }
                }
                if(strcmp(check1,check2)>0){
                    o=0;
                    char m[n];
                    for(int j=0;j<n;j++){
                        m[j]=list[i][j];
                    }
                    for(int j=0;j<n;j++){
                        list[i][j]=list[i+1][j];
                    }
                    for(int j=0;j<n;j++){
                        list[i+1][j]=m[j];
                    }
                }
            }
            /*並び替えが生じなくなるまで比較・入れ替えを繰り返す*/
            while(o==0) {
                o = 1;
                for (i = 0; i < c - 1; i++) {
                    for (int j = 0; j < n; ++j) {
                        if (list[i][j] == '\000') {
                            n1 = j + 1;
                            break;
                        }
                    }
                    for (int j = 0; j < n; ++j) {
                        if (list[i + 1][j] == '\000') {
                            n2 = j + 1;
                            break;
                        }
                    }
                    char check1[n1];
                    char check2[n2];
                    for (int j = 0; j < n1; j++) {
                        if (list[i][j] == '\000') { break; }
                        else {
                            if (list[i][j] > 96) {
                                check1[j] = list[i][j] - 32;
                            } else {
                                check1[j] = list[i][j];
                            }
                        }
                    }
                    for (int j = 0; j < n2; ++j) {
                        if (list[i][j] > 96) {
                            check2[j] = list[i + 1][j] - 32;
                        } else {
                            check2[j] = list[i + 1][j];
                        }
                    }
                    if (strcmp(check1, check2) > 0) {
                        o = 0;
                        char m[n];
                        for (int j = 0; j < n; j++) {
                            m[j] = list[i][j];
                        }
                        for (int j = 0; j < n; j++) {
                            list[i][j] = list[i + 1][j];
                        }
                        for (int j = 0; j < n; j++) {
                            list[i + 1][j] = m[j];
                        }
                    }
                }
            }
        }
        else{
            if(cmd!='z')printf("ヘルプを表示するには、コマンドhを入力してください\n\n");
        }
    }

    return 'z';
}