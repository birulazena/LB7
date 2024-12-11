#pragma once
#include <iostream>

std::string my_sum(std::string &main_number, std::string &number_1) {
  std::string result_sum;         // O(1)
  long long sum;                  // O(1)
  std::string check_main_number;  // O(1)
  std::string check_number;       // O(1)
  long long index_1 = 0;          // O(1)
  long long index_2 = 0;          // O(1)
  int ostatok = 0;                // O(1)

  for (;;) {
    if (index_1 < main_number.size()) {          // O(1)
      check_main_number = main_number[index_1];  // O(1)
      index_1++;                                 // O(1)
    }
    if (index_2 < number_1.size()) {     // O(1)
      check_number = number_1[index_2];  // O(1)
      index_2++;                         // O(1)
    }

    sum = ostatok + std::stoi(check_main_number) +
          std::stoi(check_number);  // O(1)
    check_main_number = '0';        // O(1)
    check_number = '0';             // O(1)
    ostatok = 0;                    // O(1)

    if (sum >= 10) {  // O(1)
      sum -= 10;      // O(1)
      ostatok++;      // O(1)
    }

    result_sum += std::to_string(sum);

    if (index_1 == main_number.size() && index_2 == number_1.size()) {  // O(1)
      if (ostatok == 1) {                                               // O(1)
        result_sum += '1';                                              // O(1)
      }
      break;  // O(1)
    }
  }

  return result_sum;  // O(1)
}