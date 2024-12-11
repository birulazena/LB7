#pragma once
#include <cmath>
#include <iostream>

std::string task_1(int number) {
  int size_for_str = ceil(log2(abs(number))) + 2;  // O(log number)

  std::string result;           // O(1)
  result.resize(size_for_str);  // O(1)

  if (number < 0) {        // O(1)
    result[0] = '1';       // O(1)
    number = abs(number);  // O(1)
  } else {                 // O(1)
    result[0] = '0';       // O(1)
  }

  for (int i = size_for_str - 1; i > 0; i--) {  // O(size_for_str)
    result[i] = std::to_string(number % 2)[0];  // O(1)
    number /= 2;                                // O(1)
  }

  return result;  // O(1)
}