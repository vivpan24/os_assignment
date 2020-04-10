#include<stdio.h> 
#define N 10  

typedef struct 
{ 
      int pid, at,bt,pp;
      int q, ready; 
}process_structure; 
int Queue(int t1) 
{ 
      if(t1==0 || t1==1 || t1==2 || t1==3) 
      { 
            return 1; 
      } 
      else
      {
            return 2; 
      }
}
int main() 
{ 
      int limit, count, temp_process, time, j, y; 
      process_structure temp; 
      printf("Enter Total Number of Processes:\t"); 
      scanf("%d",&limit);  
      process_structure process[limit]; 
      for(count=0;count<limit;count++) 
      { 
            printf("\nProcess ID:\t"); 
            scanf("%d", &process[count].pid); 
            printf("Arrival Time: "); 
            scanf("%d", &process[count].at); 
            printf("Burst Time: "); 
            scanf("%d", &process[count].bt); 
            printf("Process Priority: "); 
            scanf("%d", &process[count].pp); 
            temp_process = process[count].pp; 
            process[count].q = Queue(temp_process);
            process[count].ready = 0; 
      }
      time = process[0].bt; 
      for(y=0;y<limit;y++) 
      { 
            for(count=y;count<limit;count++) 
            { 
                  if(process[count].at < time) 
                  {
                        process[count].ready = 1; 
                  } 
            } 
            for(count=y;count<limit-1;count++) 
            {
                  for(j=count+1; j<limit; j++) 
                  { 
                        if(process[count].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[count].q == 2 && process[j].q == 1) 
                              { 
                                    temp = process[count]; 
                                    process[count] = process[j]; 
                                    process[j] = temp; 
                              } 
                        } 
                  } 
            } 
            for(count=y;count<limit-1;count++) 
            { 
                  for(j=count+1;j<limit;j++) 
                  {
                        if(process[count].ready==1 && process[j].ready==1) 
                        { 
                              if(process[count].q==1 && process[j].q==1) 
                              { 
                                    if(process[count].bt > process[j].bt) 
                                    { 
                                          temp=process[count]; 
                                          process[count]=process[j]; 
                                          process[j]=temp; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            } 
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].pid, time, time + process[y].bt); 
            time = time + process[y].bt; 
            for(count=y; count<limit; count++) 
            { 
                  if(process[count].ready==1) 
                  { 
                        process[count].ready=0; 
                  } 
            } 
      } 
      return 0; 
}
