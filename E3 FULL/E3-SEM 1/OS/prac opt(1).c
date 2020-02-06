#include<stdio.h>
#include<stdbool.h>
main()
{
	int p[20],f[10],j,i,k,m,n,x,s,found=0,count=0,counts=0,count1=0,count2=0,c[20],foun[20],min,max;
	bool check;
	printf(" enter the framesize\n");
	scanf("%d",&m);
	printf("enter the pagesize\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(j=0;j<m;j++)
	{
		f[j]=-1;
	}
	x=0;
	while(counts!=m)
	{
		for(i=x;i<n;i++)
		{
			k=i;
			check=false;
			for(j=0;j<m;j++)
			{
				if(f[j]==p[k])
				{
					printf("%d page is hit\n",p[k]);
					check=true;
					break;
				}
			}
			if(check==true)
			{
				break;
			}
			else
			{
				for(j=0;j<m;j++)
				{
					found=0;
					if(f[j]==-1)
					{
						f[j]=p[k];
						found=1;
						counts++;
						c[j]=count++;
						printf(" page is %d\n",p[k]);
						for(j=0;j<m;j++)
						{
							printf("%d\n",f[j]);
						}
						break;
					}
					
				}
				if(found==1)
				{
					break;
				}
			}
		}
		if(counts==m)
		{
			break;
		}
		else
		{
			x=x+1;
			continue;
		}
	}
	i=x+1;
	x=i;	
		while(x!=n)
	{
		for(i=x;i<n;i++)
		{
			k=i;
			check=false;
			for(j=0;j<m;j++)
			{
				if(f[j]==p[k])
				{
					printf("%d page is hit\n",p[k]);
					check=true;
					break;
				}
			}
			if(check==true)
			{
				break;
			}
			else
			{
				for(j=0;j<m;j++)
				{
					foun[j]=0;
				}
				found=0;
				for(j=0;j<m;j++)
				{
					
					for(i=k;i<n;i++)
					{
						if(f[j]==p[i])
						{
							found++;
							foun[j]=i;
							printf("foun[%d] is %d\n",j,i);
							break;
						}
					}
				}
				printf(" found is %d and m is %d\n",found,m);
				if(found==0)
				{
					printf("_____in found==0_____\n");
					min=999;
					for(j=0;j<m;j++)
					{
						if(c[j]<min)
						{
							min=c[j];
							s=j;
						}
					}
					j=s;
					f[j]=p[k];
					count++;
					c[j]=count;
					printf("page is %d\n",p[k]);
					for(j=0;j<m;j++)
					{
						printf("%d\n",f[j]);
					}
					
				}
				else if(found>0 && found<m)
				{
						printf("_____in found>0_____\n");
					min=999;
					for(j=0;j<m;j++)
					{
						if(foun[j]==0 && c[j]<min)
						{
							min=c[j];
							s=j;
						}
					}
					j=s;
					f[j]=p[k];
					count++;
					c[j]=count;
					printf("page is %d\n",p[k]);
					for(j=0;j<m;j++)
					{
						printf("%d\n",f[j]);
					}
					
					
				}
				else if(found==m)
				{
					printf("in ____found==m_____\n");
					max=-999;
					for(j=0;j<m;j++)
					{
						printf("___in max____\n");
						if(foun[j]>max)
						{
							max=foun[j];
							s=j;
							printf("max is %d\n",max);
						}
					}
					j=s;
					f[j]=p[k];
					count++;
					c[j]=count;
					printf("page is %d\n",p[k]);
					for(j=0;j<m;j++)
					{
						printf("%d\n",f[j]);
					}
					
				}
				break;
	    	}
	    }
		if(x==n)
		{
			break;
		}
		else
		{
			x=x+1;
			continue;
		}
	}
}
