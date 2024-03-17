#include<stdio.h> 
#include<stdlib.h> 
struct BST 
{ 
 int data; 
struct BST *leŌ;
 struct BST *right; 
}; 
typedef struct BST NODE; 
NODE *node; 
NODE* createtree(NODE *node, int data) 
{ 
 if(node==NULL) 
 { 
 NODE *temp; 
 temp=(NODE*)malloc(sizeof(NODE)); 
 temp->data=data; 
 temp->left=temp->right=NULL; 
 return temp; 
 } 
 if(data<node->data) 
 node->left=createtree(node->left,data);
 else if(data>node->data) 
 node->right=createtree(node->right,data); 
 return node; 
} 
NODE* search(NODE *node,int data) 
{ 
 if(node==NULL) 
prinf("Element not found\n"); 
 else if(data<node->data) 
 search(node->left,data);
 else if(data>node->data) 
 search(node->right,data); 
 else 
prinf("Element found is: %d",node->data); 
 return node; 
} 
void inorder(NODE *node) 
{ 
 if(node!=NULL) 
 { 
 inorder(node->left);
 prinf("%d\t",node->data); 
 inorder(node->right); 
 } 
} 
void preorder(NODE *node) 
{ 
 if(node!=NULL) 
 { 
 prinf("%d\t",node->data); 
 preorder(node->left);
 preorder(node->right); 
 } 
} 
void postorder(NODE *node) 
{ 
 if(node!=NULL) 
 { 
 preorder(node->left);
 preorder(node->right); 
 prinf("%d\t",node->data); 
 } 
} 
NODE* findmin(NODE *node) 
{ 
 if(node==NULL) 
 return NULL; 
 if(node->left)
 return findmin(node->left);
 else 
 return node; 
 } 
 NODE* del(NODE *node,int data) 
 { 
 NODE *temp; 
 if(node==NULL) 
 prinf("Element not found\n"); 
 else if(data<node->data) 
 node->left=del(node->left,data);
 else if(data>node->data) 
 node->right=del(node->right,data); 
 else 
 { 
 if(node->right&&node->left)
 { 
 temp=findmin(node->right); 
 node->data=temp->data; 
 node->right=del(node->right,temp->data); 
 } 
 else 
 { 
 temp=node; 
 if(node->left==NULL)
 node=node->right; 
 else if(node->right==NULL) 
 node=node->left;
 free(temp); 
 } 
 } 
 return node; 
} 
int main() 
{ 
 int data,ch,i,n; 
 NODE *root=NULL; 
 while(1) 
 { 
 prinf("1.InserƟon\,\n2.Search\n3.Delete element\n4.INorder\n5.Preorder\n6.postorder\n7.Exit\n"); 
 prinf("Enter you choice:\n"); 
 scanf("%d",&ch); 
 switch(ch) 
 { 
 case 1:prinf("Enter the value:\n"); 
 scanf("%d",&n); 
 prinf("Enter the values to create BST tree");
 for(i=0;i<n;i++) 
 { 
 scanf("%d",&data); 
 root=createtree(root,data); 
 } 
 break; 
 case 2:prinf("Enter the element to search: ");
 scanf("%d",&data); 
 break; 
 case 3:prinf("Enter the element to delete:\n"); 
 scanf("%d",&data); 
 root=del(root,data); 
 break; 
 case 4:prinf("Inorder:\n"); 
 inorder(root); 
 break; 
 case 5:prinf("Preorder:\n"); 
 preorder(root); 
 break; 
 case 6:prinf("Post order:\n"); 
 postorder(root); 
 break; 
 case 7:exit(0); 
 } 
} 
} 
