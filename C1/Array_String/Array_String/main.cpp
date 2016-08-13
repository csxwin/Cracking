#include <stdio.h>

int main(){
	char i = 0;
	char c, name[10];
	printf("Please input your name\n");

	while((c=getchar())!='\n')
	{
		name[i++] = c;
	}
	name[i] = 0;
	
	return 0;
}