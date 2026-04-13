#include <stdio.h>

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  int p[n], at[n], bt[n], ct[n], tat[n], wt[n];

  for(int i=0; i<n; i++){
    printf("Enter Arrival and Burst time for P%d: ", i+1);
    scanf("%d %d", &at[i], &bt[i]);
    p[i] = i+1;
  }

  // Sort by Arrival Time
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      if(at[i] > at[j]){
        int t = at[i];
        at[i] = at[j];
        at[j] = t;

        t = bt[i];
        bt[i] = bt[j];
        bt[j] = t;

        t = p[i];
        p[i] = p[j];
        p[j] = t;
      }
    }
  }

  ct[0] = at[0] + bt[0];

  for(int i=1; i<n; i++)
    ct[i] = (ct[i-1] > at[i] ? ct[i-1] : at[i]) + bt[i];

  float avgwt=0, avgtat=0;

  printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

  for(int i=0; i<n; i++){
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    avgwt += wt[i];
    avgtat += tat[i];
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
  }

  printf("\nAverage Waiting Time = %.2f\n", avgwt/n);
  printf("Average Turnaround Time = %.2f\n", avgtat/n);

  return 0;
}