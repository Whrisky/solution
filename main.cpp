#include <iostream> // std::cout
#include "ArrayHelper.h"
#include "MaxHeap.h"
int main()
{
    
    int arr_len = 10;
    int *res = ArrayHelper::array_random(1, 20, arr_len);
    MaxHeap<int> heap = MaxHeap<int>(100);
    for (int i = 0; i < arr_len; i++)
    {
        heap.insert(res[i]);
        std::cout << res[i] << " ";

    }
    std::cout << "start sort" << std::endl;
   

    // auto time = ArrayHelper::test_time("merge sort", ArrayHelper::quick_sort_threepath, res, arr_len);

    for (int i = 0; i < arr_len; i++)
    {   
        int t = heap.extractMax();
        std::cout << t << " ";
    }
    std :: cout <<"\n";
    delete[] res;

    return 0;
}
