#include <stdio.h>
#include <limits.h>

#define MAX 10

void printOptimalParenthesis(int s[MAX][MAX], int i, int j);

void matrixChainOrder(int p[], int n)
{
    int m[MAX][MAX];
    int s[MAX][MAX];

    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int L = 2; L <= n; L++)
    {
        for (int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesization is: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");
}

void printOptimalParenthesis(int s[MAX][MAX], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }
    printf("(");
    printOptimalParenthesis(s, i, s[i][j]);
    printOptimalParenthesis(s, s[i][j] + 1, j);
    printf(")");
}

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[MAX];
    printf("Enter the dimensions of matrices:\n");
    for (int i = 1; i <= n; i++)
    {
    printf("Enter dimension %d: ", i);
    scanf("%d", &p[i]);
   }
  

    matrixChainOrder(p, n);
    return 0;
}