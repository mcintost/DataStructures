/* CS261- Assignment 1 - Q.3
* Name: Thomas McIntosh
* Date: 10/1/2016
* Solution description: This program creates a random 20 integer
* array, prints it then sorts it and prints the sorted version.
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n) {
	int i;
	int j;
	int swap;

	/*Sort the given array number , of length n*/
	for (i = 0; i < (n - 1) ; i++)
	{
		for (j = 0; j < (n - i - 1); j++)
		{
			if (number[j] > number[j + 1])
			{
				swap = number[j];
				number[j] = number[j + 1];
				number[j + 1] = swap;
			}
		}
	}

}

int main() {
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	/*Allocate memory for an array of n integers using malloc.*/
	int *arrayOfInts = malloc(n * sizeof(int));
	/*Fill this array with random numbers, using rand().*/
	int x;

	for (x = 0; x < 20; x++)
	{
		arrayOfInts[x] = rand() % 1000;
	}

	/*Print the contents of the array.*/
	for (x = 0; x < 20; x++)
	{
		printf("%d ", arrayOfInts[x]);
	}

	/*Pass this array along with n to the sort() function of part a.*/
	sort(arrayOfInts, n);

	/*Print the contents of the array.*/
	printf("\n Sorted: \n");

	for (x = 0; x < 20; x++)
	{
		printf("%d ", arrayOfInts[x]);
	}

	return 0;
}
