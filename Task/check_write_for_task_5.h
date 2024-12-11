#pragma once
#include <iostream>

int write_for_task_5() {
  int result;  // O(1)
  for (;;) {
    std::string check_write;  // O(1)
    bool isnum = true;        // O(1)
    std::cin >> check_write;
    for (auto l : check_write) {  // O(check_write)
      if (!isdigit(l)) {          // O(1)
        isnum = false;            // O(1)
        break;                    // O(1)
      }
    }
    if (isnum) {                          // O(1)
      result = std::stoi(check_write);    // O(1)
      if (result <= 240 && result > 0) {  // O(1)
        break;                            // O(1)
      } else {
        std::cout << "Неверный ввод\n";  // O(1)
      }
    } else {
      std::cout << "Неверный ввод\n";  // O(1)
    }
  }
  return result;  // O(1)
}