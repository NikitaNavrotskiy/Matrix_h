#include "my_matrix.h"

int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (can_sub_sum_eq(A, B) == INCORRECT_MATRIX) return CALCULATION_ERROR;

  if (my_create_matrix(A->rows, A->columns, result) == INCORRECT_MATRIX)
    res = CALCULATION_ERROR;
  else {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }
  return res;
}