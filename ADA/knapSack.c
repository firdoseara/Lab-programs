#include<stdio.h>
int max(int a,int b)
{
        return(a>b?a:b);
}
int knapsack(int W,int wt[],int val[],int n)
{
        int i,w;
        int dp[n+1][W+1];
        for(i=0;i<=n;i++)
        {
                for(w=0;w<=W;w++)
                {
                        if(i==0||w==0)
                                dp[i][w]=0;
                        else if(wt[i-1]<=w)
                                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
                        else
                                dp[i][w]=dp[i-1][w];
                }
        }
        return dp[n][W];
}
int main()
{
        int n,W;
        printf("Enter no of items: ");
        scanf("%d",&n);
        int val[n],wt[n];
        printf("Enter value and weight of each item:\n");
        for(int i=0;i<n;i++)
        {
                scanf("%d%d",&val[i],&wt[i]);
        }
        printf("Enter the capacity of knapsack:\n");
        scanf("%d",&W);
        int maxValue=knapsack(W,wt,val,n);
        printf("Maximum value in knapsack:%d\n",maxValue);
        return 0;
}

