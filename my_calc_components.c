#include "my_matrix.h"

int my_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (check_correct_alloc_matrix(A->rows, A->columns, A) != OK)
    return CALCULATION_ERROR;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  if (my_create_matrix(A->rows, A->columns, result) != OK)
    res = CALCULATION_ERROR;
  else {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        double det = 0.0;
        my_minor_matrix(A, i + 1, j + 1, &minor);
        my_determinant(&minor, &det);
        result->matrix[i][j] = pow(-1, i + j) * det;
        my_remove_matrix(&minor);
      }
  }

  return res;
}