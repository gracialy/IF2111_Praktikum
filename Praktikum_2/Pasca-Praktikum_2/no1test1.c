#include <limits.h>
#include <stdio.h>

int FIRST = INT_MIN;
int SECOND = INT_MIN;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);

    if (x > FIRST) {
      SECOND = FIRST;
      FIRST = x;
    } else if (x > SECOND && x != FIRST) {
      SECOND = x;
    }

    if (i > 0 && SECOND == INT_MIN) {
      SECOND = x;
    }
  }

  printf("%d\n", SECOND);
  return 0;
}