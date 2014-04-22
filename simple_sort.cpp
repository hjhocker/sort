#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <vector>
#include "merge_sort.cpp"
#include "random_sequence.cpp"

void print_numbers(float nums[], int *num) {
	for (int i=1;i<*num;i++)
		std::cout << nums[i] << std::endl;
}

float findMin ( float nums[], int num) {
	float min = nums[1]; //nums[0] is zero
	for (int i=1;i<num;i++)
		if ( nums[i] < min )
			min = nums[i];
	return min;
}

float findMax ( float nums[], int num) {
	float max = nums[1]; //nums[0] is zero
	for (int i=1;i<num;i++)
		if ( nums[i] > max )
			max = nums[i];
	return max;
}

int findMinIndexInRange ( float nums[], int start, int stop ) {
	int min = start; //return current position by default
	for (int i=start;i<=stop;i++)
		if ( nums[i] < nums[start] )
			min = i;
	return min;
}

void selection_sort( float nums[], int *num) {
	int min_index = 0;
	for (int i=1;i<*num-1;i++) {
	for (int j=i+1;j<*num;j++) {
		min_index = findMinIndexInRange(nums, i, j);
		if ( nums[min_index] < nums[i] )
			std::swap(nums[min_index],nums[i]);
	}
	}
	return;
}

void quick_sort ( float nums[], int *num) {

	return;
}

void shell_sort ( float nums[], int *num) {

	return;
}

int main (int argc, char *argv[]) {

	unsigned t0 = clock(), t1;

	if (argc == 1) {
		std::cout << "Please pass me some numbers" << std::endl;
		exit(1);
	}

	if ( argc == 2) {
		std::cout << argv[1] << std::endl;
		return 0;
	}

	float numbers[argc];

	srand(time(NULL)^2);
	for (int i=0;i<argc;i++) {
		numbers[i] = atof(argv[i]);
	}

	float *p = &numbers[0];
	std::cout << "Unsorted list" << std::endl;
	//print_numbers(p, &argc);

	std::cout << "Selection Sorted list" << std::endl;
	t0 = clock();
	selection_sort(p, &argc);
	t1=clock()-t0;
	std::cout << "Execution time " << t1 << std::endl;
	print_numbers(p, &argc);

	std::cout << "Randomized List" << std::endl;
	//random_sequence(p, &argc);
	//print_numbers(p, &argc);

	t0 = clock();
	std::cout << "Merged Sort List" << std::endl;
	merge_sort(p, &argc);
	t1=clock()-t0;
	std::cout << "Execution time " << t1 << std::endl;
	print_numbers(p, &argc);
	t1=clock()-t0;
	std::cout << "Execution time " << t1 << std::endl;

	return 0;
}



