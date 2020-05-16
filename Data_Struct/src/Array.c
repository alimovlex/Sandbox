#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "sglib.h"
SGLIB_DEFINE_ARRAY_SORTING_FUNCTIONS(int, SGLIB_NUMERIC_COMPARATOR)
void massiv(int size)
{
	srand((unsigned)time(NULL));
	int t, i, num[3][3],a[4],b[4];
	//-------------------------------Random Matrix-------------------------------
	for (t = 0; t<size; t++)
		for (i = 0; i<size; i++)
			num[t][i] = rand() % 10;

	printf("Static matrix:\n");
	for (t = 0; t<size; t++)
	{
		for (i = 0; i<size; i++)
			printf("%d ", num[t][i]);
		printf("\n");
	}
    //-------------------------------Random Array one-------------------------------
	for(i=0;i<size;i++)
	    a[i]=rand()%10;
    printf("Static array one:\n");
    for(i=0;i<size;i++)
        printf("%d\t", a[i]);
    printf("\n");
    SGLIB_ARRAY_SINGLE_QUICK_SORT(int, a, size, SGLIB_NUMERIC_COMPARATOR);
    printf("Sorted array one:\n");
    for(i=0;i<size;i++)
        printf("%d\t", a[i]);
    printf("\n");
    //-------------------------------Random Array two-------------------------------
    for(i=0;i<size;i++)
        b[i]=rand()%10;
    printf("Static array two:\n");
    for(i=0;i<size;i++)
        printf("%d\t", b[i]);
    printf("\n");
    sglib_int_array_heap_sort(b, size);
    printf("Sorted array two:\n");
    for(i=0;i<size;i++)
        printf("%d\t", b[i]);
}


//---------------------------dynamic array

void matrix_print(int **A, size_t N, size_t M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%*d", 5, A[i][j]);
		}
		printf("\n");
	}
}
/*
return pointer on 2d dynamic array
!allocates memory -> to be freed later
*/

int ** matrix_alloc(size_t N, size_t M)
{
	int **A = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++)
	{
		A[i] = (int *)malloc(M * sizeof(int));
	}
	return A;
}

void matrix_free(int **A, size_t N)
{
	for (int i = 0; i < N; i++)
	{
		free(A[i]);
	}
	free(A);
}

void matrix(size_t N, size_t M) //---------------calling matrix
{
	srand((unsigned)time(NULL));
	int **A = matrix_alloc(N, M);
	//int x = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = rand() % 10;
			//x += 1;
		}
	}
	printf("Dynamic array:\n");
	matrix_print(A, N, M);
	/*memory investigation*/
	matrix_free(A, N);
}
//--------------------------------dynamic array over
