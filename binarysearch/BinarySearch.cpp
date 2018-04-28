#include <iostream>
#include "ArrayHelper.h"

// [0,len)  [l,size/2), size/2 [size/2+1, r) 
template <typename T>
int BinarySearch(T elem, T arr[], int len){
    int l = 0;
    int r = len;
    int size = r - l;
    int k = size /2;
    int i = 3;
    while(k>=0 && k<len && size > 0){
    std::cout<< l<<" | "<<r<<" | "<<k<<"\n" ;
        if(elem > arr[k]){
            l = k + 1;
            size = r - l;
            k = l+size/2;
        }else if(elem < arr[k]){
            r = k;
            size = r - l;
            k = l+size/2;
        }else return k;

    }
    return -1;
}
 int main(){
    int arr_len = 10;
    int *res = ArrayHelper::array_random(1, 20, arr_len);
    
    for (int i = 0; i < arr_len; i++)
    {
        std::cout << res[i] << " ";

    }
    std::cout << "start sort" << std::endl;
    int search_locate = 3;
    auto time = ArrayHelper::test_time("merge sort", ArrayHelper::insert_sort, res, arr_len);

    for (int i = 0; i < arr_len; i++)
    {   
        std::cout <<res[i] << " ";
    }
    std :: cout <<"\n";
    std ::cout<< "num:"<<  6 <<"\n";
    int ret = BinarySearch(6, res, arr_len);
    std::cout<<ret<<"\n";
    delete[] res;

    return 0;
 }