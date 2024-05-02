#include "my_matrix.h"

int my_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ret = OK;
  double det = 0.0;

  if (check_correct_alloc_matrix(A->rows, A->columns, A) != OK ||
      A->rows != A->columns)
    return CALCULATION_ERROR;

  my_determinant(A, &det);

  if (fabs(det) < EQ_EPS)
    ret = CALCULATION_ERROR;
  else {
    if (my_create_matrix(A->rows, A->columns, result) != OK)
      ret = CALCULATION_ERROR;
    else {
      matrix_t comp = {0}, trans = {0};
      my_calc_complements(A, &comp);
      my_transpose(&comp, &trans);
      for (int i = 0; i < result->rows; i++)
        for (int j = 0; j < result->columns; j++)
          result->matrix[i][j] = trans.matrix[i][j] / det;
      my_remove_matrix(&comp);
      my_remove_matrix(&trans);
    }
  }

  return ret;
}