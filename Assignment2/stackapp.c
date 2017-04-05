/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
param: 	s pointer to a string
pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s + i);
	if (c == '\0')
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
param: 	s pointer to a string
pre: s is not null
post:
*/
int isBalanced(char* s)
{
	DynArr *dyn;
	int i = 0;
	dyn = newDynArr(2);

	while (s[i] != '\0')
	{
		char temp = s[i];
		//char* temp = s;
		if (temp == '(' || temp == '{' || temp == '[')
		{
			pushDynArr(dyn, temp);
			i++;
			continue;
		}
		else if (temp == ')' || temp == '}' || temp == ']')
		{
			printf("second ");

			if (isEmptyDynArr(dyn))
			{
				return 0;
			}
			if (temp == ')' && topDynArr(dyn) == '(')
			{
				popDynArr(dyn);
				i++;
				continue;
			}
			else if (temp == '}' && topDynArr(dyn) == '{')
			{
				popDynArr(dyn);
				i++;
				continue;
			}
			else if (temp == ']'&& topDynArr(dyn) == '[')
			{
				popDynArr(dyn);
				i++;
				continue;
			}
			else
				return 0;
		}
		else
			i++;
	}

	if (isEmptyDynArr(dyn))
	{
		return 1;
	}
	else
		return 0;
}

int main(int argc, char* argv[]) {

	char* s = argv[1];
	
	int res;

	printf("Assignment2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else
		printf("The string %s is not balanced\n", s);
	return 0;
}

