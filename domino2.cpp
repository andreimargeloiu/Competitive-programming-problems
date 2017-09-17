#include<stdio.h>

const int NMAX = 1e6;

int main() {
    freopen("domino2.in", "r", stdin);
    freopen("domino2.out", "w", stdout);
    int dif, last, n, i, j;

    scanf("%d", &n);
    if(n == 2) {
        printf("1 1\n1 2\n2 2\n");
        return 0;
    }

    if(n % 2 == 0) {
        printf("-1\n");
        return 0;
    }

    printf("1 1\n1 2\n2 2\n2 3\n3 3\n3 1\n");

    for(i = 5; i <= n; i += 2) {
        printf("1 %d\n", i - 1);
        printf("%d %d\n", i - 1, i - 1);
        printf("%d %d\n", i - 1, i);
        printf("%d %d\n", i, i);

        dif = 0;
        for(j = i - 2; j >= 2; -- j) {
            printf("%d %d\n", i - dif, j);
            printf("%d %d\n", j, i - 1 + dif);

            dif = 1 - dif;
        }

        printf("%d 1\n", i);
    }
    return 0;
}
