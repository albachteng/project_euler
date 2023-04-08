/* project euler #2, sum of even fibonacci numbers not exceeding 4 million */

#include <stdio.h>

#define MAX 100

unsigned int cache[MAX];

unsigned int memoized_fib(int index);

void init_cache() {
  for (int i = 0; i < MAX; i++) {
    cache[i] = 0;
  }
  cache[1] = 1;
  cache[2] = 2;
}

int main() {
  init_cache();
  int fib, sum, i, j = 0;
  for (i = 1; i < MAX; i++) {
    if (memoized_fib(i) > 4000000) {
      printf("%d: %u\n", i, memoized_fib(i));
      break;
    }
  }

  for (j = 1; j < i; j++) {
    if (memoized_fib(j) % 2 == 0) {
      sum += memoized_fib(j);
    }
  }
  printf("%d", sum);
  return 1;
}

unsigned int memoized_fib(int index) {
  if (cache[index] != 0) {
    return cache[index];
  } else {
    unsigned int first, second;
    first = memoized_fib(index - 1);
    second = memoized_fib(index - 2);
    cache[index - 1] = first;
    cache[index - 2] = second;
    return first + second;
  }
}
