
#include <stdio.h>
#include <time.h>

void traditional(int A[2][2], int B[2][2], int C[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void strassen(int A[2][2], int B[2][2], int C[2][2])
{
    int a = A[0][0], b = A[0][1];
    int c = A[1][0], d = A[1][1];

    int e = B[0][0], f = B[0][1];
    int g = B[1][0], h = B[1][1];

    int M1 = (a + d) * (e + h);
    int M2 = (c + d) * e;
    int M3 = a * (f - h);
    int M4 = d * (g - e);
    int M5 = (a + b) * h;
    int M6 = (c - a) * (e + f);
    int M7 = (b - d) * (g + h);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

void printMatrix(int C[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }
}

int main()
{
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};

    int C1[2][2], C2[2][2];

    clock_t start, end;

    start = clock();
    traditional(A, B, C1);
    end = clock();

    printf("Traditional Matrix Multiplication:\n");
    printMatrix(C1);
    printf("Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    strassen(A, B, C2);
    end = clock();

    printf("\nStrassen Matrix Multiplication:\n");
    printMatrix(C2);
    printf("Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
