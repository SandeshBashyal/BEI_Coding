#include<iostream>
#include<math.h>
#include<conio.h>
#define f(x) exp(x)-3*x
#define error 0.0001
using namespace std;
void intro(){
    cout<<("******************************\n");
    cout<<("<------Bisection Method------>\n");
    cout<<("******************************\n");
}
void bisect(float a, float b){
    float c,x;
    c=(a+b)/2;
    do{
        if((f(a))*(f(c))<0){
            b=c;
        }
        else{
            a=c;
        }
        c=(a+b)/2;
        x=(fabs(b)-fabs(a))/fabs(b);
    }while(x>error);
    cout<<"Root is "<<c<<endl;
}
int main(){
    float x1,x2,xi;
    intro();
    up:
    cout<<"Enter two inital guesses: "<<endl;
    cin>>x1>>x2;
    if((f(x1))>(f(x2))){
        xi=x1;
        x1=x2;
        x2=xi;
    }
    cout<<"x1 = "<<x1<<endl<<"x2 = "<<x2<<endl;
    if((f(x1))*(f(x2))>0){
        cout<<"Guesses are worng";
        goto up;
    }
    else{
        bisect(x1,x2);
        getch();
    }
}
