/* CS261- Assignment 1 - Q.5*/
/* Name: Thomas McIntosh
* Date: 10/01/2016
* Solution description: This program takes a word and converts it to sticky
* caps.
*/

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch) {
	return ch - 'a' + 'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch) {
	return ch - 'A' + 'a';
}

void sticky(char* word) {
	int i ;
	/*Convert to sticky caps*/



	for (i = 1; word[i]; i++)
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
		{
			word[i] = toLowerCase(word[i]);
		}
		else
			i++;
	}


	if (word[0] >= 'a' && word[0] <= 'z')
	{
		word[0] = toUpperCase(word[0]);
	}

	i = 1;

	while (word[i] != '\0')
	{
		if (word[i - 1] >= 'A' && word[i - 1] <= 'Z')
		{
			i++;
		}
		else //if(word[i - 1] >= 'a' && word[i - 1] <= 'z')
		{
			word[i] = toUpperCase(word[i]);
			i++;
		}
		/*else
		{
			i++;
		}*/
	}
}

int main() {
	char word[32];

	/*Read word from the keyboard using scanf*/
	scanf("%s", word);
	
	/*Call sticky*/
	sticky(word);
	
	/*Print the new word*/
	printf(word);

	return 0;
}
