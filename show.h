#include <iostream>

void show(int arr[], int n){

    for(int i = 0; i < n-1; i++)
        std::cout << arr[i] << "->";
    std::cout << arr[n-1] << std::endl;
}
