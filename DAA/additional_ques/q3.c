#include <stdio.h>
#include <stdbool.h>

bool subset_sum(int set[], int n, int sum) {
  if (sum == 0) {
    return true;
  } else if (n == 0) {
    return false;
  } else if (set[n-1] > sum) {
    return subset_sum(set, n-1, sum);
  } else {
    return subset_sum(set, n-1, sum) || subset_sum(set, n-1, sum-set[n-1]);
  }
}

int main() {
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (subset_sum(set, n, sum) == true) {
    printf("There is a subset of the set with the given sum.\n");
  } else {
    printf("There is no subset of the set with the given sum.\n");
  }
  return 0;
}
