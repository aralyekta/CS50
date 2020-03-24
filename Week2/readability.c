#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(){
	string s = get_string("Text: ");
	int word = 0, letter =0, sentence = 0, i = 0, leng= 0, on_word =0;
	float index;
	leng = strlen(s);
	for (;i<leng;i++){
		if (((int)s[i] <= 'z' && (int)s[i] >= 'a') || ((int)s[i] <= 'Z' && (int)s[i] >= 'A')){
			if (on_word != 1){
				on_word = 1;
				word++;
		}
			letter++;
		}
		else {
			if ((int)s[i] == 32 || (int)s[i] == 44 || (int)s[i] == 59 ){
				on_word = 0;
			}
			else if ((s[i] == '.' || s[i] == '!' || s[i] == '?') && on_word == 1){
				on_word = 0;
				sentence++;
			}
		}
	}
	/*printf("%d letter(s)\n%d word(s)\n%d sentence(s)\n", letter, word, sentence);*/
	index = 0.0588 * ((float)letter / (float)word) * 100 - 0.296 *((float)sentence / (float)word) * 100 - 15.8;
	if (index > 16)
		printf("Grade 16+\n");
	else if (index < 1)
		printf("Before Grade 1\n");
	else{
		if (index - (int)index >= 0.5)
			index = (int)index+1;
		else
			index = (int)index;
		printf("Grade %d\n", (int)index);
	}
	return 0;
}
