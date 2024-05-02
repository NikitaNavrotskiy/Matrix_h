#include "test.h"

START_TEST(my_mult_number_test_1) {
  int r = 0;
  double num = 4.23;
  double arr[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  double res_arr[6] = {0};
  for (int i = 0; i < 6; i++) res_arr[i] = arr[i] * num;
  matrix_t A = {0}, res = {0}, expect = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &expect);
  copy_array_to_matrix(arr, &A);
  copy_array_to_matrix(res_arr, &expect);

  my_mult_number(&A, num, &res);
  r = my_eq_matrix(&expect, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
  ck_assert_int_eq(r, SUCCESS);
}

START_TEST(my_mult_number_test_2) {
  int r = 0;
  double num = 0;
  double arr[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  double res_arr[6] = {0};
  for (int i = 0; i < 6; i++) res_arr[i] = arr[i] * num;
  matrix_t A = {0}, res = {0}, expect = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &expect);
  copy_array_to_matrix(arr, &A);
  copy_array_to_matrix(res_arr, &expect);

  my_mult_number(&A, num, &res);
  r = my_eq_matrix(&expect, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
  ck_assert_int_eq(r, SUCCESS);
}

START_TEST(my_mult_number_test_3) {
  int r = 0;
  double num = -4.23;
  double arr[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  double res_arr[6] = {0};
  for (int i = 0; i < 6; i++) res_arr[i] = arr[i] * num;
  matrix_t A = {0}, res = {0}, expect = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &expect);
  copy_array_to_matrix(arr, &A);
  copy_array_to_matrix(res_arr, &expect);

  my_mult_number(&A, num, &res);
  r = my_eq_matrix(&expect, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
  ck_assert_int_eq(r, SUCCESS);
}

START_TEST(my_mult_number_test_4) {
  int r = 0;
  double num = -4.23;
  double arr[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  matrix_t A = {0}, res = {0};
  my_create_matrix(2, 3, &A);
  copy_array_to_matrix(arr, &A);
  A.columns = 0;
  r = my_mult_number(&A, num, &res);
  A.columns = 3;
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  ck_assert_int_eq(r, CALCULATION_ERROR);
}

Suite *suite_my_mult_number() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_mult_number_matrix");
  tc = tcase_create("case_mult_number_matrix");

  tcase_add_test(tc, my_mult_number_test_1);
  tcase_add_test(tc, my_mult_number_test_2);
  tcase_add_test(tc, my_mult_number_test_3);
  tcase_add_test(tc, my_mult_number_test_4);

  suite_add_tcase(s, tc);
  return s;
}