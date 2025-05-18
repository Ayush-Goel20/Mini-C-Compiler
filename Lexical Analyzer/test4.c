#include<stdio.h>
double f(double x){
    return 1/(1+x*x);
}
int main(){
    float a,b,h,result;
    int n;
    printf("Enter lower limit a");
    scanf("%f",&a);
    printf("Enter upper limit a");
    scanf("%f",&b);  
    printf("Enter no of intervals");
    scanf("%d",&n);
    if(n%3!=0){
        printf("error");
        return 1;
    } 
    h=(b-a)/n;
    result=f(a)+f(b);
    for(int i=1;i<n;i++){
        float x=a+i*h;
        if(i%3==0){
            result+=2*f(x);
        }
        else{
            result+=3*f(x);
        }
    }
    result=result*(3*h/8);
    printf("%f",result);
    return 0;
}

