#include<stdio.h>
#include<stdlib.h>
int dist[10];

void dj(int n, int s, int cost[10][10]) {
    int i, count = 1, min, v, visited[10];

    for (i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    visited[s] = 1;
    dist[s] = 0;

    while (count < n) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1;
        count++;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] > dist[v] + cost[v][i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }
}

int main()
{
    int i,j,n,cost[10][10],s;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d->%d? ",i,j);
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
            cost[i][j]=999;
            }
        }
    }
    printf("Enter the source node: ");
    scanf("%d",&s);
    dj(n,s,cost);
    printf("SHORTEST DISTANCE\n");
    for(i=0;i<n;i++)
    {
        printf("%d -> %d= %d\n",s,i,dist[i]);
    }
}
