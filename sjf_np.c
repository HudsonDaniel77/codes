#include <stdio.h>

int main()
{
    int n, i;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    int done[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        done[i] = 0;
    }

    int completed = 0, time = 0;

    while(completed < n)
    {
        int min = -1;

        // Find shortest available process
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && done[i] == 0)
            {
                if(min == -1 || bt[i] < bt[min])
                    min = i;
            }
        }

        // No process has arrived
        if(min == -1)
        {
            time++;
            continue;
        }

        // Execute selected process
        time += bt[min];

        ct[min] = time;
        tat[min] = ct[min] - at[min];
        wt[min] = tat[min] - bt[min];

        done[min] = 1;
        completed++;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
