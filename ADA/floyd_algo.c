#include<stdio.h>
#define V 4
void printSolution(int dist[][V]);
void floydWarshall(int graph[][V])
{
        int dist[V][V],i,j,k;
        for(i=0;i<V;i++)
                for(j=0;j<V;j++)
                        dist[i][j]=graph[i][j];
        for(k=0;k<V;k++)
        {
                for(i=0;i<V;i++)
                {
                        for(j=0;j<V;j++)
                        {
                                if(dist[i][k]+dist[k][j]<dist[i][j])
                                        dist[i][j]=dist[i][k]+dist[k][j];
                        }
                }
        }
        printSolution(dist);
}
void printSolution(int dist[][V])
{
        printf("Following matrix shows the shortest distance between every pair of vertices.\n");
        for(int i=0;i<V;i++)
        {
                for(int j=0;j<V;j++)
                {
                        if(dist[i][j]==9999)
                                printf("%7s","INF");
                        else
                                printf("%7d",dist[i][j]);
                }
                printf("\n");
        }
}
int main()
{
        int graph[V][V]={{0,5,9999,10},
                {9999,0,3,9999},
                {9999,9999,0,1},
                {9999,9999,9999,0}
        };
        floydWarshall(graph);
        return 0;
}


                                                                                                                                                      1,17          Top

