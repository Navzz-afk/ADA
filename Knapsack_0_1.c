#include <stdio.h>

// Function to return the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int weight[], int profit[], int n, int capacity) {
    int i, w;
    int K[n + 1][capacity + 1];

    // Build the DP table K[][] bottom up
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(profit[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Optional: Print the items included
    printf("\nItems included:\n");
    w = capacity;
    for (i = n; i > 0 && w > 0; i--) {
        if (K[i][w] != K[i - 1][w]) {
            printf("Item %d (Weight: %d, Profit: %d)\n", i, weight[i - 1], profit[i - 1]);
            w -= weight[i - 1];
        }
    }

    return K[n][capacity];
}

int main() {
    int n, capacity;
    int weight[50], profit[50];
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit for each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item[%d] - Weight Profit: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    int maxProfit = knapsack(weight, profit, n, capacity);

    printf("\nMaximum profit: %d\n", maxProfit);
    return 0;
}
