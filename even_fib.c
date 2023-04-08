#include <stdio.h>

#define MAX 100

int cache[MAX];

int memoized_fib(int index);

void init_cache() {
  for (int i = 0; i < MAX; i++) {
    cache[i] = 0;
  }
  cache[1] = 1;
  cache[2] = 2;
}

int main() {
  init_cache();
  printf("%d", memoized_fib(20));
  return 1;
}

int memoized_fib(int index) {
  if (cache[index] != 0) {
    return cache[index];
  } else {
    int first, second;
    first = memoized_fib(index - 1);
    second = memoized_fib(index - 2);
    cache[index - 1] = first;
    cache[index - 2] = second;
    return first + second;
  }
}
