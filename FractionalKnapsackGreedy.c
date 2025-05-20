#include <stdio.h>

int main() {
    float weight[50], profit[50], ratio[50];
    float Totalvalue = 0.0, temp, capacity, amount;
    int n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d]:\n", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of knapsack:\n");
    scanf("%f", &capacity);

    // Calculate profit/weight ratio
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by descending ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // Swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    printf("\nKnapsack problem using Greedy Algorithm:\n");
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            // Take full item
            printf("Item[%d] taken completely (100%%)\n", i);
            Totalvalue += profit[i];
            capacity -= weight[i];
        } else {
            // Take fraction of item
            float fraction = capacity / weight[i];
            Totalvalue += profit[i] * fraction;
            printf("Item[%d] taken partially (%.2f%%)\n", i, fraction * 100);
            break; // Knapsack is now full
        }
    }

    printf("\nThe maximum value is: %.2f\n", Totalvalue);
    return 0;
}
