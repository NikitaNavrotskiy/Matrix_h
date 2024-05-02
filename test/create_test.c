#include "test.h"

START_TEST(my_create_test_1) {
  matrix_t A = {0};
  int res = my_create_matrix(4, 5, &A);
  if (res == OK) ck_assert_int_eq(A.rows == 4 && A.columns == 5, 1);
  my_remove_matrix(&A);
}

START_TEST(my_create_test_2) {
  matrix_t A = {0};
  int res = my_create_matrix(-4, 5, &A);
  ck_assert_int_eq(res && !A.matrix, INCORRECT_MATRIX);
}

Suite *suite_my_create() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_create_matrix");
  tc = tcase_create("case_create_matrix");

  tcase_add_test(tc, my_create_test_1);
  tcase_add_test(tc, my_create_test_2);

  suite_add_tcase(s, tc);
  return s;
}