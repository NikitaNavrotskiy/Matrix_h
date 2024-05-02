#include "my_matrix.h"

int my_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;

  if (!is_rows_and_cols_correct(rows, columns)) return INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (!result->matrix) flag = INCORRECT_MATRIX;
  for (int i = 0; i < rows && flag == OK; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (!result->matrix[i]) flag = INCORRECT_MATRIX;
  }

  if (flag == INCORRECT_MATRIX) safety_remove_matrix(rows, columns, result);

  return flag;
}