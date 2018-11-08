#include <iostream>
#include "merge-sort.hpp"

int main(int argc, char const *argv[]) {
    int dy_size;
    std::cout << "Default Merge Sort array will be created with size 8. " << '\n';
    MergeSort merge_sort;
    //merge_sort.printElements();
    merge_sort.mergeSort(0, merge_sort.getSize() - 1);     //indexes from 0 to size-1, it means all array
    std::cout << "Merge Sort is done for array with size " << merge_sort.getSize() << ".\n" << "Array 1:\n";
    merge_sort.printElements();

    std::cout << "\n\n" << "Enter 2nd array's size: " << '\n';
    std::cin >> dy_size;
    MergeSort mergesort(dy_size);
    mergesort.mergeSort(0, mergesort.getSize() - 1);     //indexes from 0 to size-1, it means all array
    std::cout << "Merge Sort is done for array with size " << mergesort.getSize() << ".\n" << "Array 2:\n";

    mergesort.printElements();


    return 0;
}
