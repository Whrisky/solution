//
// Created by yym on 2018/4/10.
//

#include <cstdlib>
#include <ctime>
#include <utility>
#include <iostream>

#ifndef EXERCISE_RANDOMARRAY_H
#define EXERCISE_RANDOMARRAY_H

#endif //EXERCISE_RANDOMARRAY_H
using  std::string;
namespace ArrayHelper{
    //[range_l , range_r]
    int* array_random(int range_l ,int range_r , int size){
        int* ret = new int[size];
        srand(time(NULL));
        for(int i = 0 ; i < size ; i ++){
            ret[i] = rand() % (range_r - range_l + 1) + range_l;
        }

        return ret;


    }

    void select_sort(int arr[] , int arr_len){
        for(int i = 0; i < arr_len - 1; i ++){
            int min_index = i + 1;
            for (int j = min_index ; j < arr_len ;j ++){
                if(arr[i] > arr[j])
                    std::swap(arr[i] , arr[j]);
            }
        }
    
    }

    void insert_sort(int arr[] , int arr_len){
        for(int i =0 ; i < arr_len ; i ++){
            int max_index = i + 1;
            for(int j = max_index ; j > 0 ; j -- ){
                    if(arr[i] > arr[j])
                        std :: swap(arr[i] , arr[j]);
            }
        }
    }

    template<typename T>
     double test_time (string name , void ( *sort)(T[] , int), T arr[] , int n){
            clock_t start_time = clock();
            sort(arr , n);
            clock_t end_time = clock();
            double time = double(end_time - start_time) / CLOCKS_PER_SEC;
            return time ;


     }

    template <typename T>
     bool is_sorted (T arr[] ,int arr_len){
        //[0, arr-1), [1,arr)
        for(auto i = 0; i < arr_len - 1; i ++ ){
            if(arr[i] > arr[i +1]) return false;
        }
        return true;
     }
};
