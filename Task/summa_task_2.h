#pragma once
#include <string.h>

#include <iostream>

#include "delenie_2.h"
#include "ostatok.h"

char summa_task_2(char *massiw_for_number_1, std::string number_1,
                  std::string number_2, int size_for_task) {
  char *massiw_for_number_2 = new char[size_for_task];  // O(1)
  std::string copu_number_1 = number_1;                 // O(1)
  std::string copu_number_2 = number_2;                 // O(1)
  massiw_for_number_1[0] = '0';                         // O(1)
  massiw_for_number_1[size_for_task - 1] = '\0';        // O(1)
  massiw_for_number_2[0] = '0';                         // O(1)
  massiw_for_number_2[size_for_task - 1] = '\0';        // O(1)

  for (int i = size_for_task - 2; i > 0; i--) {         // O(size_for_task)
    massiw_for_number_1[i] = (ostatok(number_1)) + 48;  // O(1)
    massiw_for_number_2[i] = (ostatok(number_2)) + 48;  // O(1)
    number_1 = delenie_2(number_1);
    number_2 = delenie_2(number_2);
  }

  if (copu_number_1[0] == '-') {                             // O(1)
    for (int i = 0; i < strlen(massiw_for_number_1); i++) {  // O(size_for_task)
      if (massiw_for_number_1[i] == '0') {                   // O(1)
        massiw_for_number_1[i] = '1';                        // O(1)
      } else {                                               // O(1)
        massiw_for_number_1[i] = '0';                        // O(1)
      }
    }
  }

  if (copu_number_2[0] == '-') {                             // O(1)
    for (int i = 0; i < strlen(massiw_for_number_2); i++) {  // O(size_for_task)
      if (massiw_for_number_2[i] == '0') {                   // O(1)
        massiw_for_number_2[i] = '1';                        // O(1)
      } else {                                               // O(1)
        massiw_for_number_2[i] = '0';                        // O(1)
      }
    }
  }

  int couter = 0;  // O(1)

  for (int i = strlen(massiw_for_number_1) - 1; i >= 0;
       i--) {  // O(size_for_task)
    if (massiw_for_number_1[i] == '1' &&
        massiw_for_number_2[i] == '1') {  // O(1)
      if (couter == 1) {                  // O(1)
        massiw_for_number_1[i] = '1';     // O(1)
        continue;                         // O(1)
      } else {                            // O(1)
        massiw_for_number_1[i] = '0';     // O(1)
        couter = 1;                       // O(1)
        continue;                         // O(1)
      }
    }
    if (massiw_for_number_1[i] == '1' &&
        massiw_for_number_2[i] == '0') {  // O(1)
      if (couter == 1) {                  // O(1)
        massiw_for_number_1[i] = '0';     // O(1)
        continue;                         // O(1)
      } else {                            // O(1)
        massiw_for_number_1[i] = '1';     // O(1)
        continue;                         // O(1)
      }
    }
    if (massiw_for_number_1[i] == '0' &&
        massiw_for_number_2[i] == '1') {  // O(1)
      if (couter == 1) {                  // O(1)
        continue;                         // O(1)
      } else {                            // O(1)
        massiw_for_number_1[i] = '1';     // O(1)
        continue;                         // O(1)
      }
    }
    if (massiw_for_number_1[i] == '0' &&
        massiw_for_number_2[i] == '0') {  // O(1)
      if (couter == 1) {                  // O(1)
        massiw_for_number_1[i] = '1';     // O(1)
        couter = 0;                       // O(1)
        continue;                         // O(1)
      } else {                            // O(1)
        continue;                         // O(1)
      }
    }
  }

  delete[] massiw_for_number_2;  // O(1)

  if (couter == 1) {  // O(1)
    for (int i = strlen(massiw_for_number_1) - 1; i >= 0;
         i--) {                                            // O(size_for_task)
      if (massiw_for_number_1[i] == '1' && couter == 1) {  // O(1)
        massiw_for_number_1[i] = '0';                      // O(1)
        continue;                                          // O(1)
      }
      if (massiw_for_number_1[i] == '1' && couter == 0) {  // O(1)
        continue;                                          // O(1)
      }
      if (massiw_for_number_1[i] == '0' && couter == 1) {  // O(1)
        massiw_for_number_1[i] = '1';                      // O(1)
        couter = 0;                                        // O(1)
        continue;                                          // O(1)
      }
      if (massiw_for_number_1[i] == '0' && couter == 0) {  // O(1)
        continue;                                          // O(1)
      }
    }
  }
  return *massiw_for_number_1;  // O(1)
}