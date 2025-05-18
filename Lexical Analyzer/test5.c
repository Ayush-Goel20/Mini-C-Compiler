#include <stdio.h>

int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

double forward(double x[], double y[][10], int n, double value) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    double h = (x[1] - x[0]);
    double u = (value - x[0]) / h;
    double term = 1;
    double result = y[0][0];

    for (int i = 1; i < n; i++) {
        term *= (u - i + 1);
        result += (term * y[0][i]) / fact(i);
    }

    return result;
}

double backward(double x[], double y[][10], int n, double value) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    double h = (x[1] - x[0]);
    double u = (value - x[n - 1]) / h;
    double term = 1;
    double result = y[n - 1][0];

    for (int i = 1; i < n; i++) {
        term *= (u + i - 1);
        result += (term * y[n - 1][i]) / fact(i);
    }

    return result;
}

int main() {
    int n;
    printf("Enter number of data points:\n");
    scanf("%d", &n);

    double x[10], y[10][10];

    printf("Enter values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i][0]);
    }

    double value;
    printf("Enter the value to interpolate:\n");
    scanf("%lf", &value);

    // Forward or backward
    double result = backward(x, y, n, value);
    printf("Interpolated value at %.2f is %.6f\n", value, result);

    return 0;
}
