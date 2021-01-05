#include <stdio.h>
#include "txtfind.h"

int main()
{
	char word[WORD];
	char func;
	getword(word);
	scanf("%c",&func);
	if (func == 'a'){
		print_lines(word);
	}
	if (func == 'b'){
		print_similar_words(word);
	}
	return 1;
}