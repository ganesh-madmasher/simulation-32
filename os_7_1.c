#include<stdio.h>
#define N 10  
//pid is  id
//pp is  priority
//bt is  burst time
//at is  arrival time















typedef struct
{
      int pid, at,bt,pp;
      int q, ready;
}pxgf_strq;
int eueuQ(int rrt1)
{
      if(rrt1==0 || rrt1==1 || rrt1==2 || rrt1==3)
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
      int imit, nouct, pmet_ssecorp, kalam, j, y;
      pxgf_strq temp;
      printf("Enter Total Number of Processes:\t");
      scanf("%d",&imit);  
      pxgf_strq process[imit];
      for(nouct=0;nouct<imit;nouct++)
      {
            printf("\nProcess ID:\t");
            scanf("%d", &process[nouct].pid);
            printf("Arrival Time: ");
            scanf("%d", &process[nouct].at);
            printf("Burst Time: ");
            scanf("%d", &process[nouct].bt);
            printf("Process Priority: ");
            scanf("%d", &process[nouct].pp);
            pmet_ssecorp = process[nouct].pp;
            process[nouct].q = eueuQ(pmet_ssecorp);
            process[nouct].ready = 0;
      }
      kalam = process[0].bt;
      for(y=0;y<imit;y++)
      {
            for(nouct=y;nouct<imit;nouct++)
            {
                  if(process[nouct].at < kalam)
                  {
                        process[nouct].ready = 1;
                  }
            }
            for(nouct=y;nouct<imit-1;nouct++)
            {
                  for(j=nouct+1; j<imit; j++)
                  {
                        if(process[nouct].ready == 1 && process[j].ready == 1)
                        {
                              if(process[nouct].q == 2 && process[j].q == 1)
                              {
                                    temp = process[nouct];
                                    process[nouct] = process[j];
                                    process[j] = temp;
                              }
                        }
                  }
            }
            for(nouct=y;nouct<imit-1;nouct++)
            {
                  for(j=nouct+1;j<imit;j++)
                  {
                        if(process[nouct].ready==1 && process[j].ready==1)
                        {
                              if(process[nouct].q==1 && process[j].q==1)
                              {
                                    if(process[nouct].bt > process[j].bt)
                                    {
                                          temp=process[nouct];
                                          process[nouct]=process[j];
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
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].pid, kalam, kalam + process[y].bt);
            kalam = kalam + process[y].bt;
            for(nouct=y; nouct<imit; nouct++)
            {
                  if(process[nouct].ready==1)
                  {
                        process[nouct].ready=0;
                  }
            }
      }
      return 0;
}
