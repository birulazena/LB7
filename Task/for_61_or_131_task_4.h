#pragma once
#include <iostream>

#include "my_sum.h"

std::string for_61_or_131_task_4(std::string main_number, int D) {
  std::string check_main_number_for_61 = main_number;

  char for_rewerse;
  for (long long i = 0; i < check_main_number_for_61.size() / 2;
       i++) {  // O(n) - n = check_main_number_for_61
    for_rewerse = check_main_number_for_61[i];  // O(1)
    check_main_number_for_61[i] =
        check_main_number_for_61[check_main_number_for_61.size() - 1 -
                                 i];  // O(1)
    check_main_number_for_61[check_main_number_for_61.size() - 1 - i] =
        for_rewerse;  // O(1)
  }

  long long sum_for_61 = 0;               // O(1)
  std::string first_element_main_number;  // O(1)
  std::string check_sum_for_61;           // O(1)
  std::string second_check_sum_61;        // O(1)

  for (;;) {
    first_element_main_number = check_main_number_for_61[0];  // O(1)
    check_main_number_for_61 = check_main_number_for_61.erase(0, 1);
    if (check_main_number_for_61.empty()) {  // O(1)
      break;                                 // O(1)
    }
    for (int i = 0; i < D; i++) {                          // O(D)
      sum_for_61 += std::stoi(first_element_main_number);  // O(1)
    }

    check_sum_for_61 = std::to_string(sum_for_61);
    sum_for_61 = 0;

    for (int i = 0; i < check_sum_for_61.size() / 2;
         i++) {  // O(m),  m — длина check_sum_for_61
      for_rewerse = check_sum_for_61[i];  // O(1)
      check_sum_for_61[i] =
          check_sum_for_61[check_sum_for_61.size() - 1 - i];            // O(1)
      check_sum_for_61[check_sum_for_61.size() - 1 - i] = for_rewerse;  // O(1)
    }

    check_main_number_for_61 = my_sum(
        check_main_number_for_61, check_sum_for_61);  // O(n + m) для сложения
    if (check_main_number_for_61 == second_check_sum_61) {  // O(n)
      break;                                                // O(1)
    }

    second_check_sum_61 = check_main_number_for_61;  // O(1)
  }

  for (int i = 0; i < second_check_sum_61.size() / 2; i++) {  // O(m)
    for_rewerse = second_check_sum_61[i];                     // O(1)
    second_check_sum_61[i] =
        second_check_sum_61[second_check_sum_61.size() - 1 - i];  // O(1)
    second_check_sum_61[second_check_sum_61.size() - 1 - i] =
        for_rewerse;  // O(1)
  }
  return second_check_sum_61;  // O(1)
}