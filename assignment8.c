#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int n, int k)
{
    int *p1 = A;
    int *p2 = A + k;

    while (p1 < p2 && p2 < A + n)
    {
        if (*p1 <= *p2)
        {
            p1++;
        }
        else
        {
            int temp = *p2;
            int *p = p2;

            while (p > p1)
            {
                *p = *(p - 1);
                p--;
            }

            *p1 = temp;

            p1++;
            p2++;
        }
    }
}

int main()
{
    int n, k;

    printf("Enter n: ");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", A + i);

    printf("Enter k: ");
    scanf("%d", &k);

    merge(A, n, k);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(A + i));

    free(A);

    return 0;
}