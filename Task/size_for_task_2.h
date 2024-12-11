#pragma once
#include <iostream>

#include "delenie_2.h"

int size_for_task_2(std::string number_1, std::string number_2) {
  std::string max_str;

  if (std::size(number_1) > std::size(number_2)) {  // O(1)
    max_str = number_1;                             // O(1)
  } else {
    max_str = number_2;  // O(1)
  }

  int my_log = 0;  // O(1)
  for (;;) {
    my_log++;  // O(1)

    max_str = delenie_2(max_str);

    if (std::size(max_str) <= 2) {                       // O(1)
      int check_str_for_check_log = std::stoi(max_str);  // O(1)
      if (check_str_for_check_log == 0) {                // O(1)
        break;                                           // O(1)
      }
    }

    if (max_str[0] == '0') {  // O(1)
      max_str.erase(0, 1);    // O(1)
    }
  }

  int size_for_task = my_log + 4;  // O(1)
  return size_for_task;            // O(1)
}