#pragma once
#include <iostream>

long long for_3_task_4(std::string main_number) {
  std::string check_main_number_for_3 = main_number;  // O(1)
  long long sum_for_3 = 0;                            // O(1)
  std::string check_for_3;                            // O(1)

  for (;;) {
    for (auto l :
         check_main_number_for_3) {  // O(n) n — длина check_main_number_for_3
      check_for_3 = l;               // O(1)
      sum_for_3 += std::stoi(check_for_3);  // O(1)
    }
    check_main_number_for_3 = std::to_string(sum_for_3);
    if (check_main_number_for_3.size() == 1) {  // O(1)
      break;                                    // O(1)
    }
    sum_for_3 = 0;  // O(1)
  }
  return sum_for_3;  // O(1)
}