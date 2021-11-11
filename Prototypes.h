// Prototypes.h
// Author: Malla Grönqvist
// Header file for functions

#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include <string>

// Declarations of functions that test sorting algorithms
// and print results.

void testBubbleSort();
void testSelectionSort();
void testInsertionsSort();
void testQuickSort();

void printToFile(std::string sortType, int elementNumber, double averageTime);

#endif  // DT018G_PROTOTYPES_H
