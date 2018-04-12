#include <iostream>     // std::cout
#include "ArrayHelper.h"

int main() {

    int arr_len = 10;
    int *res = ArrayHelper::array_random(1,  20, arr_len);
    for(int i = 0 ; i < arr_len; i++){
        std::cout << res[i] << std::endl;
    }
    for(int i = 0 ; i < arr_len; i++){
        std::cout << res[i] << " ";
        
    }
    std::cout<< "start sort"<< std::endl;
    
    auto time = ArrayHelper::test_time("merge sort" , ArrayHelper::merge_sort, res , arr_len); 

    for(int i = 0 ; i < arr_len; i++){
        std::cout << res[i] << " ";

    }
    delete[] res;
    return 0;
}

