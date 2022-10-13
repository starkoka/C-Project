#include <stdio.h>

int uruu(int y){
    if(y%4==0){
        if(y%400){
            return 1;
        }
        else if(y%100){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int count(int y,int m,int d,int x){
    int ans;
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(uruu(y)==1){day[1]==29;}
    for(int i=0; i<y-x;i++){
        if(uruu(i)==1){
            ans+=366;
        }
        else{
            ans+=365;
        }
    }
    for(int i=0; i<m-1;i++){
        ans+=day[i];
    }
    ans+=d;
    return ans;
}

int youbi(int d,int y){
    int n=d+count(y,1,1,1);
    return n;

}

int main(void){
    int y,m,d,x,n;
    int ans;
    printf("何年?");
    scanf("%d",&y);
    printf("何月?");
    scanf("%d",&m);
    printf("何日?");
    scanf("%d",&d);
    printf("何年の1月1日から?");
    scanf("%d",&x);

    if(y<1|| m<0 || m>13 || d<0){printf("\nばーか");return 0;}
    else{
        ans=count(y,m,d,x);
        printf("%d年からの日数は初日を含めないで%d日です\n",x,ans-1);
        n=youbi(ans,x);
        if(n%7==0){
            printf("今日は木曜日です");
        }
        else if(n%7==1){
            printf("今日は金曜日です");
        }
        else if(n%7==2){
            printf("今日は土曜日です");
        }
        else if(n%7==3){
            printf("今日は日曜日です");
        }
        else if(n%7==4){
            printf("今日は月曜日です");
        }
        else if(n%7==5){
            printf("今日は火曜日です");
        }
        else{
            printf("今日は水曜日です");
        }
    }
    printf("\n今月のカレンダーを表示します\n\n--------------%d年%d月のカレンダー--------------\n  日     月     火     水     木     金     土  \n",y,m);
    int c=0;int day[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    n=(n-d+1)%7-3;
    if(n-3<0)n+=7;
    if(uruu(y)==1){
        day[1]=29;
    }
    else{
        day[1]=28;
    }
    printf("  ");
    for(int i=0;i<n;i++){
        printf("　     ");
    }

    for(int i=n;i<day[m-1]+n;i++){
        if(i-n+1<10){
            printf("%d  　  ",i-n+1);
        }
        else{
            printf("%d  　 ",i-n+1);
        }
        if(i%7==6){
            printf("\n  ");
        }
    }


}