#include <stdio.h>
#include <limits.h>

int main() {
  int n, completed = 0, time = 0, highest;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  int at[n], bt[n], pr[n], rt[n], ct[n], tat[n], wt[n], start[n];

  for (int i = 0; i < n; i++) {
    printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);
    scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    rt[i] = bt[i];
    start[i] = -1;
  }

  while (completed < n) {
    highest = -1;
    int best_pr = INT_MAX;

    for (int i = 0; i < n; i++) {
      if (at[i] <= time && rt[i] > 0) {
        if (pr[i] < best_pr) {
          best_pr = pr[i];
          highest = i;
        } else if (pr[i] == best_pr) {
          if (at[i] < at[highest]) {
            highest = i;
          }
        }
      }
    }

    if (highest == -1) {
      time++;
      continue;
    }

    if (start[highest] == -1)
      start[highest] = time;

    rt[highest]--;
    time++;

    if (rt[highest] == 0) {
      completed++;
      ct[highest] = time;
    }
  }

  float avgwt = 0, avgtat = 0, avgrt = 0;

  printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

  for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    int rt_time = start[i] - at[i];
    avgwt += wt[i];
    avgtat += tat[i];
    avgrt += rt_time;

    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
           i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i], rt_time);
  }

  printf("\nAverage WT = %.2f\nAverage TAT = %.2f\nAverage RT = %.2f\n",
         avgwt / n, avgtat / n, avgrt / n);

  return 0;
}