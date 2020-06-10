#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int Size(const char* s )
{
	int i = 0;
	for (; s[i] != '\0'; i++);
	return i;
}
int main()
{
	char slova[200];
	gets(slova);
	int size = Size(slova);
	int i=0,b=0, predl=1, sl=0, maxsl=0, maxpr, c, d;
		
	for (i = 0; i < size; i++)                        
	{
		if (slova[i] == '!' || slova[i] == '?' || slova[i] == '.')
		{
			maxpr = i;
			break;
		}
	}
	for (i = maxpr+1; i < size; i++)
	{
		
		if (slova[i]=='!'||slova[i]=='?'||slova[i] == '.')
		{ 
			for (b = i-1; slova[b] != '!' && slova[b] != '?' && slova[b] != '.'; b--)
			
				if (maxpr < i - b)
				{
					maxpr = i - b;
					c = b+1;
					d = i;
				}
				predl++;
		}
		
	}
	printf("\nSentence count:%d\nLongest sentence:", predl);
	for (; c <= d; c++)
		printf("%c",slova[c]);
	for (i = 0; i < size; i++)
	{
		if (isalpha(slova[i]))
		{
			b = i;
			for (; isalpha(slova[i]); i++);
			if (maxsl < i - b)
			{
				maxsl = i - b;
				c = b;
				d = i;
			}
			sl++;
		}
	}
	printf("\nWord count:%d\nLongest word:",sl);
	for (; c <= d; c++)
		printf("%c", slova[c]);
}