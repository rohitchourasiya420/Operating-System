#include<stdio.h>
int main(){
	int n,i;
	printf("enter no. of processes:");
	scanf("%d",&n);
	float arr[n][6];
	float tat=0;
	float wt=0;
	for(i=0;i<n;i++){
		arr[i][0]=i+1;
	}
	for(i=0;i<n;i++){
		printf("enter arrival time of p%.0f=",arr[i][0]);
		scanf("%f",&arr[i][1]);
	}
	for(i=0;i<n;i++){
		printf("enter burst time of p%.0f=",arr[i][0]);
		scanf("%f",&arr[i][2]);
	}
	arr[0][3]=0+arr[0][2];
	arr[0][4]=arr[0][3]-arr[0][1];
	arr[0][5]=arr[0][4]-arr[0][2];
	tat+=arr[0][4];
	wt+=arr[0][5];
	for(i=1;i<n;i++){
		if(arr[i][1]<arr[i-1][3]){
			arr[i][3]=arr[i-1][3]+arr[i][2];
			arr[i][4]=arr[i][3]-arr[i][1];
			arr[i][5]=arr[i][4]-arr[i][2];
			tat+=arr[i][4];
			wt+=arr[i][5];
		}
		else{
			arr[i][3]=arr[i][1]+arr[i][2];
			arr[i][4]=arr[i][3]-arr[i][1];
			arr[i][5]=arr[i][4]-arr[i][2];
			tat+=arr[i][4];
			wt+=arr[i][5];
		}
	}
	for(i=0;i<n;i++){
		for(int j=0;j<6;j++){
			printf("%.1f\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("%.2f\n",(tat/(float)n));
	printf("%.2f",(wt/(float)n));
	return 0;
}