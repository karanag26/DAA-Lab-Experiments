#include <stdio.h>

int a[] = {2, 3, 4, 5};
int n = 4;
int target = 7;

void findSubsets(int index, int sum) {
    if (sum == target) {
        printf("Subset found\n");
        return;
    }

    if (index == n || sum > target)
        return;

    findSubsets(index + 1, sum + a[index]);
    findSubsets(index + 1, sum);
}

int main() {
    printf("Subsets with sum %d:\n", target);
    findSubsets(0, 0);

    return 0;
}