// C Program to Implement the FCFS Disk Scheduling Algorithm
#include <stdio.h>
int main() {
   
    int total_head_movement=0;
    int n; ///To take total no. of cylinder
    
    printf("\nEnter the no. of cylinders to enter in Request Queue : ");
    scanf("%d",&n);
    
    int request_queue[n];
    printf("\n Enter the cylinders no. in Request queue :\n");
    
    for(int i=0 ; i<n ; i++){
        scanf("%d",&request_queue[i]);
    }
    
    int initial_pos;
    printf("\nEnter the initial position of RW head: ");
    scanf("%d",&initial_pos);
    
    for(int i=0;i<n;i++){
        total_head_movement += abs(initial_pos - request_queue[i]);
        initial_pos = request_queue[i];
    }
    
    printf("\nTotal No. of Head Movements = %d\n",total_head_movement);
    return 0;
}