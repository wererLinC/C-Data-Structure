//
// Created by weierLin on 7/12/16.
//
#include <iostream>
#include <ctime>
#include <cassert>
#include <stdlib.h>
#include <string>

namespace SortTestHelper {

    // 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];

        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    template <typename T>
    int* copyArrary(T arr[], int n){
        int *arr1 = new int[n];
        for(int i = 0; i < n; i++){
            arr1[i] = arr[i];
        }
        return arr1;
    }

    // 打印arr数组的所有内容
    template<typename T>
    void printArray(T arr[], int n) {

        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        return;
    }

    //因为我们要生成数据很大，总不能进行打印吧
    template <typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0; i < n; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void testSort(std::string sortName, void(*sort)(T[], int n), T arr[], int n){

        clock_t beginTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert( isSorted(arr, n));
        std::cout << sortName << " : " << double(endTime-beginTime)/CLOCKS_PER_SEC << "s" << std::endl;
    }

};
