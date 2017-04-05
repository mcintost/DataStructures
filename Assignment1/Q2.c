/* CS261- Assignment 1 - Q.2*/
/* Name: Thomas McIntosh
* Date: 10/1/2016
* Solution description: This program takes 3 integers and passes 2 by reference and 
* 1 by value to show the difference between the two.
*/

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c) {
	/*Set a to double its original value*/
	*a = *a * 2;
	/*Set b to half its original value*/
	*b = *b / 2;
	/*Assign a+b to c*/
	c = *a + *b;
	/*Return c*/
	return c;
}

int main() {
	/*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;

	/*Print the values of x, y and z*/
	printf("X = %d \n", x);
	printf("Y = %d \n", y);
	printf("Z = %d \n", z);

	/*Call foo() appropriately, passing x,y,z as parameters*/
	int w = foo(&x, &y, z);

	/*Print the value returned by foo*/
	printf("foo C = %d\n", w);

	/*Print the values of x, y and z again*/
	printf("X = %d \n", x);
	printf("Y = %d \n", y);
	printf("Z = %d \n", z);

	/*Is the return value different than the value of z?  Why?
	Yes there is a difference becuase the value of z is passed 
	by value, this means that the value is passed from z but not
	the value from the address of z.  That means when you test the
	value after the foo function. It is still the original value.*/

	return 0;
}
