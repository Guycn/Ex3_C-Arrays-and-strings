#include <stdio.h>
#include <string.h>
#include "txtfind.h"


int getlines(char s[]) {
	char c = getchar();
	int index = 0;
	while (c != '\n' && c != EOF) {  //EOF = End of file
		s[index] = c;
		index++;
		c = getchar();
	}
	s[index] = '\0';
	if (c == EOF)
	{
		return EOF; //EOF=-1
	}
	else
	{
		return 1;
	}
}

int getword(char w[]) {
	char c = getchar();
	int index = 0;
	while (c == '\n' || c == '\t' || c==' '){
		c=getchar();
	}
	while (c != '\n' && c != '\t' && c != EOF && c!=' ') {
		w[index] = c;
		c = getchar();
		index++;
	}
	w[index] = '\0';
	if (c == EOF)
	{
		return EOF;
	}
	else
	{
		return 1;
	}
}

int substring(char* str1, char* str2) {
	int str1len = strlen(str1);
	int str2len = strlen(str2);
	int i = 0, j = 0, counter = 0;
	if (str2len > str1len)return 0;
	while (i != str1len && j != str2len && counter<str2len) {
		if (*(str2 + j) == *(str1 + i)) {
			counter++;
			j++;
			i++;
		}
		else {
			if (counter > 0) {
				counter = 0;
				j = 0;
			}
			i++;
		}

	}
	if (counter == str2len)return 1;
	else return 0;
}

int similar(char* s, char* t, int n) {
	if(strcmp(s,t)==0)
    {
        return 1;
    }
    int counter=0;
    int i=0;
    int j=0;
    while(*(t + i)!='\0' || *(s + j) != '\0')
    {
        if (*(t + i) == *(s + j))
        {
            i++;
            j++;
        }
        else
        {
            j++;
            counter++;
        }
    }
    if (counter > n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void print_lines(char* str) {
	char s[LINE];
	while (getlines(s) != EOF) {
		if (substring(s, str)) {
			printf("%s\n", s);
		}
	}
}

void print_similar_words(char* str) {
	char s[WORD];
	while (getword(s) != EOF) {
		if (similar(s, str, 1)) {
			printf("%s\n", s);
		}
	}
}