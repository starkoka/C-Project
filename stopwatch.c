#include <stdio.h>
#include <termio.h>
#include <sys/time.h>

char getchar_sp (void){
    struct termio old_term, new_term;
    char c;
    ioctl (0, TCGETA, &old_term);
    new_term = old_term;
    new_term.c_lflag &= ~(ICANON | ECHO);
    ioctl (0, TCSETAW, &new_term);
    c = getchar ();
    ioctl (0, TCSETAW, &old_term);
    return (c);
}

int main(void){
    int h,m,s,sec,usec,count,stdsec,stdusec;

    sec=0;
    struct timeval _time;
    gettimeofday(&_time, NULL);
    stdsec = _time.tv_sec;
    stdusec = _time.tv_usec;
    printf("0:0:0.0\n");

    while(1){
        char key=getchar_sp();
        if(key=='r'){
            sec=0;usec=0;
            struct timeval _time;
            gettimeofday(&_time, NULL);
            stdsec = _time.tv_sec;
            stdusec = _time.tv_usec;
            printf("リセットしました\n");
            printf("0:0:0.000000\n");

        }
        else if(key=='m'){
            if(count==0){
                count=1;
                struct timeval _time;
                gettimeofday(&_time, NULL);
                sec+=_time.tv_sec-stdsec;
                int x=_time.tv_usec-stdusec;
                if(x<0){
                    x+=1000000;
                }
                usec+= x;
                if(usec>=1000000){
                    usec=usec%1000000;
                }
                stdsec = _time.tv_sec;
                stdusec = _time.tv_usec;
                printf("一時停止しました\n");
            }
            else{
                count=0;
                printf("再開しました\n");
            }
            int h,m,s;
            h=sec/3600;
            m=(sec-h*3600)/60;
            s=sec%60;
            printf("%d:%d:%d.%d\n\n",h,m,s,usec);
        }

    }
}