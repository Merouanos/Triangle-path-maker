#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

float **p, se;
int n, i, j, rlength = 0, **R, nbr = 0, **t, tlength = 0,c,k,f;
int main()
{
    do
    {
        printf("Pleasse give me n : \n");
        scanf("%d", &n);
    } while (n < 1);

    p = (float **)malloc(2 * sizeof(float *));
    for (i = 0; i < 2; i++)
        p[i] = (float *)malloc(n * sizeof(float));
    for (i = 0; i < 2; i++)
        for (j = 0; j < n; j++)
        {
            printf("Please give me p[%d,%d] : \n", i, j);
            scanf("%f", &p[i][j]);
        }

    printf("Please give me Sueil :\n");
    scanf("%f", &se);
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (sqrt(pow(p[0][i] - p[0][j], 2) + pow(p[1][i] - p[1][j], 2)) <= se)
                rlength++;

    R = (int **)malloc(2 * sizeof(int *));
    for (i = 0; i < 2; i++)
        R[i] = (int *)malloc(rlength * sizeof(int));
    i = 0;
    while (nbr < rlength)
    {
        j = i + 1;
        while (j < n && nbr < rlength)
        {
            if (sqrt(pow(p[0][i] - p[0][j], 2) + pow(p[1][i] - p[1][j], 2)) <= se)
            {
                R[0][nbr] = i;
                R[1][nbr] = j;
                nbr++;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < rlength - 1)
    {

        j = i + 1;
        while (j < rlength && R[0][i] == R[0][j])
            j++;
        for (int c = i; c < j - 1; c++)
            for (int k = i + 1; k < j; k++)
                for (int f = j; f < n; f++)
                    if (R[1][c] == R[0][f] && R[1][k] == R[1][f])
                        tlength++;
        i = j;
    }
    t = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++)
        t[i] = (int *)malloc(tlength * sizeof(int));

    nbr = 0;
    i = 0;
    while (nbr < tlength)
    {
        j = i + 1;
        while (nbr < tlength && j < rlength && R[0][i] == R[0][j])
            j++;
        for (c = i; c < j - 1; c++)
            for (k = i + 1; k < j; k++)
                for (f = j; f < n; f++)
                    if (R[1][c] == R[0][f] && R[1][k] == R[1][f])
                    {
                        t[0][nbr] = c;
                        t[1][nbr] = k;
                        t[2][nbr] = f;
                        nbr++;
                    }
        i = j;
    }
    printf("The p matrix is :\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %f ", p[i][j]);
        printf("\n");
    }
    printf("\n\n\nThe R matrix is :\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < rlength; j++)
            printf(" %d ", R[i][j]);
        printf("\n");
    }
    printf("\n\n\nThe t matrix is :\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < tlength; j++)
            printf(" %d ", t[i][j]);
        printf("\n");
    }
    for (i = 0; i < 3; i++)
        free(t[i]);
    free(t);
    for (i = 0; i < 2; i++)
        free(R[i]);
    free(R);
    for (i = 0; i < 2; i++)
        free(p[i]);
    free(p);
}
