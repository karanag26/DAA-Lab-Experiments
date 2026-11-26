
#include <stdio.h>

int iterativeSearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int recursiveSearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] < key)
        return recursiveSearch(arr, mid + 1, high, key);

    return recursiveSearch(arr, low, mid - 1, key);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key = 40;

    int result1 = iterativeSearch(arr, n, key);
    int result2 = recursiveSearch(arr, 0, n - 1, key);

    printf("Iterative Search:\n");
    if (result1 != -1)
        printf("Element found at index %d\n", result1);
    else
        printf("Element not found\n");

    printf("\nRecursive Search:\n");
    if (result2 != -1)
        printf("Element found at index %d\n", result2);
    else
        printf("Element not found\n");

    return 0;
}
