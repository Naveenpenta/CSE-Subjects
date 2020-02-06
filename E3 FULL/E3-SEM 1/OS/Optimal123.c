#include<stdio.h>
 
int main()
{
    int no_of_frames, no_of_pages, frames[1000], pages[3000], hit=0,find=0,temp[100],fifo[1000] ,flag1, flag2, flag3, i, j, k, pos, max,min, faults = 0,count=0,check=0,times[1000];
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
    printf("Enter page reference string: ");
    
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 =flag2=0,find=0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   find=1;
                   hit=j;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    count++;
                    flag2=1;
                    fifo[j]=count;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
            
        }
        
        if(flag2 == 0){
            
            check=0;
              for (j=0;j<no_of_frames;++j)
              {
              	times[j]=-1;
              	 for(k=i+1;k<no_of_pages;++k)
              	 {
              	 	if(frames[j]==pages[k])
              	 	{
              	 		check++;
              	 		times[j]=k;
              	 		break;
					   }
				   }
			  }
			  if(check==no_of_frames)
			  {
			
			  	 max = -100;
                pos = 0;
                
                for(j = 0; j < no_of_frames; ++j){
                    if(times[j] > max){
                        max = times[j];
                        pos = j;
                    }
                }     
			  }
			  else{
			  	      
						min=999;
                pos = 0;
                
                for(j = 0; j < no_of_frames; ++j){
                	if(times[j]==-1)
                	{
					
                    if(fifo[j] <min){
                        min = fifo[j];
                        pos = j;
                    }
                }
                }      
			  }
            
            frames[pos] = pages[i];
            faults++;
            count++;
            fifo[pos]=count;
        }
        
    
        if(find==0)
        {
		 printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t\n", frames[j]);
        }
        printf("\n");
    }
    else{
    	  
    	  printf("the page %d hittes\n",frames[hit]);
	}
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}
