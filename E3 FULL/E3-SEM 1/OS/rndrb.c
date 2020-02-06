#include<stdio.h>
int sort(int p[],int at[],int bt[],int bt1[],int at1[],int n,int i,int j){
	int temp,temp1,temp2,temp3,temp4;
for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(at[i]>at[j]){
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp1=bt[i];
				bt[i]=bt[j];
				bt[j]=temp1;
				temp2=p[i];
				p[i]=p[j];
				p[j]=temp2;
				temp3=bt1[i];
				bt1[i]=bt1[j];
				bt1[j]=temp3;
				temp4=at1[i];
				at1[i]=at1[j];
				at1[j]=temp4;
				
				
				}
		}
	}
} 
main(){
	int n;
	printf("enter the number of process\n");
	scanf("%d",&n);
	int at[10],bt[10],ct[10],tt[10],wt[10],i,p[10],bt1[10],j,at1[10];
	int att,awt,sum=0,sum1=0;
	for(i=0;i<n;i++){
		p[i]=i+1;
	
		printf("enter arrival time of p%d:",i+1);
		scanf("%d",&at[i]);
		printf("enter the burst time of p%d:",i+1);
		scanf("%d",&bt[i]);
		bt1[i]=bt[i];
		at1[i]=at[i];
		
	}
	int tq;
	printf("enter the time quantum\n");
	scanf("%d",&tq);
		sort(p,at,bt,bt1,at1,n,i,j);
	int nat=at[0],min,k=0;
	while(1){
		for(i=0;i<n;i++){
			if(bt[i]!=0){
				k=i;
				min=at[i];
				break;	
			}
		}
		printf("minimun valus:%d",min);
				if(bt[k]==0){
			break;
		}
		
		for(i=0;i<n;i++){
			//printf("\nat[i]value:%d",at[i]);
				if(at[i]<min&&bt[i]!=0){
					min=at[i];
					k=i;
				}
				else if(at[i]==min&&bt[i]!=0){
					
					if(at1[k]<at1[i]){
							printf("\nat[k]value:%d",at1[k]);
						min=at[i];
						k=i;
						}
				}
			}
			i=k;
			
					if(at[i]<=nat&&bt[i]!=0){
						if(bt[i]>=tq)
						{		
						at[i]=nat+tq;
						bt[i]=bt[i]-tq;
						ct[i]=at[i];
						nat=at[i];
						printf("pricrss p%d\n",p[i]);
					}					
					else if(bt[i]<tq){
						ct[i]=nat+bt[i];
						bt[i]=0;
						at[i]=ct[i];
						printf("pricrss p%d\n",p[i]);
						nat=ct[i];
					
					}
						
					}
					  else if(at[i]>nat&&bt[i]!=0){
					  	if(bt[i]>=tq)
						{		
						at[i]=at[i]+tq;
						bt[i]=bt[i]-tq;
						ct[i]=at[i];
						nat=at[i];
						printf("pricrss p%d\n",p[i]);
					}					
					else if(bt[i]<tq){
						ct[i]=at[i]+bt[i];
						bt[i]=0;
						at[i]=ct[i];
						printf("pricrss p%d\n",p[i]);
						nat=ct[i];
					
					}
			}
	}
float avg;
		for(i=0;i<n;i++){
			tt[i]=ct[i]-at1[i];
			wt[i]=tt[i]-bt1[i];
			sum=sum+tt[i];
		}
	avg=sum/n;
	printf("avreage tt %d\n",avg);
		printf("\n process  at\t bt\t ct \t tt\t wt\n");
		for(i=0;i<n;i++){
			printf("\np%d\t %d\t %d\t%d\t %d\t %d",p[i],at1[i],bt1[i],ct[i],tt[i],wt[i]);
		}
	}

