#include "test.h"

START_TEST(my_eq_test_1) {
  matrix_t A = {0};
  my_create_matrix(2, 3, &A);
  A.matrix[0][0] = 2.24252;
  A.matrix[0][1] = 14.42564;
  A.matrix[0][2] = 2.22221;
  A.matrix[1][0] = 1.11111;
  A.matrix[1][1] = 23141.123124;
  A.matrix[1][2] = 6.3531;

  ck_assert_int_eq(my_eq_matrix(&A, &A), SUCCESS);
  my_remove_matrix(&A);
}

START_TEST(my_eq_test_2) {
  matrix_t A = {0}, B = {0};
  my_create_matrix(2, 4, &A);
  my_create_matrix(2, 3, &B);
  ck_assert_int_eq(my_eq_matrix(&A, &B), FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}

START_TEST(my_eq_test_3) {
  matrix_t A = {0}, B = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &B);
  A.matrix[0][0] = 2.24252452, A.matrix[0][1] = 14.42564452;
  A.matrix[0][2] = 2.22224514, A.matrix[1][0] = 1.11114515;
  A.matrix[1][1] = 241.123124544, A.matrix[1][2] = 6.35345121;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) B.matrix[i][j] = A.matrix[i][j] - 1e-8;

  ck_assert_int_eq(my_eq_matrix(&A, &B), SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}

START_TEST(my_eq_test_4) {
  matrix_t A = {0}, B = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(2, 3, &B);
  A.matrix[0][0] = 2.24252452, A.matrix[0][1] = 14.42564452;
  A.matrix[0][2] = 2.22224514, A.matrix[1][0] = 1.11114515;
  A.matrix[1][1] = 241.123124544, A.matrix[1][2] = 6.35345121;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) B.matrix[i][j] = A.matrix[i][j] - 1e-6;

  ck_assert_int_eq(my_eq_matrix(&A, &B), FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}

START_TEST(my_eq_test_5) {
  matrix_t A = {0}, B = {0};
  my_create_matrix(2, 3, &A);
  my_create_matrix(3, 3, &B);
  A.matrix[0][0] = 2.24252452, A.matrix[0][1] = 14.42564452;
  A.matrix[0][2] = 2.22224514, A.matrix[1][0] = 1.11114515;
  A.matrix[1][1] = 241.123124544, A.matrix[1][2] = 6.35345121;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) B.matrix[i][j] = A.matrix[i][j] - 1e-08;
  B.matrix[2][0] = 0;
  B.matrix[2][1] = 0;
  B.matrix[2][2] = 0;
  ck_assert_int_eq(my_eq_matrix(&A, &B), FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}

Suite *suite_my_eq() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_eq_matrix");
  tc = tcase_create("case_eq_matrix");

  tcase_add_test(tc, my_eq_test_1);
  tcase_add_test(tc, my_eq_test_2);
  tcase_add_test(tc, my_eq_test_3);
  tcase_add_test(tc, my_eq_test_4);
  tcase_add_test(tc, my_eq_test_5);

  suite_add_tcase(s, tc);
  return s;
}
