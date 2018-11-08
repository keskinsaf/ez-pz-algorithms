#ifndef MERGESORT_HPP
#define MERGESORT_HPP

class MergeSort {
  private:
    int size;
    int* array;
    //int array[8];

  public:
    MergeSort();
    MergeSort( int array_size );
    ~MergeSort();
    int getSize();
    void printElements();
    void setElements();
    void mergeSort(unsigned int p, unsigned int r);
    void merge(unsigned int p,unsigned int q,unsigned int r);
};

#endif
