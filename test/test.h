#ifndef _MY_MATRIX_TESTS_H
#define _MY_MATRIX_TESTS_H

#include <check.h>

#include "../my_matrix.h"

void run_one_test(Suite *test);
void run_tests();

void copy_array_to_matrix(double *arr, matrix_t *A);

Suite *suite_my_create();
Suite *suite_my_remove();
Suite *suite_my_sum();
Suite *suite_my_sub();
Suite *suite_my_eq();
Suite *suite_my_mult_matrix();
Suite *suite_my_transpose();
Suite *suite_my_mult_number();
Suite *suite_my_determinant();
Suite *suite_my_calc_components();
Suite *suite_my_inverse();

#endif