#include<stdio.h>
#define max 20
int main()
{
     int AT[max]={0}; //For Arival time
    int BT[max]; //For Burst time
    int CT[max]; //For completion time
    int WT[max]; //For Waiting time
    int TAT[max]; //For turn around time
    int i,n;

    printf("\nEnter total number of processes:\n");
    scanf("%d",&n);

    printf("\nEnter Arival time for each process:\n");
    for(i=0 ; i<n ; i++)
      scanf("%d ",&AT[i]);

    printf("\nEnter Burst time for each process:\n");
    for(i=0 ; i<n ; i++){
      scanf("%d ",&BT[i]);
    }

    int GC[4]={0}; //Gantt Chart
    
    for(i=0 ; i<n ;i++)
    {
      if(i==0)
         GC[i] = BT[i];
      
      else
         GC[i]=GC[i-1]+BT[i];

      
    }
   printf("\nValue inside Gantt Chart :\n");
   for(int i=0;i<n;i++)
   {
      printf("%d ",GC[i]);
   }

   for(i=0;i<n;i++){  //Time inside gantt chart is CT
      CT[i]=GC[i];
   }
   printf("\nTime inside Completion Time (CT):\n");
   for(i=0;i<n;i++)
   {
      printf("%d ",CT[i]);
   }
   
   int TAT_sum=0;
    
   for(i=0;i<n;i++){
      TAT[i]=CT[i]-AT[i];
      TAT_sum+=TAT[i];
   }
   float avg_TAT = (float)TAT_sum/4.0;

   printf("\nTime inside TAT :\n");
   for(int i=0;i<n;i++)
   {
      printf("%d ",TAT[i]);
   }
   
   int WT_sum=0;
   for(i=0;i<n;i++){
      WT[i]=TAT[i]-BT[i];
      WT_sum+=WT[i];
   }
   float avg_WT =(float) WT_sum/4.0;

   printf("\nTime inside WT :\n");
   for(int i=0;i<n;i++)
   {
      printf("%d ",WT[i]);
   }
   
   printf("\nAverage TAT is : %.2f ",avg_TAT);
   printf("\nAverage WT is : %.2f ",avg_WT);
           
  return 0;
}