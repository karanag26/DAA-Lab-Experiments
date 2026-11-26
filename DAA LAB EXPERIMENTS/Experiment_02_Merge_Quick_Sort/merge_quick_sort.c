
#include <stdio.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right)
{
    int temp[1000];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int a[] = {45, 12, 78, 23, 9, 56, 31, 4};
    int b[] = {45, 12, 78, 23, 9, 56, 31, 4};
    int n = 8;

    clock_t start, end;

    printf("Original Array:\n");
    printArray(a, n);

    start = clock();
    mergeSort(a, 0, n - 1);
    end = clock();

    printf("\nMerge Sort:\n");
    printArray(a, n);
    printf("Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    quickSort(b, 0, n - 1);
    end = clock();

    printf("\nQuick Sort:\n");
    printArray(b, n);
    printf("Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
