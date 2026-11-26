#include <stdio.h>

int weight[] = {10, 20, 30};
int value[] = {60, 100, 120};
int n = 3, capacity = 50;
int maxValue = 0;

void solve(int i, int w, int v) {
    if (w > capacity)
        return;

    if (v > maxValue)
        maxValue = v;

    if (i == n)
        return;

    solve(i + 1, w + weight[i], v + value[i]);
    solve(i + 1, w, v);
}

int main() {
    solve(0, 0, 0);

    printf("Maximum value: %d\n", maxValue);

    return 0;
}