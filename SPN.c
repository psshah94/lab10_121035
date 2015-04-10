#include<stdio.h>
void main()
{

	int i,j,n,temp,x,wt=0,ta=0;
	printf("Enter number of processes:");
	scanf("%d",&n);

	int b[n],p[n],w[n];
	printf("Enter burst time for processes:");
	for(i=0;i<n;i++)
	{

		scanf("%d",&b[i]);
		p[i]=i;

	}

	for(i=0;i<n;i++)
	{

		for(j=i;j<n;j++)
		{

			if(b[i]>b[j])
			{

				temp=b[i];
				x=p[i];
				b[i]=b[j];
				p[i]=p[j];
				b[j]=temp;
				p[j]=x;

			}

		}

	}

	w[0]=0;
	for(i=0;i<n;i++)
	{

		w[i+1]=w[i]+b[i];

	}
	for(i=0;i<n;i++)
	{

		ta+=w[i]+b[i];
		wt+=w[i];

	}

	ta/=n;
	wt/=n;

	printf("Average turnaround time is %d",ta);
	printf("Average waiting time is %d",wt);

}