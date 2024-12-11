#pragma once
#include <string.h>

#include <iostream>

char priamoi_kod_task_2(char *massiw_for_number_1) {
  if (massiw_for_number_1[0] == '1') {  // O(1)
    for (int i = 1; i < strlen(massiw_for_number_1);
         i++) {                             // O(strlen(massiw_for_number_1))
      if (massiw_for_number_1[i] == '1') {  // O(1)
        massiw_for_number_1[i] = '0';       // O(1)
      } else {
        massiw_for_number_1[i] = '1';  // O(1)
      }
    }
  }
  return *massiw_for_number_1;  // O(1)
}