#include "test.h"

START_TEST(my_mult_matrix_test_1) {
  int r = 0;
  double arr1[] = {-2.0, 3.0, 1.0};
  double arr2[] = {2.0, -4.0, 1.0, 1.0, -3.0, 2.0};
  matrix_t A = {0}, B = {0}, res = {0}, expect = {0};
  my_create_matrix(1, 3, &A);
  my_create_matrix(3, 2, &B);
  my_create_matrix(1, 2, &expect);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(arr2, &B);
  expect.matrix[0][0] = -4.0;
  expect.matrix[0][1] = 13.0;
  my_mult_matrix(&A, &B, &res);
  r = my_eq_matrix(&expect, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
  ck_assert_int_eq(r, SUCCESS);
}

START_TEST(my_mult_matrix_test_2) {
  int r = 0;
  double arr1[] = {2.34234, 4.535, 245.6332};
  double arr2[] = {5.3994, 6.2111, 123.6987, 6.312};
  matrix_t A = {0}, B = {0}, res = {0};
  my_create_matrix(1, 3, &A);
  my_create_matrix(2, 2, &B);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(arr2, &B);

  r = my_mult_matrix(&A, &B, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  ck_assert_int_eq(r, CALCULATION_ERROR);
}

START_TEST(my_mult_matrix_test_3) {
  int r = 0;
  double arr1[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  double arr2[] = {5.3994, 6.2111, 123.6987, 6.312, 857.8, 9.2341};
  matrix_t A = {0}, B = {0}, res = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &B);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(arr2, &B);
  A.columns = -5;
  r = my_mult_matrix(&A, &B, &res);
  A.columns = 2;
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  ck_assert_int_eq(r, CALCULATION_ERROR);
}

Suite *suite_my_mult_matrix() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_mult__matrix");
  tc = tcase_create("case_mult_matrix");

  tcase_add_test(tc, my_mult_matrix_test_1);
  tcase_add_test(tc, my_mult_matrix_test_2);
  tcase_add_test(tc, my_mult_matrix_test_3);

  suite_add_tcase(s, tc);
  return s;
}