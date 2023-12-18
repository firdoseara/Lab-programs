#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	printf("PID of ex1.c=%d\n",get pid());
	char* arg1[]={"Hello","Nero","SIET","NULL"};
	execv("%ex.2",argc);
	printf("Back to ex1.c");
	return 0;
}