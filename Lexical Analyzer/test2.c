#include <stdio.h>
int main() {
    int n, i, j, k;
    float a[10][11], x[10], ratio;
    // Input
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix (coefficients and RHS):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    // Forward Elimination
    for (i = 0; i < n - 1; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error: Division by zero!\n");
            return -1;
        }
        for (j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }
    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    // Output
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.3f\n", i + 1, x[i]);
    }
    return 0;
}
