#include "my_matrix.h"

int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;

  if (can_mult(A, B) != OK) return CALCULATION_ERROR;

  if (my_create_matrix(A->rows, B->columns, result) == INCORRECT_MATRIX)
    res = CALCULATION_ERROR;
  else {
    for (int i = 0; i < result->rows; i++)
      for (int j = 0; j < result->columns; j++) result->matrix[i][j] = 0;

    for (int i = 0; i < result->rows; i++)
      for (int j = 0; j < result->columns; j++)
        for (int k = 0; k < A->columns; k++)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  }

  return res;
}