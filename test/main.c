#include "test.h"

void copy_array_to_matrix(double *arr, matrix_t *A) {
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      A->matrix[i][j] = arr[i * A->columns + j];
}

int main() {
  run_tests();
  return 0;
}

void run_tests() {
  Suite *list[] = {suite_my_create(),      suite_my_remove(),
                   suite_my_sum(),         suite_my_sub(),
                   suite_my_eq(),          suite_my_transpose(),
                   suite_my_mult_number(), suite_my_mult_matrix(),
                   suite_my_determinant(), suite_my_calc_components(),
                   suite_my_inverse(),     NULL};

  for (Suite **cur = list; *cur; cur++) run_one_test(*cur);
}

void run_one_test(Suite *test) {
  SRunner *sr = srunner_create(test);
  srunner_set_fork_status(sr, CK_FORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}