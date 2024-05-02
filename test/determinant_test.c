#include "test.h"

START_TEST(my_determinant_test_1) {
  matrix_t A = {0};
  double det = 0.0;
  double arr1[] = {3.0, 2.0, -1.0, -3.0, -4.0, 5.0, 1.0, -1.0, 1.0};
  my_create_matrix(3, 3, &A);
  copy_array_to_matrix(arr1, &A);
  my_determinant(&A, &det);
  ck_assert_double_eq_tol(det, 12.0, EQ_EPS);
  my_remove_matrix(&A);
}

START_TEST(my_determinant_test_2) {
  matrix_t A = {0};
  double det = 0.0;
  double arr1[] = {3.0, 2.0, -1.0, -3.0, -4.0, 5.0};
  my_create_matrix(2, 3, &A);
  copy_array_to_matrix(arr1, &A);
  int status = my_determinant(&A, &det);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  my_remove_matrix(&A);
}

START_TEST(my_determinant_test_3) {
  matrix_t A = {0};
  double det = 0.0;
  double arr1[] = {3.0, 2.0, -1.0, -3.0};
  my_create_matrix(2, 2, &A);
  copy_array_to_matrix(arr1, &A);
  my_determinant(&A, &det);
  ck_assert_double_eq_tol(det, -7.0, EQ_EPS);
  my_remove_matrix(&A);
}

START_TEST(my_determinant_test_4) {
  matrix_t A = {0};
  double det = 0.0;
  double arr1[] = {3.0};
  my_create_matrix(1, 1, &A);
  copy_array_to_matrix(arr1, &A);
  my_determinant(&A, &det);
  ck_assert_double_eq_tol(det, 3.0, EQ_EPS);
  my_remove_matrix(&A);
}

START_TEST(my_determinant_test_5) {
  matrix_t A = {0};
  double det = 0.0;
  double arr1[] = {3.0, 2.0, -1.0, -3.0, -4.0, 5.0,  1.0, -1.0,
                   1.0, 2.0, 10.0, -1.0, 4.0,  -4.0, 6.0, -7.0};
  my_create_matrix(4, 4, &A);
  copy_array_to_matrix(arr1, &A);
  my_determinant(&A, &det);
  ck_assert_double_eq_tol(det, -1897.0, EQ_EPS);
  my_remove_matrix(&A);
}

Suite *suite_my_determinant() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_determinant_matrix");
  tc = tcase_create("case_determinant_matrix");

  tcase_add_test(tc, my_determinant_test_1);
  tcase_add_test(tc, my_determinant_test_2);
  tcase_add_test(tc, my_determinant_test_3);
  tcase_add_test(tc, my_determinant_test_4);
  tcase_add_test(tc, my_determinant_test_5);

  suite_add_tcase(s, tc);
  return s;
}