#include <stdio.h>

int weight[] = {10, 20, 30};
int value[] = {60, 100, 120};
int n = 3, capacity = 50;
int best = 0;

void backtrack(int i, int w, int v) {
    if (w > capacity)
        return;

    if (v > best)
        best = v;

    if (i == n)
        return;

    backtrack(i + 1, w + weight[i], v + value[i]);
    backtrack(i + 1, w, v);
}

int main() {
    int dp[4][51] = {0};

    backtrack(0, 0, 0);

    printf("Backtracking result: %d\n", best);

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

    printf("Dynamic Programming result: %d\n",
           dp[n][capacity]);

    return 0;
}