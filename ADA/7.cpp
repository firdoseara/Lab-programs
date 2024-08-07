#include<stdio.h>
#include<stdlib.h>
struct Item
{
	int value,weight;
};
int compare(const void *a,const void *b)
{
	double ratioA=((struct Item *)b)->value/(double)((struct Item *)b)->weight;
	double ratioB=((struct Item *)a)->value/(double)((struct Item *)a)->weight;
	return ratioA>ratioB?1:-1;
}
int discreteknap(struct Item items[],int n,int cap)
{
	qsort(items,n,sizeof(items[0]),compare);
	int totalvalue=0;
	int remainingcap=cap;
	for(int i=0;i<n;i++)
	{
		if(items[i].weight<=remainingcap)
		{
			totalvalue+=items[i].value;
			remainingcap-=items[i].weight;
		}
		else{
			double fraction=(double)remainingcap/(double)items[i].weight;
			totalvalue+=items[i].value * fraction;
			break;
		}
	}
	return totalvalue;
}
double contiknap(struct Item items[],int n,int cap)
{
	qsort(items,n,sizeof(items[0]),compare);
	double totalvalue=0;
	for(int i=0;i<n;i++)
	{
		if(items[i].weight<=cap)
		{
			totalvalue+=items[i].value;
			cap-=items[i].weight;
		}
		else{
			totalvalue+=items[i].value * ((double)cap/(double)items[i].weight);
			break;
		}
	}
	return totalvalue;
}
int main()
{
	int n,cap;
	printf("Enter the no of items:");
	scanf("%d",&n);
	struct Item items[n];
	printf("Enter the value and weight of each item:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&items[i].value,&items[i].weight);
	}
	printf("Enter the capacity of knapsack");
	scanf("%d",&cap);
	int maxvalue=discreteknap(items,n,cap);
	printf("Maximum value in discrete knapsack:%d\n",maxvalue);
	double maxvaluecont=contiknap(items,n,cap);
	printf("Maximum value in continuous kanpsack:%.2f\n",maxvaluecont);
	return 0;
}