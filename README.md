# SortingTimer

This is a C++ console application that test four different sorting algorithms:
<li> QuickSort
<li> BubbleSort
<li> InsertionSort
<li> SelectionSort

The program measures the time it takes for the algorithms to sort an array 
with 5000-40 000 elements and prints out the results to the console and
into a textfile named 'MEASUREMENTS'.

![Bubblesort is slow!](C:/Users/Zakay/Desktop/bild.png "Example output")

## Purpose

My purpose with this project has been to gain insight into different sorting algorithms and 
to compare their efficiency. Moreover, my aim has been to learn about the Big O notation
and how it can be used when looking at the efficiency of algorithms.

## Procedures

The program calls four different testing functions from the main() to test the four different 
sorting algorithms. The functions are basically the same, the only difference is that they 
call different member functions on the array that is to be sorted. -The array class has 
specific member functions for each sorting algorithm. Further, each test function calls the
function for printing the results to file with the specific name of the sorting performed as 
a function parameter.

## Challenges

A problem that I faced with the function for printing was that the once the program had tested
all the sorting algorithms, the created text file would contain only the last result of the
measurements. The program was always writing over the previous data in the text file.
The problem was solved by using the combination of the 'out' and the 'app' flags; in this way 
the program would start writing from the end of the while once it had opened the file.

Another problem had to do with the precision of the measurements. Measuring the time in seconds
was not resulting in precise results as some of the sorting algorithms would perform the sorting in just
some millisecond. In order to get more precise results, I chose to do the measurements in
microseconds and to then convert them to seconds, as dealing with microseconds would have been
unreasonable and too laborious for example in the case of Bubblesort where the results would have been millions
of microseconds. 

## Discussion

There could probably be a more elegant way to construct the program, perhaps in a way that
would not necessitate having separate (and almost identical) functions for each sorting 
algorithm. Such an approach could result in less repetition of the same code. However, as my
purpose was to mainly focus on comparing the sorting algorithms I chose to
keep the program structure as it is.

The results of the program show that there is a significant difference in how efficient the
different sorting algorithms are. Bubblesort turned out to be the most inefficient. Its inefficiency
became particularly obvious with the biggest arrays. Insertionsort and Selectionsort had quite
similar results with each other. They were much more efficient than Bubblesort, but yet much less efficient
than Quicksort. Quicksort was clearly the most efficient sorting algorithm of these four tested
algorithms. Whereas the other three algorithms performed significantly worse as the array
became bigger, Quicksort's results did not worsen in the same pace. It seems to be the best algorithm
for sorting large quantities of data. 

When it comes to comparing the measured times with the theoretical times, Quicksort also seems
to have the best performance: As the array gets bigger, Quicksort seems to perform a faster
than what the Big O notation would predict. The other algorithms instead were performing 
in line with the Big O notation.

In summary, I've learned how the Big O notation can be used to express the efficiency of
algorithms. It's a good way to visualize how the execution time of some algorithm
or program scales with the quantity of data. It can give us an idea of how much
more time the program needs to process a larger quantity of data. 
