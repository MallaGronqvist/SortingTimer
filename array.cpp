// array.cpp
// Author: Malla Grönqvist
// Definition file for array class

#include "array.h"
#include <ctime>
#include <random>

Array::Array(): size(0) {   // Initialize size to zero.
    arr = nullptr;      // Set pointer to null pointer.
}

Array::Array(int pNum): size(pNum) {
    // Initialize array with given number of elements.
    arr = new int[pNum];
}

Array::~Array() {   // Delete array.
    delete [] arr;
    arr = NULL;
}

void Array::fillArray() {
    // Initialize the random engine generator with the range 0 - size (-1).
    std::default_random_engine generator(static_cast<unsigned>(time(0)));
    std::uniform_real_distribution<double> random(0,size);
    // Fill the array with randomized numbers.
    for (size_t i = 0; i < size; i++){
         arr[i] = random(generator);
    }
}

void swap(int &a, int &b) {
    int tmp = a;    // Swap a and b.
    a = b;
    b = tmp;
}

void Array::quickS(int arr[], int first, int last) {
    if(first < last) {
        int low  = first;
        int high = last;
        if(arr[first] > arr[last])     // Place a sentinel in the position a[last ]
            swap(arr[first], arr[last]);

        do {
            // Start from the beginning and search for the first value
            // that is bigger than a[first].
            do {
                low++;
            } while(arr[low] < arr[first]);
            // Start from the end and search for the first value that is
            // smaller than a[first].
            do {
                high--;
            } while(arr[high] > arr[first]);
            // Swap a[low] and a[high] if low < high.
            if(low < high)
                swap(arr[low], arr[high]);
        } while(low <= high);          // Continue until low > high.

        swap(arr[first], arr[high]);        // Place a[first] in sorted position.

        quickS(arr, first, high-1);                // Sort left list.
        quickS(arr, high+1, last);                 // Sort right list.
    }
}

// Wrapper function for quick sort.
void Array::quickSort() {
    quickS(arr, 0, size-1);
}

void Array::insertionSort() {
    if(size > 1) {
        int save, j;
        for(int k = size - 1; k >= 0; k--) {
            j = k+1;
            save = arr[k];
            /* If the element is bigger than the key move it
            to one position ahead of its current position */
            while(j < size && save > arr[j]) {
                arr[j-1] = arr[j];
                j++;
            }
            arr[j-1] = save;
        }
    }
}

void Array::selectionSort() {
    for(int i=0; i < size - 1; i++) {
        int smallIdx = i;             // Index for the smallest nr to the right from i.
        for( int j= i+1; j < size; j++)  // Find the smallest non-sorted number.
            if(arr[j] < arr[smallIdx])
                smallIdx = j;             // Save index of the smallest number.

        if(smallIdx != i)             // Swap numbers if smaller than a[i].
            swap(arr[i], arr[smallIdx]);
    }
}

void Array::bubbleSort() {
    for(int pass=0; pass < size-1; pass++)
        for(int i=0; i < size-1; i++) {
            /* If element to the left is bigger than
             * the on to the right, swap them. */
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
}










