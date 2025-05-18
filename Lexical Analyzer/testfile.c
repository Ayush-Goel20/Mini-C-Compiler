#include <stdio.h>
#include <math.h>

int main() {
    float a[10][11], x[10], ratio;
    int i, j, k, n;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    // Applying Gauss Elimination
    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Math Error: Division by zero\n");
            return 0;
        }

        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k <= n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Obtaining solution
    for (i = 0; i < n; i++) {
        x[i] = a[i][n] / a[i][i];
    }

    // Displaying solution
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.3f\n", i + 1, x[i]);
    }

    return 0;
}
