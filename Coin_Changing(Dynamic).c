#include <stdio.h>

void coin_changing(int purchase_amount, int amount_paid, int denomination[10]) 
{
    int dp[amount_paid - purchase_amount + 1];
    int coins_used[amount_paid - purchase_amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount_paid - purchase_amount; i++) 
    {
        dp[i] = 999999;
    }

    for (int i = 0; i < 10; i++) 
    {
        for (int j = denomination[i]; j <= amount_paid - purchase_amount; j++) 
        {
            if (dp[j - denomination[i]] + 1 < dp[j]) 
            {
                dp[j] = dp[j - denomination[i]] + 1;
                coins_used[j] = denomination[i];
            }
        }
    }

    printf("Minimum number of coins needed: %d\n", dp[amount_paid - purchase_amount]);

    printf("Denomination of coins used: ");
    int amount = amount_paid - purchase_amount;
    while (amount > 0) 
    {
        printf("%d ", coins_used[amount]);
        amount -= coins_used[amount];
    }
    printf("\n");
}

int main() 
{
    int purchase_amount, amount_paid, denomination[10];
    printf("Enter the purchase amount : ");
    scanf("%d", &purchase_amount);
    printf("Enter amount paid : ");
    scanf("%d", &amount_paid);
    printf("Enter denomination(enter 0 if finished)\n");
    for (int i = 0; i < 10; i++) 
    {
        int j;
        scanf("%d", &j);
        if (j == 0) 
        {
            break;
        }
        denomination[i] = j;
    }
    coin_changing(purchase_amount, amount_paid, denomination);
    return 0;
}
