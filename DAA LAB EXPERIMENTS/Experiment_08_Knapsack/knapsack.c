#include <stdio.h>

int main() {
    int weight[] = {10, 20, 30};
    int value[] = {60, 100, 120};
    int capacity = 50;
    int n = 3;

    int dp[4][51] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                int include = value[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                dp[i][w] = include > exclude ?
                            include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum value: %d\n", dp[n][capacity]);

    return 0;
}