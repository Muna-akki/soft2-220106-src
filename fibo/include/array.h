#pragma once
#include <stdio.h>
#include <stdlib.h>

//行列群
typedef struct array{
    long a[4][100];
    long memo[100];
} Array;


Array* make_default(); //行列群の初期化

void advance_array(Array* ar, int n); //行列を進める
