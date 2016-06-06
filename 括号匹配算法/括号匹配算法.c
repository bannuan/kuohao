#include<stdio.h>

typedef unsigned char boolean;
#define TRUE 1
#define FALSE 0

boolean isMarketMatch(char *str, int *index);
void showMismatch(char *str, int mismatchIndex);

void showMismatch(char *str, int mismatchIndex){
	int i;

	printf("\n%s\n", str);
	for(i = 0; i < mismatchIndex; i++){
		printf(" ");
	}
	printf("^\n");
}

boolean isMarketMatch(char *str, int *index){
	int num = 0;
	int i;

	for(i = 0; str[i]; i++){
		if(str[i] == '('){
			++num;
		}else if(str[i] == ')'){
			--num;
			if(num < 0){
				*index = i;
				return FALSE;
			}
		}
	}

	if(num > 0){
		*index = i-1;
	}

	return num == 0;
}

void main(void){
	char str[80];
	int mismatchIndex;

	printf("ÇëÊäÈë×Ö·û´®£¬½ö½öÖ»°üº¬(ºÍ):\n");
	gets(str);

	if(isMarketMatch(str, &mismatchIndex)){
		printf("À¨ºÅÆ¥Åä£¡\n");
	}else
	{
		printf("À¨ºÅ²»Æ¥Åä£¡\n");
		showMismatch(str, mismatchIndex);
	}
}