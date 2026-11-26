#include <stdio.h>
#include <limits.h>

int main() {
    int p[] = {10, 20, 30, 40};
    int n = 3;
    int m[4][4] = {0};

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    printf("Minimum multiplication cost: %d", m[1][n]);
    return 0;
}