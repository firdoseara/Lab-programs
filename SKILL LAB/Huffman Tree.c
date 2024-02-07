#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node 
{
    char data;
    unsigned frequency;
    struct Node *left,*right;
};
struct Node* createNode(char data,unsigned frequency)
{
    struct Node* newNode = (struct  Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->frequency=frequency;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct Node* buildHuffmanTree(char data[],unsigned frequency[],int size)
{
    struct Node *left,*right,*top;
    struct Node* priorityQueue[size];
    int rear=0;
    for(int i=0;i<size;++i)
    {
        priorityQueue[rear++]=createNode(data[i],frequency[i]);
        for(int j=rear-1;j>0;j--)
        {
            if(priorityQueue[j]->frequency<priorityQueue[j-1]->frequency)
            {
                struct Node* temp=priorityQueue[j];
                priorityQueue[j]=priorityQueue[j-1];
                priorityQueue[j-1]=temp;
            }
            else
            {
                break;
            }
        }
    }
    while(rear>1)
    {
        left=priorityQueue[0];
        right=priorityQueue[1];
        for(int i=0;i<rear-2;++i)
        {
            priorityQueue[i]=priorityQueue[i+2];
            
        }
        rear-=2;
        top=createNode('$',left->frequency+right->frequency);
        top->left=left;
        top->right=right;
        int i; 
        for(i=rear-1;i>=0;--i)
        {
            if(top->frequency>=priorityQueue[i]->frequency)
            {
                break;
            }
            priorityQueue[i+1]=priorityQueue[i];
        }
        priorityQueue[i+1]=top;
        rear++;
    }
    return priorityQueue[0];
}
void printHuffmanCodes(struct Node* root,int arr[],int top)
{
    if(root->left)
    {
        arr[top]=0;
        printHuffmanCodes(root->left,arr,top+1);
    }
    if(root->right)
    {
        arr[top]=1;
        printHuffmanCodes(root->right,arr,top+1);
    }
    if(!(root->left)&&!(root->right))
    {
        printf("%c:",root->data);
        for(int i=0;i<top;++i)
        {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    char inputString[]="blackboard";
    int frequencies[256]={0};
    int len=strlen(inputString);
    for(int i=0;i<len;i++)
    {
        frequencies[(int)inputString[i]]++;
    }
    int validCharacters=0;
    for(int i=0;i<256;i++)
    {
        if(frequencies[i]>0)
        {
            validCharacters++;
        }
    }
    char data[validCharacters];
    int freq[validCharacters];
    int index=0;
    for(int i=0;i<256;i++)
    {
        if(frequencies[i]>0)
        {
            data[index]=(char)i;
            freq[index]=frequencies[i];
            index++;
        }
    }
    struct Node* root=buildHuffmanTree(data,freq,validCharacters);
    int arr[100],top=0;
    printf("Huffman codes:\n");
    printHuffmanCodes(root,arr,top);
    return 0;
}
