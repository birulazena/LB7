#pragma once
#include <iostream>

std::string delenie_2(std::string number) {
  int check_number;    // O(1)
  int ostatok = 0;     // O(1)
  std::string lol;     // O(1)
  std::string result;  // O(1)

  for (int i = 0; i < std::size(number); i++) {  // O(number)
    if (number[i] == '-') {                      // O(1)
      number.erase(i, 1);                        // O(1)
      i--;                                       // O(1)
      continue;                                  // O(1)
    }
    lol = number[i];                               // O(1)
    check_number = ostatok * 10 + std::stoi(lol);  // O(1)
    ostatok = check_number % 2;                    // O(1)
    result += std::to_string(check_number / 2);
  }

  if (result[1] == '0' && result[0] == '-') {  // O(1)
    result.erase(1, 1);                        // O(1)
  }

  return result;  // O(1)
}