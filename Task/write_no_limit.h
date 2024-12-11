#pragma once
#include <iostream>

long double write_no_limit() {
  long double number;  // O(1)
  for (;;) {
    std::string write_number;  // O(1)
    std::cin >> write_number;  // O(1)
    bool isnum = true;         // O(1)

    for (auto l : write_number) {     // O(write_number.size())
      if (!isdigit(l) && l != '-') {  // O(1)
        isnum = false;                // O(1)
      }
    }

    if (isnum) {                          // O(1)
      number = std::stold(write_number);  // O(1)
      break;                              // O(1)
    } else {
      std::cout << "Неверный ввод, повтори попытку\n";  // O(1)
    }
  }
  return number;  // O(1)
}