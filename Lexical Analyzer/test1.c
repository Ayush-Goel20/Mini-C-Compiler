#include<stdio.h>
#include<math.h>
double f(double x,double y){
    return x+y;
}
double rk(double x0,double y0, double h, int n){
    double k1,k2,k3,k4,y=y0,x=x0;
    printf("steps\tx\ty\n");
    for(int i=0;i<=n;i++){
        printf("%d\t%.6lf\t%.6lf\n",i,x,y);
        k1=h*f(x,y);
        k2=h*f(x+h/2,y+k1/2);
        k3=h*f(x+h/,y+k2/3);
        k4=h*f(x+h,y+k3);
        y+=(k1+2*k2+2*k3+k4)/6;
        x+=h;
    }
    return y;
}
int main(){
    double x0,y0,h,result;
    int n;
    printf("Enter x0");
    scanf("%lf",&x0);
     printf("Enter y0");
    scanf("%lf",&y0);
     printf("Enter h");
    scanf("%lf",&h);
     printf("Enter n");
    scanf("%d",&n);
    result=rk(x0,y0,h,n);
    printf("the final value of y at x= %.6lf is :%.6lf\n",x0+n*h,result);
    return 0;
}
