#include "my_matrix.h"

int my_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;

  if (check_correct_alloc_matrix(A->rows, A->columns, A) == INCORRECT_MATRIX)
    return CALCULATION_ERROR;

  if (my_create_matrix(A->rows, A->columns, result) == INCORRECT_MATRIX)
    res = CALCULATION_ERROR;
  else {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
  }

  return res;
}