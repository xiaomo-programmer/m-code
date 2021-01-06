#include<stdio.h>
#include<string.h>
void reverse_string(char * str,int left,int right)
 {
 	if(left<right)
 	{
 		char temp=str[left];
 		str[left]=str[right];
 		str[right]=temp;
 		reverse_string(str,++left,--right);
	 }
 }
  reverse_string(char * str)
 {
 	int left;char temp;
 	int right = strlen(str)-1;
 	str[right]=temp;
 	++left;
 	--right;
 	
  } 
 
 
 
 int main()
 {
 	char strarr1[]="123456"; 
 	reverse_string(strarr1,0,5);
 	return 0;
 }
 
 
 
 
 
 
 
 
 
