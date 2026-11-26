#include <stdio.h>

void activitySelection(int start[], int finish[], int n) {
    int i, j;
    printf("Selected activities: ");

    i = 0;
    printf("%d ", i + 1);

    for (j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("%d ", j + 1);
            i = j;
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    activitySelection(start, finish, n);

    return 0;
}