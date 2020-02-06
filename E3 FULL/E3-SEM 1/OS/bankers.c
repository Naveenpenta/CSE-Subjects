#include<stdio.h>
main()
{
	int alloc[10][10],max[10][10],n,i,j,m,need[10][10],check[10],k,p,q,work[10];
	printf("enter the n value for [n*m]\n");
	scanf("%d",&n);
		printf("enter the m value for [n*m]\n");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("enter the value for alloc[%d][%d] :",i,j);
			scanf("%d",&alloc[i][j]);
		}
	}
	// displaying array matrix
	printf("ALLOCATION MATRIX\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",alloc[i][j]);
			
		}
		printf("\n");
	}
	//scaning the max matrix
		for(i=0;i<n;i++)
	    {
		for(j=0;j<m;j++)
		{
			printf("enter the value for max[%d][%d] :",i,j);
			scanf("%d",&max[i][j]);
		}
	}
	//printing the max matrix
	printf("MAX MATRIX\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",max[i][j]);
			
		}
			printf("\n");
	}
	printf("need matrix \n");
	//FINDING THE NEED MARTRIX..
		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			
		}
	}
	//printing the need matrix..
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",need[i][j]);
			
		}
			printf("\n");
	}
	// work matrix.
		for(i=0;i<m;i++)
	    {
			printf("enter the value for (available) work[%d] :",i);
			scanf("%d",&work[i]);
		}
	
	printf("WORK MATRIX\n");
	// available..
		for(i=0;i<m;i++)
		{
			
			printf("%d\t",work[i]);
			
		}
			printf("\n");
	for(i=0;i<n;i++)
	{
		check[i]=0;
	}
	/// CODE FOR BANKERS...
	for(i=0;i<n;i++)
	{
		if(check[i]==0)
		{
			j=0;
			while(j!=m)
			{
				q=j;
				if(need[i][j]>work[q])
				{
					
					check[i]=1;
					break;
				}
				j++;
			}
			if(check[i]==0)
			{
				j=0;
				printf("reached work..\n");
				while(j!=m)
				{
					q=j;
					work[j]=alloc[i][j]+work[q];
					printf("%d\t",work[j]);
					j++;
				}
				printf("\n");
				printf("p[%d] is safe\n",i);
		    }
        	}	
		}
	// for the need in hold..
	for(i=0;i<n;i++)
	{
		int count=0;
		if(check[i]==1)
		{
			j=0;
			while(count!=m)
			{
				q=j;
				if(need[i][j]>work[q])
				{
				
					check[i]=1;
				}
				else
				{
					if(count==m-1)
					{	
						check[i]=0;	
					}
				}
				j++;
				count++;
			}
			
		
		if(check[i]==0)
		{
				j=0;
				while(j!=m)
				{
					q=j;
					work[j]=alloc[i][j]+work[q];
					j++;
				}
				printf("p[%d] is safe\n",i);
		}
	}
  }
                printf(".......after hold......\n");
              	printf("___________ work updated_______\n");
				for(j=0;j<m;j++)
				{
					
					printf("%d\t",work[j]);
					
				}
					printf("\n");
	    	for(i=0;i<n;i++){
	    		if(check[i]==1){
	    			printf("the process %d is in deadlock\n",i);
				}
			}	
}

