#include <stdio.h>
#include <limits.h>

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  int p[n], at[n], bt[n], ct[n], tat[n], wt[n], done[n];

  for(int i=0; i<n; i++){
    printf("Enter Arrival and Burst time for P%d: ", i+1);
    scanf("%d %d", &at[i], &bt[i]);
    p[i] = i+1;
    done[i] = 0;
  }

  int completed = 0, time = 0;

  while(completed < n){
    int idx = -1;
    int minbt = INT_MAX;

    for(int i=0; i<n; i++){
      if(at[i] <= time && done[i] == 0){
        if(bt[i] < minbt){
          minbt = bt[i];
          idx = i;
        }
        else if(bt[i] == minbt){
          if(at[i] < at[idx]){
            idx = i;
          }
        }
      }
    }

    if(idx == -1){
      time++;
    }
    else{
      ct[idx] = time + bt[idx];
      time = ct[idx];
      tat[idx] = ct[idx] - at[idx];
      wt[idx] = tat[idx] - bt[idx];
      done[idx] = 1;
      completed++;
    }
  }

  float avgwt = 0, avgtat = 0;

  printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

  for(int i=0; i<n; i++){
    avgwt += wt[i];
    avgtat += tat[i];
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
  }

  printf("\nAverage Waiting Time = %.2f\n", avgwt/n);
  printf("Average Turnaround Time = %.2f\n", avgtat/n);

  return 0;
}