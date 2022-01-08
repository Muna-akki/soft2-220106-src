#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "./../include/city.h"
#include "./../include/map.h"
#include "./../include/solve.h"

double solve(const City *city, int n, int *route, int *visited)
{
    int trial_time = 1000; //初期解の個数
    route[0] = 0; // 循環した結果を避けるため、常に0番目からスタート
    visited[0] = 1;
    
    int** trial = make_first_trial(n,trial_time); //初期解の生成
    
    int ex_trial[n]; //ほぼ使い捨ての中身
    int reference[n]; //こちらを更新してtrial[i]をとっておく
    
    double ans = count_sum_distance(city, n, trial[0]);
    copy_int_array(trial[0],route,n);
    
    for(int i=0 ; i<trial_time ; i++){ //i個目の初期解についての試行
        int check = 1;
        while(check == 1){
            check = 0;
            double sum = count_sum_distance(city, n, trial[i]);
            copy_int_array(trial[i],reference,n);
            copy_int_array(trial[i],ex_trial,n);
            //どの二つを入れ替えるか
            for(int j=1 ; j<n-2 ; j++){
                for(int k=j+1 ; k<n-1 ; k++){
                    swap(&ex_trial[j], &ex_trial[k]);
                    double ex_sum = count_sum_distance(city, n, ex_trial);
                    if(ex_sum<sum){
                        copy_int_array(ex_trial,reference,n);
                        sum = ex_sum;
                        check = 1;
                    }
                    swap(&ex_trial[j], &ex_trial[k]);
                }
            }
            if(check == 1){
                copy_int_array(reference,trial[i],n);
            }
            if(ans>sum){
                copy_int_array(reference,route,n);
                ans = sum;
            }
        }
        
    }

    return ans;
}

// トータルの巡回距離を計算する
double count_sum_distance(const City* city, int n, int* route){
    double sum_d = 0;
    for(int i=0 ; i<n ; i++){
        const int c0 = route[i];
        const int c1 = route[(i+1)%n]; // nは0に戻る
        sum_d += distance(city[c0],city[c1]);
    }
    return sum_d;
}

int** make_first_trial(int n, int trial_time){
    srand(time(NULL));
    int **trial = (int**) malloc(trial_time * sizeof(int*));
    int *tmp = (int*)malloc(trial_time*n*sizeof(int));
    for (int i = 0 ; i < trial_time ; i++){
        trial[i] = tmp + i * n;
    }
    int check[n];
    int count;
    for(int i=0 ; i<trial_time ; i++){
        for(int j=0 ; j<n ; j++){
            check[j] = 0; 
        }
        count = 1;
        trial[i][0] = 0;
        check[0] = 1;
        while(count!=n){
            int k = rand()%n;
            if(check[k]==0){
                trial[i][count] = k;
                count++;
                check[k] = 1;
            }
        }
    }
    return trial;
}

void copy_int_array(int* f, int* t, int n){ //fをtにコピー
    for(int i=0 ; i<n ; i++){
        t[i] = f[i];
    }
}

void swap(int* a, int* b){
    int f = *a;
    int s = *b;
    *b = f;
    *a = s;
}


