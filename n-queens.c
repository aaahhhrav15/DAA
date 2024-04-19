#include <stdio.h>
#include <stdbool.h>

#define N 10

int board[N][N];
int n;

bool isSafe(int row, int col) 
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool NQueens(int col) 
{
    if (col >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++) 
    {
        if (isSafe(i, col)) 
        {
            board[i][col] = 1;
            if (NQueens(col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }

    return false;
}

void print() 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    printf("Enter the no. of queens (board size): ");
    scanf("%d", &n);

    if (n <= 0 || n > N) 
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (NQueens(0)) 
    {
        print();
    } 
    else 
    {
        printf("Solution does not exist for the given board size.\n");
    }

    return 0;
}





