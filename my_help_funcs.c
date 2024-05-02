#include "my_matrix.h"

int is_rows_and_cols_correct(int rows, int cols) {
  int res = 1;

  if (rows < 1 || cols < 1) res = 0;

  return res;
}

int check_correct_alloc_matrix(int rows, int cols, matrix_t *matrix) {
  int res = OK;
  if (!is_rows_and_cols_correct(rows, cols) || !matrix)
    res = INCORRECT_MATRIX;
  else if (!matrix->matrix)
    res = INCORRECT_MATRIX;
  else {
    for (int i = 0; i < rows && res == OK; i++) {
      if (!matrix->matrix[i]) res = INCORRECT_MATRIX;
    }
  }

  return res;
}

int safety_remove_matrix(int rows, int cols, matrix_t *matrix) {
  int res = OK;

  if (is_rows_and_cols_correct(rows, cols) && matrix->matrix) {
    for (int i = 0; i < rows; i++) {
      if (matrix->matrix[i]) free(matrix->matrix[i]);
    }
  }

  return res;
}

int can_sub_sum_eq(matrix_t *A, matrix_t *B) {
  int res = OK;
  int flagA = OK;
  int flagB = OK;
  if (A->rows != B->rows || A->columns != B->columns) res = INCORRECT_MATRIX;

  flagA = check_correct_alloc_matrix(A->rows, A->columns, A);
  flagB = check_correct_alloc_matrix(B->rows, B->columns, B);

  if (flagA != OK || flagB != OK) res = INCORRECT_MATRIX;

  return res;
}

int can_mult(matrix_t *A, matrix_t *B) {
  int res = OK;
  int flagA = OK;
  int flagB = OK;

  flagA = check_correct_alloc_matrix(A->rows, A->columns, A);
  flagB = check_correct_alloc_matrix(B->rows, B->columns, B);

  if (flagA != OK || flagB != OK || A->columns != B->rows)
    res = INCORRECT_MATRIX;

  return res;
}