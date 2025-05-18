#include<stdio.h>
double f(double x){
    return 1/(1+x*x);
}
int main()
{
    double a,b,h,result;
    int n;
    printf("Enter lower limit a");
    scanf("%lf",&a);
    printf("Enter upper limit a");
    scanf("%lf",&b);  
    printf("Enter no of intervals");
    scanf("%d",&n);
    if(n%2!=0){
        printf("error");
        return 1;
    } 
    h=(b-a)/n;
    result=f(a)+f(b);
    for(int i=1;i<n;i++){
        double x=a+i*h;
        if(i%2==0){
            result+=2*f(x);
        }
        else{
            result+=4*f(x);
        }
    }
    result=result*(h/3);
    printf("%lf",result);
    return 0;
}

