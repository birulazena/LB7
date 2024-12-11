#pragma once
#include <iostream>

std::string write_for_task_4() {
  std::string result;  // O(1)

  for (;;) {
    std::string check;  // O(1)
    std::cin >> check;  // O(1)
    bool isnum = true;  // O(1)

    for (auto l : check) {  // O(check.size())
      if (!isdigit(l)) {    // O(1)
        isnum = false;      // O(1)
        break;              // O(1)
      }
    }

    if (isnum) {       // O(1)
      result = check;  // O(1)
      break;           // O(1)
    } else {
      std::cout << "Неверный ввод\n";  // O(1)
    }
  }
  return result;  // O(1)
}