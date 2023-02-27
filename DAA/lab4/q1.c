#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10

int n;
int cost_matrix[MAX_N][MAX_N];

void generate_cost_matrix() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cost_matrix[i][j] = rand() % 10 + 1; // generate a random cost between 1 and 10
        }
    }
}

void print_cost_matrix() {
    int i, j;
    printf("Cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", cost_matrix[i][j]);
        }
        printf("\n");
    }
}

int assign_brute_force(int perm[]) {
    int i, j;
    int min_cost = 1000000; // initialize the minimum cost to a large number
    int cost;
    do {
        cost = 0;
        for (i = 0; i < n; i++) {
            cost += cost_matrix[i][perm[i]];
        }
        if (cost < min_cost) {
            min_cost = cost;
        }
    } while (next_permutation(perm, perm + n));
    return min_cost;
}

int main() {
    srand(time(NULL)); // seed the random number generator
    printf("Enter the number of workers/tasks (max %d): ", MAX_N);
    scanf("%d", &n);
    generate_cost_matrix();
    print_cost_matrix();
    int perm[MAX_N];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    int min_cost = assign_brute_force(perm);
    printf("Minimum cost: %d\n", min_cost);
    return 0;
}
