#include "my_matrix.h"

int my_determinant(matrix_t *A, double *result) {
  int res = OK;
  double det = 0.0;

  if (A->rows < 1 || A->columns < 1 || A->rows != A->columns)
    return CALCULATION_ERROR;

  if (A->rows == 1)
    det = A->matrix[0][0];
  else {
    int sign = 1;
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor = {0};
      my_minor_matrix(A, i + 1, 1, &minor);
      double loc_res = 0.0;
      my_determinant(&minor, &loc_res);
      det += sign * A->matrix[i][0] * loc_res;
      sign *= -1;
      my_remove_matrix(&minor);
    }
  }

  *result = det;
  return res;
}