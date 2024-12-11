#pragma once
#include <iostream>

std::string dellenie_statok_task_3(std::string number, long long base,
                                   long long &ostatok) {
  std::string result_number;   // O(1)
  std::string str_for_number;  // O(1)
  long long check_result;      // O(1)

  for (long long i = 0; i < std::size(number); i++) {  // O(std::size(number))
    str_for_number = number[i];                        // O(1)
    check_result = (ostatok * 10 + std::stoll(str_for_number)) / base;  // O(1)
    ostatok = (ostatok * 10 + std::stoll(str_for_number)) % base;       // O(1)
    result_number += std::to_string(check_result);
  }

  while (true) {
    int i = 0;
    if (result_number[i] == '0') {  // O(1)
      result_number.erase(i, 1);
    } else {
      break;  // O(1)
    }
  }
  return result_number;  // O(1)
}