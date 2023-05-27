#include <stdio.h>
#include <stdlib.h>


void InputArray_1D(int*& a, int& n);
void OutputArray_1D(int* a, int n);
void FreeArray_1D(int*& a);
void InputMatrix(int**& mat, int &n);
void OutputMatrix(int** mat, int n);
void FreeMatrix(int**& mat, int n);

void InputArray_1D(int*& a, int& n)
{
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    if(a==NULL) return;
    for (int i=0; i<n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void OutputArray_1D(int* a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d \t", a[i]);
    }
}
void FreeArray_1D(int*& a)
{
    free(a);
}
void InputMatrix(int**& mat, int &n)
{
    scanf("%d", &n);
    mat = (int**)malloc(n*sizeof(int*));
    if(mat==NULL) return;
    for (int i=0; i<n; i++)
    {
        mat[i] = (int*)malloc(n*sizeof(int));
        for (int j = 0; j<n; j++)
        {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void OutputMatrix(int** mat, int n)
{  
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        { 
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}
void FreeMatrix(int**& mat, int n)
{
    free(mat);
}

int main()
{
    int n;
    int* a = NULL; 
    printf("Enter number of array element: ");
    InputArray_1D(a, n);
    printf("\nPrint Array: \n");
    OutputArray_1D(a, n);
    FreeArray_1D(a);
    // OutputArray_1D(a, n);

    int** mat = NULL;
    int m;
    printf("\n\nEnter number of matrix element: ");
    InputMatrix(mat, m);
    printf("\nPrint Matrix: \n");
    OutputMatrix(mat, m);
    FreeMatrix(mat, m);
    // OutputMatrix(mat, m);
    return 0;
}