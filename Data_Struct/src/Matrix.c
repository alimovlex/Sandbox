#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "sglib.h"
#include "DuoList.h"
#include "c_lib.h"
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

static int
compare_e(const void* left, const void* right) {
    int *l = (int*)left;
    int *r = (int*)right;
    return (*l - *r);
}

static int
compare_e_ptr(const void* left, const void* right) {
    int *l = *((int**)left);
    int *r = *((int**)right);
    return (*l - *r);
}

static int
compare_e_str(const void* left, const void* right) {
    char *l = *((char**)left);
    char *r = *((char**)right);
    return strcmp(l, r);
}

static void
free_e(void* ptr) {
    if (ptr) {
        void *p = *((void **)ptr);
        if (p) {
            free(p);
        }
    }
}

static void print_e(int *ptr) {
    if (ptr) {
        printf("%d\n", *(int*)ptr);
    }
}

void stl_int_array()
{
    size_t size = 10;
    int i = 0;
    int *p_rv = (int *)0;
    int rv = 0;
    struct cstl_array* myArray = cstl_array_new(8, compare_e, NULL);
    assert(cstl_true == cstl_array_empty(myArray));

    for (i = 0; i < (int)size; i++) {
        cstl_array_push_back(myArray, &i, sizeof(int));
    }
    assert(cstl_false == cstl_array_empty(myArray));
    assert(size == cstl_array_size(myArray));
    for (i = 0; i < (int)size; i++) {
        p_rv = (int *) cstl_array_element_at(myArray, i);
        rv = *(int*)p_rv;
        assert(rv == i);
    }
    p_rv = (int *) cstl_array_front(myArray);
    rv = *(int*)p_rv;
    assert(rv == 0);

    p_rv = (int *) cstl_array_back(myArray);
    rv = *(int*)p_rv;
    assert(rv == (int)(size - 1));

    cstl_array_remove_from(myArray, 0);
    assert(size - 1 == cstl_array_size(myArray));
    p_rv = (int *) cstl_array_element_at(myArray, 0);
    rv = *(int*)p_rv;
    assert(rv == 1);

    size = cstl_array_size(myArray);
    cstl_array_remove_from(myArray, size / 2);
    assert(size - 1 == cstl_array_size(myArray));
    p_rv = (int *) cstl_array_element_at(myArray, size / 2);
    rv = *(int*)p_rv;
    assert((size_t)rv == size / 2 + 2);

    size = cstl_array_size(myArray);
    cstl_array_remove_from(myArray, size - 1);
    assert(size - 1 == cstl_array_size(myArray));
    size = cstl_array_size(myArray);
    p_rv = (int *) cstl_array_element_at(myArray, size - 1);
    rv = *(int*)p_rv;
    assert(rv == 8);

    i = 900;
    cstl_array_insert_at(myArray, 5, &i, sizeof(int));
    p_rv = (int *) cstl_array_element_at(myArray, 5);
    rv = *(int*)p_rv;
    assert(rv == i);

    p_rv = (int *) cstl_array_element_at(myArray, 6);
    rv = *(int*)p_rv;
    assert(rv == 7);

    for (i = 0; i < (int) cstl_array_size(myArray); i++) {
        p_rv = (int *) cstl_array_element_at(myArray, (size_t)i);
        print_e(p_rv);
    }

    cstl_array_delete(myArray);
}

void stl_dynamic_array()
{
    size_t size = 10;
    int i = 0;
    int *rv;
    int **p_rv = (int **)0;
    struct cstl_array* myArray = cstl_array_new(8, compare_e_ptr, free_e);
    assert(cstl_true == cstl_array_empty(myArray));

    for (i = 0; i < (int)size; i++) {
        int *v = (int*)calloc(1, sizeof(int));
        *v = i;
        cstl_array_push_back(myArray, &v, sizeof(int*));
    }
    assert(cstl_false == cstl_array_empty(myArray));
    assert(size == cstl_array_size(myArray));
    for (i = 0; i < (int)size; i++) {
        p_rv = (int **) cstl_array_element_at(myArray, i);
        rv = *((int**)p_rv);
        assert(*rv == i);
    }
    p_rv = (int **) cstl_array_front(myArray);
    rv = *((int**)p_rv);
    assert(*rv == 0);

    p_rv = (int **) cstl_array_back(myArray);
    rv = *((int**)p_rv);
    assert(*rv == (int)size - 1);

    cstl_array_remove_from(myArray, 0);
    assert(size - 1 == cstl_array_size(myArray));

    p_rv = (int **) cstl_array_element_at(myArray, 0);
    rv = *((int**)p_rv);
    assert(*rv == 1);

    size = cstl_array_size(myArray);
    cstl_array_remove_from(myArray, size / 2);
    assert(size - 1 == cstl_array_size(myArray));
    p_rv = (int **) cstl_array_element_at(myArray, size / 2);
    rv = *((int**)p_rv);
    assert((size_t)*rv == size / 2 + 2);

    size = cstl_array_size(myArray);
    cstl_array_remove_from(myArray, size - 1);
    assert(size - 1 == cstl_array_size(myArray));

    size = cstl_array_size(myArray);

    p_rv = (int **) cstl_array_element_at(myArray, size - 1);
    rv = *((int**)p_rv);
    assert(*rv == 8);

    cstl_array_delete(myArray);
}

void stl_strings_array()
{
    size_t size = 10;
    char *input_array[11];
    int i = 0;
    char *rv;
    char **p_rv = (char **)0;
    struct cstl_array* myArray = cstl_array_new(8, compare_e_str, free_e);
    assert(cstl_true == cstl_array_empty(myArray));

    input_array[0] = "STRING_0";
    input_array[1] = "STRING_1";
    input_array[2] = "STRING_2";
    input_array[3] = "STRING_3";
    input_array[4] = "STRING_4";
    input_array[5] = "STRING_5";
    input_array[6] = "STRING_6";
    input_array[7] = "STRING_7";
    input_array[8] = "STRING_8";
    input_array[9] = "STRING_9";
    input_array[10] = "STRING_10";

    for (i = 0; i < (int)size; i++) {
        char *v = cstl_strdup(input_array[i]);
        cstl_array_push_back(myArray, &v, sizeof(char *));
    }
    assert(cstl_false == cstl_array_empty(myArray));
    assert(size == cstl_array_size(myArray));
    for (i = 0; i < (int)size; i++) {
        p_rv = (char **) cstl_array_element_at(myArray, i);
        rv = *((char**)p_rv);
        assert(strcmp(rv, input_array[i]) == 0);
    }
    p_rv = (char **) cstl_array_front(myArray);
    rv = *((char**)p_rv);
    assert(strcmp(rv, input_array[0]) == 0);

    p_rv = (char **) cstl_array_back(myArray);
    rv = *((char**)p_rv);
    assert(strcmp(rv, input_array[size - 1]) == 0);

    cstl_array_remove_from(myArray, 0);
    assert(size - 1 == cstl_array_size(myArray));

    p_rv = (char **) cstl_array_element_at(myArray, 0);
    rv = *((char**)p_rv);
    assert(strcmp(rv, input_array[1]) == 0);

    size = cstl_array_size(myArray);
    cstl_array_remove_from(myArray, size / 2);

    p_rv = (char **) cstl_array_element_at(myArray, size / 2);
    rv = *((char**)p_rv);
    assert(strcmp(rv, input_array[size / 2 + 2]) == 0);

    size = cstl_array_size(myArray);
    cstl_array_remove_from(myArray, size - 1);
    assert(size - 1 == cstl_array_size(myArray));
    size = cstl_array_size(myArray);

    p_rv = (char **) cstl_array_element_at(myArray, size - 1);
    rv = *((char**)p_rv);
    assert(strcmp(rv, input_array[8]) == 0);

    cstl_array_delete(myArray);
}