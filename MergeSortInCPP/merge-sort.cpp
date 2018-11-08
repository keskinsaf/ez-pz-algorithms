#include "merge-sort.hpp"
#include <iostream>
#include <climits>

MergeSort::MergeSort()
{
    size = 8;
    array = new int[size];
    setElements();
}

MergeSort::MergeSort(int array_size)
{
    size = array_size;
    array = new int[size];
    setElements();
}

MergeSort::~MergeSort()
{
    delete[] array;
    //std::cout << "Object is destroyed." << '\n';
}

int MergeSort::getSize()
{
    return size;
}

void MergeSort::printElements()
{
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i + 1 << ": " << array[i] << '\n';
    }
}

void MergeSort::setElements()
{
    for (int i = 0; i < size; i++) {
        std::cout << "Enter element[" << i + 1 << "]: ";
        std::cin >> array[i];
    }
}

void MergeSort::mergeSort(unsigned int p, unsigned int r)
{
    if (p < r) {
        int q = ( p + r ) / 2;
        //std::cout << "mergesortta: " << '\n';
        //std::cout << "p:" << p << " q:" << q << " r:" << r << '\n';
        mergeSort(p , q);
        mergeSort(q + 1, r);
        merge(p, q, r);
    }
}

void MergeSort::merge(unsigned int p, unsigned int q, unsigned int r)
{
    int n1 = q - p + 1, n2 = r - q;
    int L[n1+1], R[n2+1];
    int i, j;
    //std::cout << "L: " << '\t';
    for (i = 0; i < n1; i++) {
        L[i] = array[(p + i)];
        //std::cout << L[i] << '\t';
    }
    //std::cout << "\nR: " << '\t';
    for (j = 0; j < n2; j++) {
        R[j] = array[(q + 1 + j)];
        //std::cout << R[j] << '\t';
    }
    L[i] = R[j] = INT_MAX;
    //std::cout << '\n';

    i = j = 0;
    for (int k = p; k <= r ; k++) {
        if ( L[i] <= R[j] ) {
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
        //std::cout << array[k] << '\t';
    }
    //std::cout << "Merge is done!" << '\n';

}
