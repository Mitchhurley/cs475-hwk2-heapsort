/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{	
	int listsize = n;
	printList(A, n);
	buildHeap(A, n);
	printf("\nPost Build Heap");
	printList(A, n);
	while (n > 0){
		printf("\nN is %d",n);
		printList(A, listsize);
		swap(&A[n-1], &A[0]);
		printList(A, listsize);
		n--;
		heapify(A, 0, n);
		

	}
	printList(A, n);
}
	

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	
	printf("\nHeapifying All");
	for (int i = n/2; i >= 0; i--){
		
		heapify(A,i,n);
	}
	
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	
	// get index of left child of element i
	int left = (2 * (i+1)) - 1;
	printf("\nIndex of current node is %d, Sal is %d", i,  A[i].salary);
	printf("\nIndex of left child is %d, Sal is %d", left, A[left].salary);
	
	//get index of right child of element i
	int right = 2 * (i + 1);
	printf("\nIndex of right child is %d, Sal is %d", right, A[right].salary);
	int smaller = i;
	// TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	if (right < n && A[right].salary < A[left].salary){
		printf("\nRight is smaller");
		smaller = right;
	} else if (left < n){
		printf("\nLeft is smaller");
		smaller = left;
	}
	if (smaller != i && A[i].salary > A[smaller].salary) {
		swap(&A[i], &A[smaller]);
		printf("\nHeapifying");
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee tmp = *e1;  
  	*e1 = *e2;
  	*e2 = tmp; 
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for (int i = 0; i < n; i++)
        printf("Name = %s, Salary = %d\n ", A[i].name,A[i].salary);
    printf("\n");
}
