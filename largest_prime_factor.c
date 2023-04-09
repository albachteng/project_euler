/* The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime
 * factor of the number 600851475143 ? */

#include <math.h>
#include <stdio.h>

#define MAXINDEX 1000
unsigned long factor(long n);
unsigned long factors[MAXINDEX];
int i = 0;

int main() {
  printf("%lu\n", factor(600851475143));
  return 1;
}

unsigned long factor(long n) {
  unsigned long curr = n;
  unsigned long root = sqrt(n);
  if (n == 2 || n == 1 || n == 0) {
    return n;
  }
  // even numbers are a special case
  // if we didn't handle them separately, we would have to get messsy with the
  // divisor below
  while (curr % 2 == 0) {
    factors[i++] = 2;
    curr /= 2;
    root = sqrt(curr);
  }
  // for every odd divisor:
  for (unsigned divisor = 3; divisor < root; divisor += 2) {
    if (curr % divisor == 0) {
      factors[i++] = divisor;
      curr /= divisor;
      root = sqrt(curr);
      divisor = 3;
    }
  }
  // if we reach the root, the current number is also a factor of the original
  factors[i++] = curr;
  int j;
  for (j = 0; j < i; j++) {
    printf("%lu\n", factors[j]);
  }
  int k;
  unsigned max_factor = 0;
  for (k = 0; k < i; k++) {
    if (factors[k] > max_factor) {
      max_factor = factors[k];
    }
  }
  printf("\n");
  return max_factor;
}
