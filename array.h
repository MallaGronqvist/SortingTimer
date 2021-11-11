// array.h
// Author: Malla Grönqvist
// Header file for array class.

#ifndef DT019G_ARRAY_H
#define DT019G_ARRAY_H

#include <array>

class Array {
private:
    int *arr;  // Pointer to the array.
    std::size_t size;    // Size of the array.
public:
    // Constructors and destructor.
    Array();
    explicit Array(int pNum);
    ~Array();
    // Member functions.
    void fillArray();
    void quickSort();
    void quickS(int arr[], int first, int last);
    void insertionSort();
    void selectionSort();
    void bubbleSort();
};
// Help function for sorting. Not part of the class.
void swap(int &a, int &b);

#endif //DT019G_ARRAY_H
