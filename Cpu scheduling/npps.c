#include <stdio.h>
#include <limits.h>

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  int p[n], at[n], bt[n], pr[n], ct[n], tat[n], wt[n], done[n];

  for(int i=0; i<n; i++){
    printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i+1);
    scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    p[i] = i+1;
    done[i] = 0;
  }

  int completed = 0, time = 0;

  while(completed < n){
    int idx = -1;
    int bestpr = INT_MAX;

    for(int i=0; i<n; i++){
      if(at[i] <= time && done[i] == 0){
        if(pr[i] < bestpr){
          bestpr = pr[i];
          idx = i;
        }
        else if(pr[i] == bestpr){
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

  float avgwt=0, avgtat=0;

  printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

  for(int i=0; i<n; i++){
    avgwt += wt[i];
    avgtat += tat[i];
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
  }

  printf("\nAverage Waiting Time = %.2f\n", avgwt/n);
  printf("Average Turnaround Time = %.2f\n", avgtat/n);

  return 0;
}