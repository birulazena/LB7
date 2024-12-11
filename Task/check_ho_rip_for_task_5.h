#pragma once
#include <iostream>

void tabl(int str, int stlb, int** tablica) {
  int check = str / 2;                  // O(1)
  for (int i = 0; i < stlb; i++) {      // O(stlb)
    for (int j = 0; j < str; j++) {     // O(str)
      tablica[j][i] = (j / check) % 2;  // O(1)
    }
    check /= 2;  // O(1)
  }  // O(stlb * str)
}

int check_ho_rip(int numb_peop, int key) {
  int str = 1;                           // O(1)
  for (int i = 0; i < numb_peop; i++) {  // O(numb_peop)
    str *= 2;                            // O(1)
  }
  int** tablica = new int*[str];      // O(1)
  for (int i = 0; i < str; i++) {     // O(str)
    tablica[i] = new int[numb_peop];  // O(1)
  }

  tabl(str, numb_peop, tablica);         // O(numb_peop * 2^numb_peop)
  int result = 0;                        // O(1)
  for (int i = 0; i < numb_peop; i++) {  // O(numb_peop)
    if (tablica[key - 1][i] == 1) {      // O(1)
      int pow = 1;                       // O(1)
      for (int j = 0; j < numb_peop - 1 - i; j++) {  // O(numb_peop)
        pow *= 2;                                    // O(1)
      }
      result += pow;  // O(1)
    }
  }  // O(numb_peop^2)

  for (int i = 0; i < str; i++) {  // O(str)
    delete[] tablica[i];           // O(1)
  }
  delete[] tablica;   // O(1)
  return result + 1;  // O(1)
}