/* CS261- Assignment 1 - Q. 0*/
/* Name: Thomas McIntosh
* Date: 10/1/2016
* Solution description: Creating a pointer and showing the address and value of the 
* variable and pointer.
*/

#include <stdio.h>
#include <stdlib.h>

/*This function will use the pointer passed to it to show the value
  of the pointer, the address the pointer is pointing to
  and the pointers own address.  */
void fooA(int* iptr) {
	/*Print the value pointed to by iptr*/
	printf("The value pointed to by iptr = %d\n", *iptr);
	/*Print the address pointed to by iptr*/
	printf("The address pointed to by iptr = %d\n", iptr);
	/*Print the address of iptr itself*/
	printf("The address of iptr = %d\n", &iptr);
}

int main() {

	/*declare an integer x*/
	int x = 5;
	/*print the address of x*/
	printf("The address of x = %d\n", &x);
	/*Call fooA() with the address of x*/
	fooA(&x);
	/*print the value of x*/
	printf("The value of x = %d\n", x);
	return 0;
}