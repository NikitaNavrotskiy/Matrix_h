#ifndef _MY_MATRIX_H
#define _MY_MATRIX_H

#include <math.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

int my_create_matrix(int rows, int columns, matrix_t *result);

void my_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0

#define EQ_EPS 1e-07

int my_eq_matrix(matrix_t *A, matrix_t *B);

int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int my_mult_number(matrix_t *A, double number, matrix_t *result);

int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int my_transpose(matrix_t *A, matrix_t *result);

int my_calc_complements(matrix_t *A, matrix_t *result);

int my_determinant(matrix_t *A, double *result);

int my_inverse_matrix(matrix_t *A, matrix_t *result);

int my_minor_matrix(matrix_t *A, int row, int col, matrix_t *result);

int is_rows_and_cols_correct(int rows, int cols);

int check_correct_alloc_matrix(int rows, int cols, matrix_t *matrix);

int safety_remove_matrix(int rows, int cols, matrix_t *matrix);

int can_sub_sum_eq(matrix_t *A, matrix_t *B);

int can_mult(matrix_t *A, matrix_t *B);

#endif