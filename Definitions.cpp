// Definitions.cpp
// Author: Malla Grönqvist
// Definition file for functions

#include "Prototypes.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include "array.h"
#include <fstream>
using std::cout;
using std::endl;

// Functions for testing the different sorting algorithms
// and for printing the results.

void testQuickSort() {
    for (int x = 5000; x <= 40000; x += 5000) {     // Repeat for array sizes.
        std::cout << "Testing on " << x << " elements using quick sort." << std::endl;
        double sumOfMeasurements = 0;
        for (int i = 1; i <= 10; i++) {     // Repeat ten times.
            Array test(x);      // Create an array.
            test.fillArray();   // Fill the array with random numbers
            // Start the clock.
            auto timeStart = std::chrono::high_resolution_clock::now();

            test.quickSort();   // Sort the array.
            // Stop the clock.
            auto timeEnd = std::chrono::high_resolution_clock::now();
            std::cout << std::fixed << std::setprecision(6);  // Format output.
            // Calculate duration by subtracting start time from end time.
            size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count();
            double seconds = 1.0 * duration / 1000000;
            // Print result.
            std::cout << "Test number " << i << "/10. Time = " << seconds << std::endl;
            sumOfMeasurements += seconds;   // Add result to the sum of results.
        }
        double average = (sumOfMeasurements / 10); // Calculate average.
        // Print the result.
        std::cout << std::endl << "Average time = " << average << "[s]" << std::endl;
        std::cout << "***************************************************" << std::endl;
        // Print results to file.
        printToFile("Quick sort", x, average);
    }
}

/* The following 3 test functions have not been commented since they
 * contain only some minor details that are different from the function
 * above. */

void testBubbleSort() {
    for (int x = 5000; x <= 40000; x += 5000) {
        std::cout << "Testing on " << x << " elements using bubble sort." << std::endl;
        double sumOfMeasurements = 0;
        for (int i = 1; i <= 10; i++) {
            Array test(x);
            test.fillArray();

            auto timeStart = std::chrono::high_resolution_clock::now();

            test.bubbleSort();

            auto timeEnd = std::chrono::high_resolution_clock::now();

            size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count();
            double seconds = 1.0 * duration / 1000000;
            std::cout << "Test number " << i << "/10. Time = " << seconds << std::endl;
            sumOfMeasurements += seconds;
        }
        double average = (sumOfMeasurements / 10);
        std::cout << std::endl << "Average time = " << average << "[s]" << std::endl;
        std::cout << "***************************************************" << std::endl;
        printToFile("Bubble sort", x, average);
    }
}

void testSelectionSort() {
    for (int x = 5000; x <= 40000; x += 5000) {
        std::cout << "Testing on " << x << " elements using selection sort." << std::endl;
        double sumOfMeasurements = 0;
        for (int i = 1; i <= 10; i++) {
            Array test(x);
            test.fillArray();

            auto timeStart = std::chrono::high_resolution_clock::now();

            test.selectionSort();

            auto timeEnd = std::chrono::high_resolution_clock::now();

            size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count();
            double seconds = 1.0 * duration / 1000000;
            std::cout << "Test number " << i << "/10. Time = " << seconds << std::endl;
            sumOfMeasurements += seconds;
        }
        double average = (sumOfMeasurements / 10);
        std::cout << std::endl << "Average time = " << average << "[s]" << std::endl;
        std::cout << "***************************************************" << std::endl;
        printToFile("Selection sort", x, average);
    }
}

void testInsertionsSort() {
    for (int x = 5000; x <= 40000; x += 5000) {
        std::cout << "Testing on " << x << " elements using insertion sort." << std::endl;
        double sumOfMeasurements = 0;
        for (int i = 1; i <= 10; i++) {
            Array test(x);
            test.fillArray();

            auto timeStart = std::chrono::high_resolution_clock::now();

            test.insertionSort();

            auto timeEnd = std::chrono::high_resolution_clock::now();

            size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count();
            double seconds = 1.0 * duration / 1000000;
            std::cout << "Test number " << i << "/10. Time = " << seconds << std::endl;
            sumOfMeasurements += seconds;
        }
        double average = (sumOfMeasurements / 10);
        std::cout << std::endl << "Average time = " << average << "[s]" << std::endl;
        std::cout << "***************************************************" << std::endl;
        printToFile("Insertions sort", x, average);
    }
}

void printToFile(std::string sortType, int elementNumber, double averageTime) {
    std::string fileName = "MEASUREMENTS";
    // Open file for writing. Write to end of file.
    std::fstream outFile(fileName, std::ios::out| std::ios::app);
    // Write data to file.
    outFile << sortType << char(9) << elementNumber << char(9) << averageTime << endl;
    outFile.close();    // Close file.

}




