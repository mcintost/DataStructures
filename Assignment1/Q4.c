/* CS261- Assignment 1 - Q.4*/
/* Name: Thomas McIntosh
*  Date: 10/1/2016
*  Solution description: This program creates 20 unique student ids with a test score
*  the program then sorts the students based on increasing test scores.
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

void sort(struct student* students, int n) {
	/*Sort the n students based on their score*/
	int i;
	int j;
	int swap;

	for (i = 0; i < (n - 1); i++)
	{
		for (j = 0; j < (n - i - 1); j++)
		{
			if (students[j].score > students[j + 1].score)
			{
				swap = students[j].score;
				students[j].score = students[j + 1].score;
				students[j + 1].score = swap;
			}
		}
	}

}
int main() {
	/*Declare an integer n and assign it a value.*/
	int n = 20;
	/*Allocate memory for n students using malloc.*/
	struct student *studentList = malloc(n * sizeof(struct student));
	/*Generate random and unique IDs and random scores for the n students, using rand().*/
	studentList[20];
	int numOfCalls;
	int testScores;
	int array[20];
	int x;
	int y;
	int p;
	int s;
	int i = 0;

	for (numOfCalls = 0; numOfCalls < 20; numOfCalls++) {
		array[numOfCalls] = rand() % 20 + 1;
	}

	while (i < n) {
		int r = rand() % n + 1;

		for (x = 0; x < i; x++)
		{
			if (array[x] == r) {
				break;
			}
		}
		if (x == i) {
			array[i++] = r;
		}
	}

	for (p = 0; p < n; p++) {
		studentList[p].id = array[p];
	}

	for (testScores = 0; testScores < n; testScores++) {
		array[testScores] = rand() % 100 + 1;
	}

	for (p = 0; p < n; p++) {
		studentList[p].score = array[p];
	}

	/*Print the contents of the array of n students.*/

	for (s = 0; s < n; s++)
	{
		printf("ID %d %d\n", studentList[s].id, studentList[s].score);
	}

	/*Pass this array along with n to the sort() function*/
	sort(studentList, n);

	/*Print the contents of the array of n students.*/
	printf("\nSorted: \n");

	for (s = 0; s < n; s++)
	{
		printf("ID %d %d\n", studentList[s].id, studentList[s].score);
	}

	free(studentList);
	return 0;
}
