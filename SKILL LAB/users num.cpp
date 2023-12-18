#include<stdio.h>
#include<stdlib.h>
#define MAX_USERS 100
struct Node {
	int data;
	struct Node*next;
	
};
struct Graph {
	int numUsers;
	struct Node* adjList[MAX_USERS];
};
struct Graph* createGraph(int numUsers){
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->numUsers = numUsers;
	for (int i=0;i<numUsers; ++i)
	{
		graph->adjList[i]=NULL;
		
	}
	return graph;
	
}
void addEdge(struct Graph*graph,int user1,int user2)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data= user2;
	newNode->next = graph->adjList[user1];
	graph->adjList[user1]=newNode;
	
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = user1;
	newNode->next = graph->adjList[user2];
	graph->adjList[user2]= newNode;
}
void printFriends(struct Graph* graph,int user){
	printf("	Friends of users %d:",user);
	int visited[MAX_USERS]={0};
	int queue[MAX_USERS];
	int front =0,rear=0;
	visited[user] = 1;
	queue[rear++]=user;
	while (front <rear){
		int currentUser = queue[front++];
		struct Node* temp = graph->adjList[currentUser];
		while (temp!= NULL){
			int friendUser = temp->data;
			if (!visited [friendUser]){
				visited[friendUser]=1;
				printf("%d ",friendUser);
				queue[rear++] = friendUser;
			}
			temp = temp->next;
			
			
		}
	}
	printf("\n");
}
int main() {
	struct Graph* socialGraph = createGraph(6);
	addEdge(socialGraph,0,1);
	addEdge(socialGraph,0,2);
	addEdge(socialGraph,1,3);
	addEdge(socialGraph,2,4);
	addEdge(socialGraph,3,5);
	printFriends(socialGraph,0);
	return 0;
	
}