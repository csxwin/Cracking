#include <stdio.h>
#include <string.h>

void Q1_1()
{
	char c = 'g';
	char * string = "abcdefg";
	char id[2];
	id[0] = c;
	id[1] = 0;

	if(strstr(string, id)!=0)
	{
		printf("found\n");
	}
	else
	{
		printf("not found\n");
	}
}

void Q1_2()
{
	char * string = "abcdefg";
	char * id = "f";

	if(strstr(string, id)!=0)
	{
		printf("found");
	}
	else
	{
		printf("not found");
	}
}


char* Q2_1(char * str)
{
	int i = 0; 
	int str_len = 0;
	char loc_str_array [20];
	char * loc_str = str;
	while(*(loc_str++)!=0)
	{
		str_len++;
	}
	loc_str--;
	while(i <= str_len)
	{
		loc_str_array[i++] = *(--loc_str);
	}
	loc_str_array[str_len] = 0;
	return loc_str_array;
}

void Q2_2(char * str, char ** str2)
{
	int i = 0; 
	int str_len = 0;
	char loc_str_array [20];
	char * loc_str = str;
	while(*(loc_str++)!=0)
	{
		str_len++;
	}
	loc_str--;
	while(i <= str_len)
	{
		loc_str_array[i++] = *(--loc_str);
	}
	loc_str_array[str_len] = 0;
	*str2 = loc_str_array;
}

int IsPermutation(char* str1, char* str2) //Q3
{
	char * loc_str1 = str1;
	char * loc_str2 = str2;
	char * ptr1, * ptr2;
	int    num_str1 = 0;
	int    num_str2 = 0;
	if(strlen(loc_str1)!=strlen(loc_str2))
	{
		return 0;
	}
	ptr1 = loc_str1;

	while(*ptr1!=0)   //!!!!!!!!!!!!!!!!!!!!!!!!!! Made mistake here. judge ptr value.
	{
		ptr2 = loc_str1;
		while(*ptr2!=0)
		{
			if(*ptr2 == *ptr1)
			{
				num_str1++;
			}
			ptr2++;
		}

		ptr2 = loc_str2;
		while(*ptr2!=0)
		{
			if(*ptr2 == *ptr1)
			{
				num_str2++;
			}
			ptr2++;
		}
		if(num_str1!=num_str2)
		{
			return 0;
		}
		ptr1++;
	}
	printf("two strings are permutation\n");
	return 1;
}


void Q4(char** str, int length)
{
	char * ptr = *str;

/*
below block is only to test char pointer and array, strcpy
*/
	char * test;
	//* test = 'a'; //will report error
	test = "abc";   //good
	char test_array[5]; // necessary for test to be ok in strcpy
	//test_array = "acde"; //will report error. array cannot be assigned.
	test = test_array;  // what does this mean?
	strcpy(test,"abd");
	strcpy(test_array, "acd");


	char new_str[20] = "";							
	char * new_ptr = new_str;
	strcpy(new_ptr, "a");
	int i = 0;   
	for(i = 0; i < length; i++)
	{
		
		if(*ptr!=0x20)
		{
			*(new_ptr++) = *ptr;
		}
		else{
			*(new_ptr++) = '%';
			*(new_ptr++) = '2';
			*(new_ptr++) = '0';
		}
		ptr++;
	}
	*new_ptr = 0;
	*str = new_str;
}


void Q5(char* str)
{
	char new_str[20] = "";
	int n = 0;
	int m = 0;
	char * ptr = str;
	while(*ptr != 0)
	{	
		n = 0;
		while(*(ptr+n)==*ptr)
		{
			n++;
		}
		
		new_str[m++] = *ptr;
		new_str[m++] = n + 0x30;
		ptr = ptr + n;
	}
	new_str[m] = 0;
}

void Q6()
{
	int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int matrix_new[3][3];
	puts("Q6. original matrix shows below:");
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%d",matrix[i][j]);
			if (j == 2){printf("\n");}
			matrix_new[j][2-i] = matrix[i][j];
		}
	}
	puts("Q6. new matrix shows below:");
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			
			printf("%d",matrix_new[i][j]);
			if (j == 2){printf("\n");}
		}
	}
}

void Q7()
{
	int matrix[3][3] = {{1,2,3},{4,5,6},{0,8,9}};
	int zero_point [20];
	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(matrix[i][j] == 0)
			{
				zero_point[n++] = i;
				zero_point[n++] = j;
			}
		}
	}
	for(int i = 0; i < n/2; i++)
	{
		for (int r = 0; r < 3; r++)
		{
			matrix[r][zero_point[2*i+1]] = 0;
		}
		for (int c = 0; c < 3; c++)
		{
			matrix[zero_point[2*i]][c] = 0;
		}
	}
	puts("Q7: clear row and colum:\n");
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%d",matrix[i][j]);
			if (j == 2){printf("\n");}
		}
	}
}

int isSubstring(char * substr, char * str)
{
	char * ptr;
	ptr = strstr(str, substr);
	return (ptr == 0 ? 0 : 1);
}

int Q8(char * str1, char * str2)
{//bug here
	char substr[20];
	char *ptr1 = str1;
	char *ptr2 = str2;
	int n = 0;
	int i = 0;
	int flag1 = 1;
	int flag2 = 1;
	do{
		while(*ptr1!=0)
		{
			if(*(ptr1++) == *ptr2)
			{
				
				break;
			}
			n++;
		}
		strncpy_s(substr, str2, strlen(str1)-n);
		substr[strlen(str1)-n] = 0;
		flag1 = (isSubstring(substr, str1) == 0 ? 0 : 1);

		for( i = 0; i < n; i++)
		{
			substr[i] = *(str2 + (strlen(str2)-n+i));
		}
		substr[n] = 0;
		flag2 = (isSubstring(substr, str1) == 0 ? 0 : 1);
		n++;
	}while((!(flag1&&flag2))&&(*ptr1!=0));

	if(flag1&&flag2)
	{
		printf("%s is rotation of %s",str2, str1);
	}
	else{
		printf("%s is not rotation of %s",str2, str1);
	}
	return 1;
}

int main(){
	char i = 0;
	char * str = "abbcccccdeee";
	char * str_reverse = "";
	char str2[10];
	char * str3 = "eabeebccdccc";
/**
Q1
**/
	Q1_1();
/**
Q2
**/
	//str_reverse = Q2_1(str);
	Q2_2(str, &str_reverse);
	
	do{
		str2[i++] = *(str_reverse+i);
	}while(str2[i-1]!=0);

	//printf("%s\n",str_reverse);

	printf("str: %s\n",str);
	printf("str_reverse: %s\n",str_reverse);
	printf("str2: %s\n",str2);

/**
Q3
**/
	i = IsPermutation(str, str2);
	if(!i)
	{
		printf("str str2 not permutation\n");
	}
	i = IsPermutation(str, str3);
	if(!i)
	{
		printf("str str3 not permutation\n");
	}

/**
Q4
**/
	char* str_Q4 = "Mr John Smith    ";
	Q4(&str_Q4, 13);

/**
Q5
**/
	Q5(str);
/**
Q6
**/
	Q6(); //!!!!!!!!!! how to pass matrix by pointer
/**
Q7
**/
	Q7();
/**
Q8
*/
	char * str1_Q8 = "waterbottle";
	char * str2_Q8 = "lerbottlewa";
	Q8(str1_Q8, str2_Q8);


	do{
	}while(getchar()!=0xa);

	return 0;
}


