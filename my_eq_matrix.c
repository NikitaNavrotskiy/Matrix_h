#include <math.h>

#include "my_matrix.h"

int my_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;

  if (can_sub_sum_eq(A, B) != OK) return FAILURE;

  for (int i = 0; i < A->rows && result == SUCCESS; i++)
    for (int j = 0; j < A->columns && result == SUCCESS; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EQ_EPS) result = FAILURE;
    }

  return result;
}