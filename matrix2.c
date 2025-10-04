#include <stdio.h>
void addmatrix(int mata[100][100], int matb[100][100], int matc[100][100],int m,int n)
{
    int i,j;
    for (i=0; i<m; i++)
    for (j=0; j<n; j++)
    {
    matc[i][j] = mata[i][j] + matb[i][j];
    }
}

void submatrix(int mata[100][100], int matb[100][100], int matc[100][100],int m,int n)
{
    int i,j;
    for (i=0; i<m; i++)
    for (j=0; j<n; j++)
    {
    matc[i][j] = mata[i][j] - matb[i][j];
    }
}

void multimatrix(int mata[100][100], int matb[100][100], int matc[100][100],int m,int n )
{
    int i,j,k;
    for (i=0; i<m; i++)
    {
      for (j=0; j<n; j++)
      {
        matc[i][j] = 0;
      }
    }
    for (i=0; i<m; i++)
    {
      for (j=0; j<n; j++)
      {
        for (k=0; k<n; k++)
        {
          matc[i][j] += mata[i][k] * matb[k][j];
        }
      }
    }
}

void printmat(int d[100][100], int x, int y)
{
  int i,j;
  for (i = 0; i < x; ++i)
    for (j = 0; j < y; ++j) {
      printf("%d   ", d[i][j]);
      if (j == y - 1) {
        printf("\n\n");
      }
    }
}

int main ()
{
    int i,j,n,m;
    printf ("Enter The Rows of Matrix :\n");
    scanf ("%d",&m);
    printf ("Enter The Columns of Matrix :\n");
    scanf ("%d",&n);
    int mata[100][100];
    printf ("Enter The Elements of the Matrix A : \n");
    for (i=0 ; i<m; i++)
    for (j=0; j<n; j++)
    {
        printf("Enter elements of A %d%d : ",i+1,j+1);
        scanf ("%d",&mata[i][j]);
    }
    int matb[100][100];
    int matc[100][100];
    printf ("Enter The Elements of the Matrix B : \n");
    for (i=0 ; i<m; i++)
    for (j=0; j<n; j++)
    {
        printf("Enter elements of B %d%d : ",i+1,j+1);
        scanf ("%d",&matb[i][j]);
    }
    printf("Matrix A is : \n");
    printmat(mata,m,n);

    printf("Matrix B is : \n");
    printmat(matb,m,n);

    int input;
    printf ("What To Do With The Given Matrix :\n Enter 1 for Addition, 2 for Multiplication and 3 for Subtraction : \n");
    scanf ("%d", &input);
    if (input==1)
    {
      addmatrix(mata,matb,matc,m,n);
    }
    if (input==2)
    {
      multimatrix(mata,matb,matc,m,n);
    }
    if (input==3)
    {
      submatrix(mata,matb,matc,m,n);
    }
    else
    printf ("Please enter a valid value.\n");
    

    printf("Result matrix is :\n");
    printmat(matc,m,n);

    return 0;
}