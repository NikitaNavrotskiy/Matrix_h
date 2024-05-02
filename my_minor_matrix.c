#include "my_matrix.h"

int my_minor_matrix(matrix_t *A, int row, int col, matrix_t *result) {
  int res = OK;
  row--;
  col--;

  if (row > A->rows || col > A->columns || row < 0 || col < 0)
    return INCORRECT_MATRIX;

  if (my_create_matrix(A->rows - 1, A->columns - 1, result) != OK)
    res = CALCULATION_ERROR;
  else {
    for (int i = 0, i_r = 0; i < A->rows; i++) {
      if (row != i) {
        for (int j = 0, j_r = 0; j < A->columns; j++) {
          if (col != j) {
            result->matrix[i_r][j_r] = A->matrix[i][j];
            j_r++;
          }
        }
        i_r++;
      }
    }
  }

  return res;
}