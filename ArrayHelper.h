//
// Created by yym on 2018/4/10.
//
#ifndef _ARRAYHELPER_
#define _ARRAYHELPER_

#include <cstdlib>
#include <ctime>
#include <utility>
#include <iostream>
#include <vector>


#ifndef EXERCISE_RANDOMARRAY_H
#define EXERCISE_RANDOMARRAY_H

#endif //EXERCISE_RANDOMARRAY_H
using namespace std;
using std::string;
using std::vector;
namespace ArrayHelper{

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
        for(int i = 1 ; i < arr_len ; i ++){
            int max_index = i;
            for(int j = max_index ; j > 0 ; j -- ){
                    if(arr[j-1] > arr[j])
                        std :: swap(arr[j] , arr[j-1]);
            }
        }
    }
    //[l+1,i) [i,j)
    int _partition(int arr[], int l, int r){
        srand(time(NULL));
        int sr = rand()%(r  - l) + l;
        swap(arr[l], arr[sr]);
        int p = arr[l];
        int i = l + 1, j = l + 1;
        for(int k = l+1 ; k < r; k++){
            if(arr[k] < p){
                swap(arr[i], arr[k]);
                i ++ ;
                j ++ ;
            }else{
                j ++ ;
            }
        }
        // [l,i-1) p [i,r)
        swap(arr[i-1], arr[l]);
        return i-1;
    }
//[l, p),
    void _quick_sort(int arr[], int l , int r){
        if(r - l <= 1) return;
        int p = _partition(arr , l , r);
        _quick_sort(arr, l , p);
        _quick_sort(arr, p+1, r);
    }
    void quick_sort(int arr[], int arr_len){
        _quick_sort(arr , 0, arr_len);
    
    
    }
     //[l,i),(j, r),[l, r) [l, lt)<p ,[gt, r)>p, [lt, gt)=p
    // vector<int> __patition_threepath(int arr[], int l , int r){
    //     int p = arr[l];
    //     int i = l+1 ,j = r-1;
    //     int lt = l, gt = j;
    //     while(true){
    //         while(i < r && arr[i] < p) {
    //             lt ++ ;
    //             i ++ ;
    //         }
    //         while(j >= l && arr[j] > p){
    //             gt -- ;
    //             j -- ;
    //         }
    //        if(arr[i] == p) i ++;
    //        else{    
    //             swap(arr[j] , arr[gt--]);
    //              i ++ ; 
    //        }
    //        if(arr[j] == p) j --;
    //        else{
    //            swap(arr[lt++] , arr[j]);
    //            j -- ;
    //        }
    //        if(i > j) break;
    //     }
    //     vector<int> v ;
    //     v.push_back(lt);
    //     v.push_back(gt);
    //     return v;
    // }

    //[l, lt)<p, [gt, r)>p
    vector<int> __patition_threepath(int arr[], int l , int r){

        int p = arr[l];
        int lt = l, gt = r;
        for(int i = l; i < gt; i ++){
            if(arr[i] < p) {
                swap(arr[lt], arr[i]);
                lt++;
                --i;
            }else if( arr[i] > p){
                swap(arr[i], arr[--gt]);
                --i;
            }
        }
        vector<int> v ;
        v.push_back(lt);
        v.push_back(gt);
        return v;
    }
    void _quick_sort_threepath(int arr[], int l, int r){
        if(r - l <= 1) return;
       vector<int> v =  __patition_threepath(arr , l, r);
       cout << v[0]<<"|" << v[1]<<"\n";
        for (int i= l; i<r;i++){
            std::cout<< arr[i]<< "\t";
        }
        std::cout<<"\n";
       _quick_sort(arr , l, v[0]);
       _quick_sort(arr, v[1] ,r); 

    }
    void quick_sort_threepath(int arr[], int arr_len){
       _quick_sort_threepath(arr , 0, arr_len); 
    }


    //[low,mid),[mid, hig) 分而治之，此为治
    void merge_process(int arr[] ,int low , int hig){
        if (low >= hig) return;
        int arr_len = hig -low;
        vector<int> tmp;
        int mid = low + arr_len / 2;
        int i = low;
        int j = mid;
        while(i < mid && j < hig){
            if (arr[i] < arr[j]){
                tmp.push_back(arr[i]);
                i ++;
            }else{
                tmp.push_back(arr[j]);
                j ++;
            }
        }
        while(i < mid){
            tmp.push_back(arr[i]);
            i ++ ;
        }
        while( j < hig){
            tmp.push_back(arr[j]);
            j ++ ;
        }

        for(auto x : tmp){
            std::cout << x<<",";
        }
        std::cout << std::endl;

        for(int k = low ; k < hig ; k++){
            arr[k] = tmp[k-low];
        }
    }

        //[low,mid),[mid, hig) 分而治之，此为治
    void merge_process2(int arr[] ,int low , int mid, int hig){
        if (low >= hig) return;
        int arr_len = hig -low;
        vector<int> tmp;
        int i = low;
        int j = mid;
        while(i < mid && j < hig){
            if (arr[i] < arr[j]){
                tmp.push_back(arr[i]);
                i ++;
            }else{
                tmp.push_back(arr[j]);
                j ++;
            }
        }
        while(i < mid){
            tmp.push_back(arr[i]);
            i ++ ;
        }
        while( j < hig){
            tmp.push_back(arr[j]);
            j ++ ;
        }

        for(auto x : tmp){
            std::cout << x<<",";
        }
        std::cout << std::endl;

        for(int k = low ; k < hig ; k++){
            arr[k] = tmp[k-low];
        }
    }
    // 分而治之，此为分
    void merge_divide(int arr[] , int arr_len , int partition){
        if (partition > arr_len ){
            return;
        }
        //[0,d)
        int division = arr_len / partition;
        
        for(int i = 0 ; i < division ; i ++ ){
            int low = i * partition;
            int hight = low + partition ;
            if(hight > arr_len){
                 hight = arr_len ;

            }
            merge_process(arr , low, hight);            
                // [low,hight)
        }
        if (arr_len % partition != 0){
           merge_process(arr,  partition*division, arr_len); 
        }
        merge_divide(arr, arr_len, partition*2);
        //if(partition < arr_len) merge_divide(arr , arr_len, partition * 2);
        
    }
    
    // [0, n) , log2 N , 
    void merge_divide2(int arr[] , int l , int h ){
        int len = h - l;
        if(len > 2){
            merge_divide2(arr , l , l + len/2);
            merge_divide2(arr , l + len/2 , h); 
            merge_process(arr , l , h);
        }else{
           merge_process(arr , l , h); 
        }
    }
    void merge_sort(int arr[] , int arr_len){
        merge_divide(arr , 0 , 2 );
        // merge_divide(arr , arr_len , 2);

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


    int *array_random(int range_l, int range_r, int size) {
	    int *ret = new int[size];
	    srand(time(NULL));
	    for (int i = 0; i < size; i++) {
	    	ret[i] = rand() % (range_r - range_l + 1) + range_l;
	    }
    
    	return ret;
    } 
}

#endif