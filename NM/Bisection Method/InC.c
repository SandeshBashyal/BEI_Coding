#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
// #define e 2.718281828459
//#define f(x) pow(e,x)- 3*x
#define f(x) exp(x)-3*x
#define error 0.0001
void intro(){
    printf("******************************\n");
    printf("<------Bisection Method------>\n");
    printf("******************************\n");
}
void bisect(float a,float b){
    float c,x;
    c=(a+b)/2;
    int count=0;
    do{
        if((f(a))*(f(c))<0){
            b=c;
        }
        else{
            a=c;
        }
        count++;
        c=(a+b)/2;
        x=(fabs(b)-fabs(a))/fabs(b);
    }while(x>error);
    printf("Iteration done= %d\n",count);
    printf("Root is %f",c);
}
int main(){
    float x1,x2,xi;
    intro();
    up:
    printf("Enter two inital guess \n");
    scanf("%f %f",&x1,&x2);
    if(x1>x2){
        xi=x1;
        x1=x2;
        x2=xi;
    }
    printf("x1= %f and x2= %f \n", x1, x2);
    printf("f(x1)= %f\n", f(x1));
    printf("f(x2)= %f\n", f(x2));
    if ((f(x1))*(f(x2))>0){
        printf("Guesses are wrong, enter new guesses");
        goto up;
    }
    else{
        // x0=(x1+x2)/2;
        // printf("x0= %f, f(x0)= %f\n",x0,f(x0));
        bisect(x1,x2);
        getch();
    }
    
}
