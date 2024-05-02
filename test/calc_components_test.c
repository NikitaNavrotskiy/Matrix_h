#include "test.h"

START_TEST(my_calc_components_test_1) {
  matrix_t A = {0}, res = {0}, expect = {0};
  double arr1[] = {3.0, 2.0, -1.0, -3.0, -4.0, 5.0, 1.0, -1.0, 1.0};
  double r[] = {1.0, 8.0, 7.0, -1.0, 4.0, 5.0, 6.0, -12.0, -6.0};
  my_create_matrix(3, 3, &A);
  my_create_matrix(3, 3, &expect);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(r, &expect);
  my_calc_complements(&A, &res);
  ck_assert_int_eq(my_eq_matrix(&res, &expect), SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
}

START_TEST(my_calc_components_test_2) {
  matrix_t A = {0}, res = {0};
  double arr1[] = {3.0, 2.0, -1.0, -3.0, -4.0, 5.0};
  my_create_matrix(2, 3, &A);
  copy_array_to_matrix(arr1, &A);
  int status = my_calc_complements(&A, &res);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  my_remove_matrix(&res);
  my_remove_matrix(&A);
}

START_TEST(my_calc_components_test_3) {
  matrix_t A = {0}, res = {0}, expect = {0};
  double arr1[] = {3.0, 2.0, -1.0, -3.0};
  double r[] = {-3.0, 1.0, -2.0, 3.0};
  my_create_matrix(2, 2, &A);
  my_create_matrix(2, 2, &expect);
  copy_array_to_matrix(arr1, &A);
  copy_array_to_matrix(r, &expect);
  my_calc_complements(&A, &res);
  ck_assert_int_eq(my_eq_matrix(&res, &expect), SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&expect);
}

START_TEST(my_calc_components_test_4) {
  matrix_t A = {0}, res = {0};
  double arr1[] = {3.0};
  my_create_matrix(1, 1, &A);
  copy_array_to_matrix(arr1, &A);
  my_calc_complements(&A, &res);
  ck_assert_double_eq_tol(res.matrix[0][0], 0.0, EQ_EPS);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
}

Suite *suite_my_calc_components() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_calc_components_matrix");
  tc = tcase_create("case_calc_components_matrix");

  tcase_add_test(tc, my_calc_components_test_1);
  tcase_add_test(tc, my_calc_components_test_2);
  tcase_add_test(tc, my_calc_components_test_3);
  tcase_add_test(tc, my_calc_components_test_4);

  suite_add_tcase(s, tc);
  return s;
}