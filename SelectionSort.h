#include <iostream>
#include <algorithm>

class SelectionSort{

public:
    void selectionSort(int arr[], int n){

        for(int i = 0; i < n; i++){
            int minIndex = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[minIndex])
                    minIndex = j;
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }
};
