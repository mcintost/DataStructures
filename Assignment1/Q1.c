/* CS261- Assignment 1 - Q.1*/
/* Name: Thomas McIntosh
* Date: 10/1/2016
* Solution description:This program generates 10 random students id and test scores.
* the program shows the min. max. and average test scores.
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/
	int numStudent = 10;
	struct student *myStudents = malloc(numStudent * sizeof(struct student));
	/*return the pointer*/
	return myStudents;
}

void generate(struct student* students) {
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int numOfCalls;
	int testScores;
	int array[10];
	students[10];
	int x;
	int y;
	int p;
	int i = 0;

	//srand(time(NULL));

	for (numOfCalls = 0; numOfCalls < 10; numOfCalls++){
		array[numOfCalls] = rand() % 10 + 1;
	}

	while (i < 10){
		int r = rand() % 10 + 1;

		for (x = 0; x < i; x++)
		{
			if (array[x] == r) {
				//students[p].id = r;
				break;
			}
		}
		if (x == i) {
			array[i++] = r;
		//	students[p].id = r;

		}
	}

	for (p = 0; p < 10; p++) {
		students[p].id = array[p];
	}

	for (testScores = 0; testScores < 10; testScores++) {
		array[testScores] = rand() % 100 + 1;
	}

	for (p = 0; p < 10; p++) {
		students[p].score = array[p];
	}
}

void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/
	int s;

	for (s = 0; s < 10; s++)
	{
		printf("ID %d %d\n", students[s].id, students[s].score);
	}

}

void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	int scores[10];
	int minimum;
	int maximum;
	float sum = 0;
	float average;
	int location = 1;
	int x;
	int s;
	int i;
	for (s = 0; s < 10; s++)
	{
		scores[s] = students[s].score;
	}
	
	minimum = scores[0];

	for (x = 1; x < 10; x++)
	{
		if (scores[x] < minimum)
		{
			minimum = scores[x];
			location = x + 1;
		}
	}

	maximum = scores[0];

	for (x = 1; x < 10; x++)
	{
		if (scores[x] > maximum)
		{
			maximum = scores[x];
			location = x + 1;
		}
	}

	for (i = 0; i < 10; i++)
	{
		sum = sum + scores[i];
	}

	average = sum / 10;

	printf("Minimum Score = %d\n", minimum);
	printf("Maximum Score = %d\n", maximum);
	printf("total %.0f\n", sum);
	printf("Average Score = %.2f\n", average);
}

void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/
	free(stud);
}

int main() {
	struct student* stud = NULL;

	/*call allocate*/
		stud = allocate();
	/*call generate*/
		generate(stud);
	/*call output*/
		output(stud);
	/*call summary*/
		summary(stud);
	/*call deallocate*/
		deallocate(stud);
	return 0;
}
