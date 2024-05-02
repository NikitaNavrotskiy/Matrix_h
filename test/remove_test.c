#include "test.h"

START_TEST(my_remove_test_1) {
  matrix_t A = {0};
  int res = my_create_matrix(4, 5, &A);
  if (res == OK) {
    my_remove_matrix(&A);
    ck_assert_int_eq(A.rows == 0 && A.columns == 0 && A.matrix == NULL, 1);
  }
}

Suite *suite_my_remove() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_remove_matrix");
  tc = tcase_create("case_remove_matrix");

  tcase_add_test(tc, my_remove_test_1);

  suite_add_tcase(s, tc);
  return s;
}