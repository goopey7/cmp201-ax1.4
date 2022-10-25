// CMP201.2022 AX1.4 Sorting
// William Kavanagh, Abertay University

#include "Sorting.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */
#include <iostream>
#include <chrono>		/* timing */
#include <string>

// Bubble up and bubble back down.
// Runs in O(N^2).
void CocktailShakerSort(int a[], int size)
{
	// TODO: assessed, [1.0]
	for(int i=0;i<size/2; i++)
	{
		bool swappedRight = false;
		bool swappedLeft = false;

		// Shake to the right
		for(int j=0;j<size-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swappedRight = true;
			}
		}

		// Shake to the left
		for(int j=size-2-i; j>i; j--)
		{
			if(a[j] < a[j-1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				swappedLeft = true;
			}
		}

		if(!swappedLeft && !swappedRight)
		{
			break;
		}
	}
}

// IN-PLACE implementation of insertion sort.
// Runs in O(N^2).
void InsertionSort(int a[], int size)
{
	// TODO: assessed, [1.5]
	for(int i=1; i < size; i++)
	{
		for(int j=i; j>0; j--)
		{
			if(a[j] < a[j-1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	
}

// Partition function for QuickSort.
// Runs in O(n) and chooses the final element as the pivot
int partition(int a[], int begin, int end)
{
	// TODO: assessed, [2.0]
	return 0;
}

// Sorting using partition() and recusion. Runs in O(n log(n))
void QuickSort(int a[], int begin, int end)
{
	// TODO: assessed, [0.5]
	
}

// Takes an array and it's size (as int), fills the array with random values from 1 to size*3
void fillArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % (size * 3);
	}
}

// Utility function: O(n) sorted check with early exit.
bool isSorted(int a[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (a[i] < a[i - 1]) return false;
	}
	return true;
}

// Utility function: Get two time points and return a string of nanoseconds between them.
std::string timeDelta(std::chrono::system_clock::time_point t, std::chrono::system_clock::time_point t2)
{
	long timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t).count();
	return std::to_string(timeDelta) + " ns";
}

// Main method included for testing. Remove or comment out before submitting or [-1.0].
int main()	// Ignore the warnings, this is a semester 2 problem.
{
	srand(time(NULL));	// seed RNG

	// Generate 3 random arrays of length 1000 with 3 copies of each.
	int a[100] = {};
	fillArray(a, 100);
	int a_copy[100];
	std::copy(std::begin(a), std::end(a), std::begin(a_copy));
	int a_second_copy[100];
	std::copy(std::begin(a), std::end(a), std::begin(a_second_copy));
	int b[1000] = {};
	fillArray(b, 1000);
	int b_copy[1000];
	std::copy(std::begin(b), std::end(b), std::begin(b_copy));
	int b_second_copy[1000];
	std::copy(std::begin(b), std::end(b), std::begin(b_second_copy));
	int c[2000] = {};
	fillArray(c, 2000);
	int c_copy[2000];
	std::copy(std::begin(c), std::end(c), std::begin(c_copy));
	int c_second_copy[2000];
	std::copy(std::begin(c), std::end(c), std::begin(c_copy));

	// CocktailShaker tests
	auto time = std::chrono::high_resolution_clock::now();
	CocktailShakerSort(a, 100);
	auto time2 = std::chrono::high_resolution_clock::now();
	CocktailShakerSort(b, 1000);
	auto time3 = std::chrono::high_resolution_clock::now();
	CocktailShakerSort(c, 2000);
	auto time4 = std::chrono::high_resolution_clock::now();

	if(isSorted(a, 100) && isSorted(b, 1000) && isSorted(c, 2000))
	{
		std::cout << "Cocktail shaker sorts correctly:\n\tTime taken for A:\t";
		std::cout << timeDelta(time, time2) << "\n\tTime taken for B:\t";
		std::cout << timeDelta(time2, time3) << "\n\tTime taken for C:\t";
		std::cout << timeDelta(time3, time4) << "\n\n";
	}
	else {
		std::cout << "Cocktail shaker sort is not sorting correctly\n\n";
	}

	// Insertion tests
	time = std::chrono::high_resolution_clock::now();
	InsertionSort(a_copy, 100);
	time2 = std::chrono::high_resolution_clock::now();
	CocktailShakerSort(b_copy, 1000);
	time3 = std::chrono::high_resolution_clock::now();
	CocktailShakerSort(c_copy, 2000);
	time4 = std::chrono::high_resolution_clock::now();

	if (isSorted(a_copy, 100) && isSorted(b_copy, 1000) && isSorted(c_copy, 2000))
	{
		std::cout << "Insertion sorts correctly:\n\tTime taken for A:\t";
		std::cout << timeDelta(time, time2) << "\n\tTime taken for B:\t";
		std::cout << timeDelta(time2, time3) << "\n\tTime taken for C:\t";
		std::cout << timeDelta(time3, time4) << "\n\n";
	}
	else {
		std::cout << "Insertion sort is not sorting correctly\n\n";
	}

	// Quicksort tests
	time = std::chrono::high_resolution_clock::now();
	QuickSort(a_second_copy, 0, 99);
	time2 = std::chrono::high_resolution_clock::now();
	QuickSort(b_second_copy, 0, 999);
	time3 = std::chrono::high_resolution_clock::now();
	QuickSort(c_second_copy, 0, 1999);
	time4 = std::chrono::high_resolution_clock::now();

	if (isSorted(a_second_copy, 100) && isSorted(b_second_copy, 1000) && isSorted(c_second_copy, 2000))
	{
		std::cout << "Quicksort sorts correctly:\n\tTime taken for A:\t";
		std::cout << timeDelta(time, time2) << "\n\tTime taken for B:\t";
		std::cout << timeDelta(time2, time3) << "\n\tTime taken for C:\t";
		std::cout << timeDelta(time3, time4) << "\n\n";
	}
	else {
		std::cout << "Quicksort is not sorting correctly\n\n";
	}
	
	return 0;
}
