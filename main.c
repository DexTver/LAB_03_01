#include <stdio.h>
#include <math.h>

int main() {
    int m, n = 1, cnt = 0, ind = 0;
    printf("Enter the count of columns:\n");
    scanf("%i", &m);
    printf("Enter the first line:\n");

    int first_line[m];
    for (int j = 0; j < m; ++j) {
        scanf("%i", first_line + j);
        if (abs(first_line[j]) > n) {
            n = abs(first_line[j]);
        }
    }

    int a[n][m], check[n];
    for (int j = 0; j < m; ++j) {
        a[0][j] = first_line[j];
    }
    for (int i = 1; i < n; ++i) {
        printf("Enter next line:\n");
        for (int j = 0; j < m; ++j) {
            scanf("%i", &a[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        check[i] = 1;
        for (int j = 1; j < m && check[i] == 1; j += 2) {
            if (a[i][j] % 2 != 0) {
                check[i] = 0;
            }
        }
        cnt += check[i];
    }
    int b[m][cnt];
    if (cnt == 0) {
        printf("The matrix is empty!");
    } else {
        for (int i = 0; i < n; ++i) {
            if (check[i] == 1) {
                for (int j = 0; j < m; ++j) {
                    b[m - j - 1][ind] = a[i][j];
                }
                ++ind;
            }
        }

        printf("Required matrix:");
        for (int i = 0; i < m; ++i) {
            printf("\n");
            for (int j = 0; j < cnt; ++j) {
                printf("%i ", b[i][j]);
            }
        }
    }
    return 0;
}
