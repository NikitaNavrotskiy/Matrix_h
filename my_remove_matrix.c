#include "my_matrix.h"

void my_remove_matrix(matrix_t *A) {
  if (check_correct_alloc_matrix(A->rows, A->columns, A) == OK) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
    A->matrix = NULL;
  } else
    safety_remove_matrix(A->rows, A->columns, A);
}
