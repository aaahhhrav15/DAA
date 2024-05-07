#include <stdio.h>

void strassen_multiply(int n, int m, int p, int q, int a[n][m], int b[p][q], int c[n][q]) {
   if (n == 1 && m == 1 && p == 1 && q == 1) {
       c[0][0] = a[0][0] * b[0][0];
       return;
   }

   int a11[n / 2][m / 2], a12[n / 2][m / 2], a21[n / 2][m / 2], a22[n / 2][m / 2];
   int b11[p / 2][q / 2], b12[p / 2][q / 2], b21[p / 2][q / 2], b22[p / 2][q / 2];
   int c11[n / 2][q / 2], c12[n / 2][q / 2], c21[n / 2][q / 2], c22[n / 2][q / 2];

   for (int i = 0; i < n / 2; i++) {
       for (int j = 0; j < m / 2; j++) {
           a11[i][j] = a[i][j];
           a12[i][j] = a[i][j + m / 2];
           a21[i][j] = a[i + n / 2][j];
           a22[i][j] = a[i + n / 2][j + m / 2];
       }
   }

   for (int i = 0; i < p / 2; i++) {
       for (int j = 0; j < q / 2; j++) {
           b11[i][j] = b[i][j];
           b12[i][j] = b[i][j + q / 2];
           b21[i][j] = b[i + p / 2][j];
           b22[i][j] = b[i + p / 2][j + q / 2];
       }
   }

   for (int i = 0; i < p / 2; i++) {
       for (int j = 0; j < q / 2; j++) {
           b12[i][j] = b12[i][j] - b22[i][j];
           b21[i][j] = b21[i][j] - b11[i][j];
       }
   }

   strassen_multiply(n / 2, m / 2, p / 2, q / 2, a11, b11, c11);
   strassen_multiply(n / 2, m / 2, p / 2, q / 2, a12, b21, c12);
   strassen_multiply(n / 2, m / 2, p / 2, q / 2, a11, b12, c21);
   strassen_multiply(n / 2, m / 2, p / 2, q / 2, a22, b22, c22);

   for (int i = 0; i < n / 2; i++) {
       for (int j = 0; j < q / 2; j++) {
           c[i][j] = c11[i][j] + c12[i][j];
           c[i][j + q / 2] = c21[i][j] + c22[i][j];
           c[i + n / 2][j] = c11[i][j] + c21[i][j];
           c[i + n / 2][j + q / 2] = c12[i][j] + c22[i][j];
       }
   }
}

int main() {
   int n, m, p, q;
   printf("Enter the number of rows and columns of the first matrix\n");
   scanf("%d %d", &n, &m);
   int a[n][m];
   printf("Enter the elements of the first matrix\n");
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           scanf("%d", &a[i][j]);
       }
   }

   printf("Enter the number of rows and columns of the second matrix\n");
   scanf("%d %d", &p, &q);
   int b[p][q];
   printf("Enter the elements of the second matrix\n");
   for (int i = 0; i < p; i++) {
       for (int j = 0; j < q; j++) {
           scanf("%d", &b[i][j]);
       }
   }

   if (m != p) {
       printf("Matrix multiplication not possible\n");
       return 0;
   }

   int c[n][q];
   strassen_multiply(n, m, p, q, a, b, c);

   printf("Resultant matrix after multiplication:\n");
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < q; j++) {
           printf("%d ", c[i][j]);
       }
       printf("\n");
   }

   return 0;
}