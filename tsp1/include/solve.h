#pragma once
#include "./../include/city.h"

double solve(const City *city, int n, int *route, int *visited);

double count_sum_distance(const City* city, int n, int* route);

int** make_first_trial(int n, int trial_time);

void copy_int_array(int* f, int* t, int n);

void swap(int* a, int* b);