#include <stdio.h>

void matrix_multiply(int A[][3], int B[][3], int C[][3], int n) {
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      C[i][j] = 0;
      for (k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void print_matrix(int A[][3], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int C[3][3];
  matrix_multiply(A, B, C, 3);
  printf("Matrix A:\n");
  print_matrix(A, 3);
  printf("Matrix B:\n");
  print_matrix(B, 3);
  printf("Matrix C = A * B:\n");
  print_matrix(C, 3);
  return 0;
}




// #include <stdio.h>
// #include <time.h>

// // ...

// int main() {
//   int n = 10;
//   int A[n][n], B[n][n], C[n][n];
//   int i, j;
//   clock_t start, end;
//   double cpu_time_used;

//   for (i = 0; i < n; i++) {
//     for (j = 0; j < n; j++) {
//       A[i][j] = i + j;


// // ...
// B[i][j] = i - j;
// }
// }

// start = clock();
// matrix_multiply(A, B, C, n);
// end = clock();
// cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

// printf("Time taken for %d x %d matrices: %f seconds\n", n, n, cpu_time_used);

// return 0;
// }