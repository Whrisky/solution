#ifndef __MAXHEAP__
#define __MAXHEAP__

#include <utility>



template <typename Item>
class MaxHeap{
    private:
    Item *data;
    int count;
    int capacity;
    void __shift_up(int i){
         while( i/2 >= 1 && data[i]> data[i/2]){
            std::swap(data[i], data[i/2]);
            i = i/2;
        }
    }
    //[1, count]
    void __shift_down(int k){
       while(k  <= count){
           int j;
           if(2*k+1 <= count ){
              
               if(data[2*k + 1] > data[2*k]){
                  j= 2*k+1;
               }else{
                   j = 2*k;
               }
           }else if(2*k <=count){
                 j = 2*k;
           }else break;
           if(data[k] < data[j]){
                swap(data[j], data[k]);
                k = j;
            }else break;
       }
    }
    public:
    MaxHeap(int cabacity){
    // :capacity(cabacity) , count(0), data(new Item[cabacity + 1]){
        this->capacity = cabacity;
        count = 0;
        data = new Item[cabacity + 1];
    };
    ~MaxHeap(){
        delete[] data;
    }
    int size(){
        return count;
    }
    bool is_empty(){
        return count == 0;
    }
    // [1, count]
    void insert(Item item){
        assert(count+1 <= capacity);
        int i = ++count;
        data[i] = item;
        __shift_up(count);
    }
    Item extractMax(){
        assert(count > 0);
        Item res = data[1];
        swap(data[1], data[count]);
        count--;
        __shift_down(1);
        return res;
    }

    
};
#endif