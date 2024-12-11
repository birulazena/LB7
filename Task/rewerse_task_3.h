#pragma once
#include <iostream>

void rewerse_task_3(std::string &result_sum) {
  // Первая часть: реверс строки
  for (long long i = 0; i < result_sum.size() / 2;
       i++) {                         // O(result_sum.size())
    char for_rewerse_sum;             // O(1)
    for_rewerse_sum = result_sum[i];  // O(1)
    result_sum[i] = result_sum[result_sum.size() - 1 - i];    // O(1)
    result_sum[result_sum.size() - 1 - i] = for_rewerse_sum;  // O(1)
  }

  std::string str_for_rewerse_sum;               // O(1)
  int start = 0;                                 // O(1)
  for (int i = 0; i < result_sum.size(); i++) {  // O(result_sum.size)
    if (result_sum[i] != 32) {                   // O(1)
      str_for_rewerse_sum += result_sum[i];      // O(1)
    } else {
      for (int j = str_for_rewerse_sum.size() - 1; j >= 0;
           j--) {  // O(str_for_rewerse.size())
        result_sum[start] = str_for_rewerse_sum[j];  // O(1)
        start++;                                     // O(1)
      }
      start = i + 1;                // O(1)
      str_for_rewerse_sum.clear();  // O(1)
    }
  }

  for (int i = 1; i < result_sum.size() - 1; i++) {  // O(n)
    if (result_sum[i] == 32 && isdigit(result_sum[i - 1]) &&
        isdigit(result_sum[i + 1])) {  // O(1)
      result_sum.erase(i, 1);          // O(1)
      i--;                             // O(1)
    }
  }
}