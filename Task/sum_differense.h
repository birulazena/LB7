#pragma once
#include <cmath>
#include <iostream>

void sum_differense(std::string &translated_number_1,
                    std::string &translated_number_2, long long base,
                    char **notation, bool check_size_for_differense,
                    bool check_ho_bigger, std::string &result_sum,
                    std::string &result_difference) {
  long long ostatok_for_sum = 0;         // O(1)
  long long index_1 = 0;                 // O(1)
  long long index_2 = 0;                 // O(1)
  long long index_sum_differense_1 = 0;  // O(1)
  long long index_sum_differense_2 = 0;  // O(1)
  long long sum = 0;                     // O(1)
  long long differense;                  // O(1)
  long long ostatok_for_differense = 0;  // O(1)

  for (;;) {
    bool check_1 = false;       // O(1)
    bool check_2 = false;       // O(1)
    std::string str_for_sum_1;  // O(1)
    std::string str_for_sum_2;  // O(1)

    while (index_1 <
           translated_number_1.size()) {  // O(translated_number_1.size())
      if (translated_number_1[index_1] != 32) {         // O(1)
        str_for_sum_1 += translated_number_1[index_1];  // O(1)
        index_1++;                                      // O(1)
      } else {
        index_1++;  // O(1)
        break;      // O(1)
      }
    }

    while (index_2 <
           translated_number_2.size()) {  // O(translated_number_2.size())
      if (translated_number_2[index_2] != 32) {         // O(1)
        str_for_sum_2 += translated_number_2[index_2];  // O(1)
        index_2++;                                      // O(1)
      } else {
        index_2++;  // O(1)
        break;      // O(1)
      }
    }

    long long for_start_scan =
        std::min(str_for_sum_1.size(), str_for_sum_2.size());  // O(1)
    long long start_scan = 0;                                  // O(1)
    long long current_power = 1;                               // O(1)

    for (int i = 2; i < for_start_scan; i++) {  // O(for_start_scan)
      start_scan += powl(26, i);                // O(1)
    }

    for (long long i = start_scan; i < base; i++) {  // O(base - start_scan)
      if (str_for_sum_1 == notation[i]) {            // O(1)
        check_1 = true;                              // O(1)
        index_sum_differense_1 = i;                  // O(1)
      }
      if (str_for_sum_2 == notation[i]) {  // O(1)
        check_2 = true;                    // O(1)
        index_sum_differense_2 = i;        // O(1)
      }
      if (check_1 && check_2) {  // O(1)
        break;                   // O(1)
      }
    }

    if (check_size_for_differense || check_ho_bigger) {  // O(1)
      differense = index_sum_differense_1 - index_sum_differense_2 -
                   ostatok_for_differense;  // O(1)
      ostatok_for_differense = 0;           // O(1)
      if (differense < 0) {                 // O(1)
        differense += base;                 // O(1)
        ostatok_for_differense++;           // O(1)
      }
      result_difference += notation[differense];  // O(1)
      result_difference += 32;                    // O(1)
    } else {
      differense = index_sum_differense_2 - index_sum_differense_1 -
                   ostatok_for_differense;  // O(1)
      ostatok_for_differense = 0;           // O(1)
      if (differense < 0) {                 // O(1)
        differense += base;                 // O(1)
        ostatok_for_differense++;           // O(1)
      }
      result_difference += notation[differense];  // O(1)
      result_difference += 32;                    // O(1)
    }

    sum = ostatok_for_sum + index_sum_differense_1 +
          index_sum_differense_2;  // O(1)
    index_sum_differense_1 = 0;    // O(1)
    index_sum_differense_2 = 0;    // O(1)
    ostatok_for_sum = 0;           // O(1);

    if (sum >= base) {    // O(1)
      ostatok_for_sum++;  // O(1)
      sum -= base;        // O(1)
    }

    result_sum += notation[sum];  // O(1)
    result_sum += 32;             // O(1)

    if (index_1 == translated_number_1.size() &&
        index_2 == translated_number_2.size()) {  // O(1)
      if (ostatok_for_sum > 0) {                  // O(1)
        result_sum += notation[ostatok_for_sum];  // O(1)
      }
      break;  // O(1)
    }
  }
}