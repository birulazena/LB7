#pragma once
#include <iostream>

long long write_base() {
  long long result;  // O(1)

  for (;;) {
    std::string check_base;  // O(1)
    std::cin >> check_base;  // O(1)
    bool isnum = true;       // O(1)

    for (auto l : check_base) {                    // O(check_base.size())
      if (!isdigit(l) || check_base.size() > 9) {  // O(1)
        isnum = false;                             // O(1)
        break;                                     // O(1)
      }
    }

    if (isnum) {                        // O(1)
      result = std::stoll(check_base);  // O(1)
      break;                            // O(1)
    } else {
      std::cout << "Неверный ввод\n";  // O(1)
    }
  }
  return result;  // O(1)
}