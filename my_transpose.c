#include "my_matrix.h"

int my_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (check_correct_alloc_matrix(A->rows, A->columns, A) != OK)
    res = CALCULATION_ERROR;

  if (my_create_matrix(A->columns, A->rows, result) != OK)
    res = CALCULATION_ERROR;
  else {
    for (int i = 0; i < result->rows; i++)
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[j][i];
  }

  return res;
}