#include<stdio.h>
main()
{

int f,p,f1[20],p1[20],head,head1,c=0,count=0,diff,min=0,max=199,i,temp,j;
printf("enter the no. of pages");
scanf("%d",&p);
printf("enter the pages");
for(i=0;i<p;i++)
{
scanf("%d",&p1[i]);	
}
printf("enter the head");
scanf("%d",&head);
head1=head;
for(i=0;i<p;i++)
{
	for(j=i;j<p;j++)
	{
		if(p1[i]>p1[j])
		{
			temp=p1[i];
			p1[i]=p1[j];
			p1[j]=temp;
		}
	}
}
for(i=0;i<p;i++)
{
	if(head<p1[i])
	{
	diff=p1[i]-head;
	printf("%d\n",diff);
	count=count+diff;
	head=p1[i];	
	}
}
diff=max-head;
count=count+diff;
head=max;
diff=head-min;
count=count+diff;
head=min;
for(i=0;i<p;i++)
{
	if(head1>p1[i])
	{
	
	diff=p1[i]-head;
	printf("%d\n",diff);
	count=count+diff;
	head=p1[i];
}
}

printf(" %d the toatl no. of head moments",count);
}












