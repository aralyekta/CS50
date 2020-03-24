#include <stdio.h>
#include <cs50.h>
#include <string.h>

int isalpha(char);
char transform_print(char, int[], int[]);

int main(int argc, string argv[])
{	
	int i, leng = 0, leng_str = 0, temp = 0, l = 0;
	int array_upper[26], array_lower[26];
	string s;
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
		temp = isalpha(argv[1][i]);
		if (temp == 0)
		{
			printf("Invalid key, problem is with %d\n",argv[1][i]);
			return 1;
		}
		else if (temp == 2)
		{
			for (l = 0 ; l < i ; l++)
			{
				if (argv[1][i] == array_upper[l])
				{
					printf("Invalid key\n");
					return 1;
				}
				
			}
			array_upper[i] = argv[1][i];
			array_lower[i] = argv[1][i]+32;
		}
		else if (temp == 1)
		{
			for (l = 0 ; l < i ; l++)
			{
				if (argv[1][i] == array_lower[l])
				{
					printf("Invalid key\n");
					return 1;
				}	
			}
			array_lower[i] = argv[1][i];
			array_upper[i] = argv[1][i]-32;
		}
	}
	s = get_string("plaintext: ");
	leng_str = strlen(s);
	printf("ciphertext: ");
	for (i = 0 ; i < leng_str ; i++)
	{
		transform_print(s[i], array_upper, array_lower);
	}
	printf("\n");
	return 0;
}

int isalpha(char c)
{
	if (c <= 'z' && c >= 'a')
	{
		return 1;
	}
	else if (c <= 'Z' && c >= 'A')
	{
		return 2;
	}
	else
		return 0;
}

char transform_print(char c, int array_upper[], int array_lower[])
{
	int temp;
	temp = isalpha(c);
	if (temp == 2)
	{
		c -= 'A';
		printf("%c",array_upper[c]);
	}
	else if (temp  == 1)
	{
		c -= 'a';
		printf("%c",array_lower[c]);
	}
	else
	{
		printf("%c",c);
	}
	return 0;
}
