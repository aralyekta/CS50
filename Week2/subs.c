#include <stdio.h>
#include <cs50.h>
#include <string.h>

int isalpha(char);

int main(int argc, string argv[])
{	
	int i, leng = 0;
	if (argc == 1)
	{
		printf("No key\n");
		return 1;
	}
	leng = strlen(argv[1]);
	if (leng != 26)
	{
		printf("Not long enough key\n");
		return 1;
	}
	for (i = 0 ; i < 26 ; i++)
	{
		if (isalpha(argv[1][i]) == 0)
		{
			printf("Invalid key, problem is with %d\n",i);
			return 1;
		}
	}
	return 0;
}

int isalpha(char c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
	{
		return 1;
	}
	else
		return 0;
}
