#include <stdio.h>

int main() {
  int n, completed = 0, time = 0, tq;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], start[n];

  for (int i = 0; i < n; i++) {
    printf("Enter Arrival and Burst time for P%d: ", i + 1);
    scanf("%d %d", &at[i], &bt[i]);
    rt[i] = bt[i];
    start[i] = -1;
  }

  printf("Enter Time Quantum: ");
  scanf("%d", &tq);

  while (completed < n) {
    int found = 0;

    for (int i = 0; i < n; i++) {
      if (at[i] <= time && rt[i] > 0) {
        found = 1;

        if (start[i] == -1)
          start[i] = time;

        if (rt[i] > tq) {
          rt[i] -= tq;
          time += tq;
        } else {
          time += rt[i];
          rt[i] = 0;
          completed++;
          ct[i] = time;
        }
      }
    }

    if (!found)
      time++;
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
