#ifndef __INDEXHEAP__
#define __INDEXHEAP__
#include<utility>
using namespace std;
template <typename T>
class IndexHeap{
    private:
    T *data;
    int *index;
    int capacity;
    int len;
    //2*k+1 2*k+2
    void __shiftdown(T arr[], int index[], int len, int k){
        while(2*k+1 < len){
            int max = 2*k+1;
            if(2*k+2 < len && arr[index[2*k+2]] > arr[index[2*k+1]]){
                max = 2*k+2;
            }
            if(arr[index[max]] > arr[index[k]]){
                swap(index[max], index[k]);
                k = max;
            }else break;
        }
    }
    public:
    IndexHeap(T arr[], int len){
        this->len = len;
        capacity = len;
        index = new int[len];
        data = new T[len];
        for(int i = 0; i < len ; i++){
            index[i] = i;
        }
        for(int i = 0; i < len ; i++){
            data[i] = arr[i];
        }
        for(int j = (len - 2)/2 ; j >= 0 ; j--){
            __shiftdown(arr , index, len, j);
        }
        for(int k = len -1 ; k > 0 ; k--){
            swap(index[0] , index[k]);
            __shiftdown(arr, index, k , 0 );
        }

    }
    ~IndexHeap(){
        delete[] data;
        delete[] index;
    }
    int* Index(){
        return index;
    }
    int* Data(){
        return data;
    }
};
#endif