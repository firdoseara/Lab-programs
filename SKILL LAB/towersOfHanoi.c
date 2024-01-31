#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of disks:");
    scanf("%d",&n);
    char source='A',auxillary='B',destination='C';
    towerOfHanoi(n,source,auxillary,destination);
    return 0;
}
void towerOfHanoi(int n,char source,char auxillary,char destination)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",source,destination);
        return;
    }
    towerOfHanoi(n-1,source,destination,auxillary);
    printf("Move disk %d from %c to %c\n",n,source,destination);
    towerOfHanoi(n-1,auxillary,source,destination);
}
