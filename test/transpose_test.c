#include "test.h"

START_TEST(my_transpose_test_1) {
  matrix_t A = {0}, res = {0}, expect = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(3, 2, &expect);
  A.matrix[0][0] = 2.24252, A.matrix[0][1] = 14.42564;
  A.matrix[0][2] = 2.22221, A.matrix[1][0] = 1.11111;
  A.matrix[1][1] = 23141.123124, A.matrix[1][2] = 6.3531;

  expect.matrix[0][0] = 2.24252, expect.matrix[1][0] = 14.42564;
  expect.matrix[2][0] = 2.22221, expect.matrix[0][1] = 1.11111;
  expect.matrix[1][1] = 23141.123124, expect.matrix[2][1] = 6.3531;

  my_transpose(&A, &res);

  ck_assert_int_eq(my_eq_matrix(&res, &expect), SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
}

START_TEST(my_transpose_test_2) {
  int ret = 0;
  matrix_t A = {0}, res = {0}, expect = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(3, 2, &expect);
  A.matrix[0][0] = 2.24252, A.matrix[0][1] = 14.42564;
  A.matrix[0][2] = 2.22221, A.matrix[1][0] = 1.11111;
  A.matrix[1][1] = 23141.123124, A.matrix[1][2] = 6.3531;

  expect.matrix[0][0] = 2.24252, expect.matrix[1][0] = 14.42564;
  expect.matrix[2][0] = 2.22221, expect.matrix[0][1] = 1.11111;
  expect.matrix[1][1] = 23141.123124, expect.matrix[2][1] = 6.3531;
  A.columns = -1;
  ret = my_transpose(&A, &res);
  A.columns = 2;

  ck_assert_int_eq(ret, CALCULATION_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
}

Suite *suite_my_transpose() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_transpose_matrix");
  tc = tcase_create("case_transpose_matrix");

  tcase_add_test(tc, my_transpose_test_1);
  tcase_add_test(tc, my_transpose_test_2);

  suite_add_tcase(s, tc);
  return s;
}
