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
  if (n == 2) {
    return 2;
  }
  if (n == 1) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }
  // 2 is a special case because it would fuck up our other loop
  while (curr % 2 == 0) {
    factors[i++] = 2;
    curr /= 2;
    root = sqrt(curr);
  }
  // for every odd divisor
  for (unsigned divisor = 3; divisor < root; divisor += 2) {
    // if the current number divides evenly by that divisor
    if (curr % divisor == 0) {
      // the divisor is a factor, add it to our factors array
      factors[i++] = divisor;
      // divide current by divisor
      curr /= divisor;
      // reset the root
      root = sqrt(curr);
      // reset the divisor to begin the process again
      divisor = 3;
    }
  }
  // if we reach the root, the current number is a factor of the original (it
  // may be the only one)
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
  // if (factor(max_factor) == 0) {
  //   return max_factor;
  // }
  // return factor(max_factor);
  return max_factor;
}
