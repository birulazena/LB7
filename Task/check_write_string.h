#pragma once
#include <iostream>

std::string check_write_string() {
  std::string number;  // O(1)

  for (;;) {
    std::string check_number;  // O(1)
    bool isnum = true;         // O(1)
    std::cin >> check_number;

    if (check_number[0] != '-' && !isdigit(check_number[0])) {  // O(1)
      isnum = false;                                            // O(1)
    }

    for (int i = 1; i < std::size(check_number); i++) {  // O(check_number)
      if (!isdigit(check_number[i])) {                   // O(1)
        isnum = false;                                   // O(1)
        break;                                           // O(1)
      }
    }

    if (isnum) {              // O(1)
      number = check_number;  // O(1)
      break;                  // O(1)
    } else {
      std::cout << "Неверный ввод, повтори попытку\n";  // O(1)
    }
  }
  return number;  // O(1)
}