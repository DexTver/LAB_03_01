#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n = 1, cnt = 0, ind = 0;
    printf("Enter the number of columns:\n");
    scanf("%i", &m);
    int **a;
    if ((a = (int **) malloc(sizeof(int *))) != NULL) {
        if ((a[0] = (int *) malloc((m + 1) * sizeof(int *))) != NULL) {
            printf("Enter first line:\n");
            for (int i = 1; i <= m; ++i) {
                scanf("%i", &a[0][i]);
                if (n < abs(a[0][i])) {
                    n = abs(a[0][i]);
                }
            }
        } else {
            printf("Something's wrong!");
        }
    } else {
        printf("Something's wrong!");
    }
    if ((a = (int **) realloc(a, n * sizeof(int *))) != NULL) {
        for (int i = 1; i < n; ++i) {
            if ((a[i] = (int *) malloc((m + 1) * sizeof(int *))) != NULL) {
                printf("Enter next line:\n");
                for (int j = 1; j <= m; ++j) {
                    scanf("%i", &a[i][j]);
                }
            } else {
                printf("Something's wrong!");
            }
        }
    } else {
        printf("Something's wrong!");
    }

    for (int i = 0; i < n; ++i) {
        a[i][0] = 1;
        for (int j = 2; j <= m && a[i][0] == 1; j += 2) {
            if (a[i][j] % 2 != 0) {
                a[i][0] = 0;
            }
        }
        cnt += a[i][0];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }

    int b[m][cnt];
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == 1) {
            for (int j = 1; j <= m; ++j) {
                b[m - j][ind] = a[i][j];
            }
            ++ind;
        }
    }
    printf("Required matrix:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < cnt; ++j) {
            printf("%i ", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    getchar();
    return 0;
}
