#include<stdio.h> 
#include<stdlib.h> 
#define MAX 100 
int create(int); 
void display(int[]); 
void linear_prob(int[],int,int); 
int main() 
{ 
 int a[MAX],num,key,i; 
 int ans=1; 
printf("collision handling by linear probing:\n"); 
 for(i=0;i<MAX;i++) 
 a[i]=-1; 
 do 
 { 
 printf("Enter the data:\n"); 
 scanf("%4d",&num); 
 key=create(num); 
 linear_prob(a,key,num); 
 printf("\nDo you want to conƟnue? (0/1): ");
 scanf("%d",&ans); 
 } while(ans); 
 display(a); 
} 
int create(int num) 
{ 
 int key; 
 key=num%100; 
 return key; 
} 
void linear_prob(int a[MAX],int key,int num) 
{ 
 int flag,i,count=0; 
 flag=0; 
 if(a[key]==-1) 
 a[key]=num; 
 else 
 { 
 printf("Collinsion detected.....!!\n"); 
 i=0; 
 while(i<MAX) 
 { 
 if(a[i]!=-1) 
 count++; 
 i++; 
 } 
 printf("Collision avoided successfully using LINEAR PROBING\n"); 
 if(count==MAX) 
 { 
 printf("Hash table is full");
 display(a); 
 exit(1); 
 } 
 for(i=key+1;i<MAX;i++) 
 if(a[i]==-1) 
 { 
 a[i]=num; 
 flag=1; 
 break; 
 } 
 for(i=0;i<key;i++) 
 i=0; 
 while((i<key)&&(flag==0)) 
 { 
 if(a[i]==-1) 
 { 
 a[i]=num; 
 flag=1; 
 break; 
 } 
 i++; 
 } 
 } 
} 
void display(int a[MAX]) 
{ 
 int ch,i; 
printf("1.Display All\n2.Filtered display\n"); 
 scanf("%d",&ch); 
 if(ch==1) 
 { 
 printf("\nThe hash table is:\n"); 
 for(i=0;i<MAX;i++) 
 printf("%d %d\n",i,a[i]); 
 } 
 else 
 { 
 printf("The hash table is\n"); 
 for(i=0;i<MAX;i++) 
 if(a[i]!=-1) 
 { 
 printf("%d %d\n ",i,a[i]); 
 continue;
 } 
 } 
}
