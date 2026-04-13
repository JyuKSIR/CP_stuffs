#include <stdio.h>
#include <limits.h>

int main() {
  int n, completed = 0, time = 0, smallest;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], start[n], end[n];

  for (int i = 0; i < n; i++) {
    printf("Enter Arrival and Burst time for P%d: ", i + 1);
    scanf("%d %d", &at[i], &bt[i]);
    rt[i] = bt[i];
    start[i] = -1;
  }

  while (completed < n) {
    smallest = -1;
    int min_rt = INT_MAX;

    for (int i = 0; i < n; i++) {
      if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
        min_rt = rt[i];
        smallest = i;
      }
    }

    if (smallest == -1) {
      time++;
      continue;
    }

    if (start[smallest] == -1)
      start[smallest] = time;

    rt[smallest]--;
    time++;

    if (rt[smallest] == 0) {
      completed++;
      ct[smallest] = time;
    }
  }

  float avgwt = 0, avgtat = 0, avgrt = 0;

  printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

  for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    int rt_time = start[i] - at[i];
    avgwt += wt[i];
    avgtat += tat[i];
    avgrt += rt_time;

    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
           i + 1, at[i], bt[i], ct[i], tat[i], wt[i], rt_time);
  }

  printf("\nAverage WT = %.2f\nAverage TAT = %.2f\nAverage RT = %.2f\n",
         avgwt / n, avgtat / n, avgrt / n);

  return 0;
}