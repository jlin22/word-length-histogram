#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORDLENGTH 20

int main() {
  int c, wl, state;
  int wlength[MAXWORDLENGTH];
  for (int i = 0; i < MAXWORDLENGTH; ++i)
    wlength[i] = 0;
  wl = 0;

  while ((c = getchar()) != EOF) {
    ++wl;
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++wlength[wl];
      wl = 0;
    }
  }

  for (int i = 0; i < MAXWORDLENGTH; ++i) {
    printf("%2d ", i);
    for (int j = 0; j < wlength[i]; j++)
      printf(">");
    printf("\n");
  }

  // Find the maximum value of wlength[i]
  int max = 0;
  for (int i = 0; i < MAXWORDLENGTH; ++i)
    if (wlength[i] > max)
      max = wlength[i];

  for (int i = max; i >= 0; --i) {
    int j = 2;
    printf("  ");
    for (int k = 0; k < MAXWORDLENGTH; ++k) {
      if (wlength[k] >= i) {
        printf("#  ");
      }
      else 
        printf("   "); 
      j += 3;
    }
    printf("\n");
  }

  printf(" ");
  for (int k = 0; k < MAXWORDLENGTH; ++k) 
    printf("%2d ", k);
  printf("\n");

  return 0;
}
    
