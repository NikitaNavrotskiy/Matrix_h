#include "test.h"

START_TEST(my_sub_test_1) {
  int r = 0;
  double arr1[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  double arr2[] = {5.3994, 6.2111, 123.6987, 6.312, 857.8, 9.2341};
  double res_arr[6] = {0};
  for (int i = 0; i < 6; i++) res_arr[i] = arr1[i] - arr2[i];
  matrix_t A = {0}, B = {0}, res = {0}, expect = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &B);
  my_create_matrix(2, 3, &expect);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(arr2, &B);
  copy_array_to_matrix(res_arr, &expect);

  my_sub_matrix(&A, &B, &res);
  r = my_eq_matrix(&expect, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
  ck_assert_int_eq(r, SUCCESS);
}

START_TEST(my_sub_test_2) {
  int r = 0;
  double arr1[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  double arr2[] = {5.3994, 6.2111, 123.6987, 6.312};
  matrix_t A = {0}, B = {0}, res = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 2, &B);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(arr2, &B);

  r = my_sub_matrix(&A, &B, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  ck_assert_int_eq(r, CALCULATION_ERROR);
}

START_TEST(my_sub_test_3) {
  int r = 0;
  double arr1[] = {2.34234, 4.535, 245.6332, 6.666, 7.777, 8.8633};
  double arr2[] = {5.3994, 6.2111, 123.6987, 6.312, 857.8, 9.2341};
  double res_arr[6] = {0};
  for (int i = 0; i < 6; i++) res_arr[i] = arr1[i] - arr2[i];
  matrix_t A = {0}, B = {0}, res = {0}, expect = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &B);
  my_create_matrix(2, 3, &expect);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(arr2, &B);
  copy_array_to_matrix(res_arr, &expect);
  A.columns = -5;
  r = my_sub_matrix(&A, &B, &res);
  A.columns = 2;
  my_eq_matrix(&expect, &res);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
  ck_assert_int_eq(r, CALCULATION_ERROR);
}

Suite *suite_my_sub() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_sub_matrix");
  tc = tcase_create("case_sub_matrix");

  tcase_add_test(tc, my_sub_test_1);
  tcase_add_test(tc, my_sub_test_2);
  tcase_add_test(tc, my_sub_test_3);

  suite_add_tcase(s, tc);
  return s;
}