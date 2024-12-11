#pragma once
#include <iostream>

void create_notation(char **notation, long long base) {
  int k = 0;         // O(1)
  char for_rewerse;  // O(1)

  for (long long i = 0; i < base; i++) {  // O(base)
    if (i < 10) {                         // O(1)
      notation[i][0] = '0' + i;           // O(1)
      notation[i][1] = '\0';              // O(1)
    } else {
      k = 0;                    // O(1)
      if (i == 10) {            // O(1)
        notation[i][0] = 65;    // O(1)
        notation[i][1] = '\0';  // O(1)
      }

      for (long long index = i - 10; index >= 0; index--) {  // O(i)
        notation[i][k] = 'A' + index % 26;                   // O(1)
        index = index / 26;                                  // O(1)
        k++;                                                 // O(1)
      }

      for (long long l = 0; l < k / 2; l++) {     // O(k)
        for_rewerse = notation[i][l];             // O(1)
        notation[i][l] = notation[i][k - 1 - l];  // O(1)
        notation[i][k - 1 - l] = for_rewerse;     // O(1)
      }
      notation[i][k] = '\0';  // O(1)
    }
  }
}