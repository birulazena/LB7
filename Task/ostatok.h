#pragma once
#include <iostream>

int ostatok(std::string number) {
  std::string check_number;  // O(1)

  check_number = number[std::size(number) - 1];  // O(1)
  int ostatok = std::stoi(check_number);         // O(1)

  ostatok %= 2;    // O(1)
  return ostatok;  // O(1)
}