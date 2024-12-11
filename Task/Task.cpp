#include <cmath>
#include <iostream>

#include "Task_1.h"
#include "check_ho_rip_for_task_5.h"
#include "check_write_for_task_5.h"
#include "check_write_string.h"
#include "create_notation.h"
#include "delenie_2.h"
#include "delenie_ostatok_task_3.h"
#include "for_3_task_4.h"
#include "for_61_or_131_task_4.h"
#include "meniu.h"
#include "my_sum.h"
#include "ostatok.h"
#include "priamoi_kod_task_2.h"
#include "rewerse_task_3.h"
#include "size_for_task_2.h"
#include "sum_differense.h"
#include "summa_task_2.h"
#include "write_base.h"
#include "write_for_start.h"
#include "write_for_task_4.h"
#include "write_no_limit.h"
int main() {
  meniu();
  for (;;) {
    std::cout << "Введите 1 - Task_1\n";
    std::cout << "Введите 2 - Task_2\n";
    std::cout << "Введите 3 - Task_3\n";
    std::cout << "Введите 4 - Task_4\n";
    std::cout << "Введите 5 - Task_5\n";
    long double number_for_start = write_for_start();

    if (number_for_start == 1) {
      std::cout << "Введите число в естественной форме\n";
      int number = write_no_limit();

      std::string result = task_1(number);

      std::cout << "Число в прямом коде:\n" << result << '\n';
    }

    if (number_for_start == 2) {
      std::cout << "Введите первое число\n";
      std::string number_1 = check_write_string();
      std::cout << "Введите второе число\n";
      std::string number_2 = check_write_string();

      int size_for_task = size_for_task_2(number_1, number_2);

      char *massiw_for_number_1 = new char[size_for_task];

      summa_task_2(massiw_for_number_1, number_1, number_2, size_for_task);
      priamoi_kod_task_2(massiw_for_number_1);

      std::cout << "\nСумма в прямом коде:\n"
                << massiw_for_number_1 << std::endl;

      delete[] massiw_for_number_1;
    }

    if (number_for_start == 3) {
      std::cout << "Введите основание системы счисления\n";
      long long base = write_base();
      long long size_for_columb;
      size_for_columb = base - 36;
      long long couter = 0;
      if (size_for_columb > 0 && size_for_columb < 62) {
        couter++;
      }
      while (true) {
        if (size_for_columb < 26) {
          break;
        }
        couter++;
        size_for_columb /= 26;
      }
      couter++;

      char **notation = new char *[base];
      for (long long i = 0; i < base; i++) {
        notation[i] = new char[couter + 1];
      }

      for (int i = 0; i < base; i++) {
        for (int j = 0; j <= couter; j++) {
          notation[i][j] = '\0';
        }
      }

      create_notation(notation, base);

      std::cout << "Введите первое число\n";
      std::string number_1 = check_write_string();
      std::cout << "Введите второе число\n";
      std::string number_2 = check_write_string();
      char sign_number_1;
      char sign_number_2;
      if (number_1[0] == '-') {
        number_1.erase(0, 1);
        sign_number_1 = '-';
      }
      if (number_2[0] == '-') {
        number_2.erase(0, 1);
        sign_number_2 = '-';
      }
      bool check_size_for_differense = false;
      bool check_ho_bigger = false;
      if (number_1.size() > number_2.size()) {
        check_ho_bigger = true;
      }
      if (number_1.size() == number_2.size()) {
        for (int i = 0; i < number_1.size(); i++) {
          std::string check_digit_number_1;
          check_digit_number_1 = number_1[i];
          std::string check_digit_number_2;
          check_digit_number_2 = number_2[i];
          if (std::stoi(check_digit_number_1) >
              std::stoi(check_digit_number_2)) {
            check_size_for_differense = true;
            check_ho_bigger = true;
            break;
          } else {
            break;
          }
        }
      }
      std::string translated_number_1;
      long long ostatok_number_1 = 0;
      char spase[] = " ";

      while (number_1.empty() == false) {
        number_1 = dellenie_statok_task_3(number_1, base, ostatok_number_1);
        translated_number_1 += notation[ostatok_number_1];
        ostatok_number_1 = 0;
        translated_number_1 += 32;
      }

      std::string translated_number_2;
      long long ostatok_number_2 = 0;

      while (number_2.empty() == false) {
        number_2 = dellenie_statok_task_3(number_2, base, ostatok_number_2);
        translated_number_2 += notation[ostatok_number_2];
        ostatok_number_2 = 0;
        translated_number_2 += 32;
      }

      std::string result_sum;
      std::string result_difference;
      sum_differense(translated_number_1, translated_number_2, base, notation,
                     check_size_for_differense, check_ho_bigger, result_sum,
                     result_difference);

      for (long long i = 0; i < base; i++) {
        delete[] notation[i];
      }
      delete[] notation;

      rewerse_task_3(result_sum);
      rewerse_task_3(result_difference);

      std::string for_sing_sum = result_sum;
      std::string for_sing_differense = result_difference;
      if (sign_number_1 == '-' && sign_number_2 == '-') {
        result_sum.insert(0, 1, sign_number_1);
        if (check_size_for_differense || check_ho_bigger) {
          result_difference.insert(0, 1, sign_number_1);
        }
      }
      if (sign_number_1 == '-' && sign_number_2 != '-') {
        if (check_size_for_differense || check_ho_bigger) {
          result_sum = for_sing_differense.insert(0, 1, sign_number_1);
          result_difference = for_sing_sum.insert(0, 1, sign_number_1);
        } else {
          result_sum = for_sing_differense;
          result_difference = for_sing_sum.insert(0, 1, sign_number_1);
        }
      }
      if (sign_number_1 != '-' && sign_number_2 == '-') {
        if (check_size_for_differense || check_ho_bigger) {
          result_sum = for_sing_differense;
          result_difference = for_sing_sum;
        } else {
          result_sum = for_sing_differense.insert(0, 1, sign_number_2);
          result_difference = for_sing_sum;
        }
      }

      if (sign_number_1 != '-' && sign_number_2 != '-') {
        if (check_size_for_differense == false || check_ho_bigger == false) {
          char minus = '-';
          result_difference.insert(0, 1, minus);
        }
      }

      std::cout << "\nCумма чисел в " << base
                << "-ой системе счисления = " << result_sum << '\n';

      std::cout << "\nРазность чисел в " << base
                << "-ой системе счисления = " << result_difference << '\n';
    }

    if (number_for_start == 4) {
      std::cout << "Введите число\n";
      std::string main_number = write_for_task_4();
      std::cout << '\n';

      // Для 3
      long long sum_for_3 = for_3_task_4(main_number);
      long long check_sum_for_3 = 0;
      for (;;) {
        check_sum_for_3 += 3;
        if (check_sum_for_3 == sum_for_3) {
          std::cout << "Число " << main_number << " делится на 3\n";
          break;
        }
        if (check_sum_for_3 > sum_for_3) {
          std::cout << "Число " << main_number << " не делится на 3\n";
          break;
        }
      }

      // для 61
      int D_for_61 = 55;
      std::string second_check_sum_61 =
          for_61_or_131_task_4(main_number, D_for_61);

      long long check_task_61 = 0;
      if (second_check_sum_61.empty() == false) {
        for (;;) {
          check_task_61 += 61;
          if (check_task_61 == std::stoll(second_check_sum_61)) {
            std::cout << "Число " << main_number << " делится на 61\n";
            break;
          }
          if (check_task_61 > std::stoll(second_check_sum_61)) {
            std::cout << "Число " << main_number << " не делится на 61\n";
            break;
          }
        }
      } else {
        std::cout << "Число " << main_number << " не делится на 61\n";
      }

      // Для 131;
      int D_for_131 = 118;
      std::string second_check_sum_131 =
          for_61_or_131_task_4(main_number, D_for_131);

      long long check_task_131 = 0;
      if (second_check_sum_131.empty() == false) {
        for (;;) {
          check_task_131 += 131;
          if (check_task_131 == std::stoll(second_check_sum_131)) {
            std::cout << "Число " << main_number << " делится на 131\n";
            break;
          }
          if (check_task_131 > std::stoll(second_check_sum_131)) {
            std::cout << "Число " << main_number << " не делится на 131\n";
            break;
          }
        }
      } else {
        std::cout << "Число " << main_number << " не делится на 131\n";
      }
    }
    if (number_for_start == 5) {
      int massiw[240] = {};
      for (int i = 0; i < 240; i++) {
        massiw[i] = i + 1;
        // std::cout << massiw[i] << " ";
      }

      std::cout << "Введите номер отравленной бочки (от 1 до 240)\n";
      int key = write_for_task_5();
      std::string rab_1 = "1";
      std::string rab_2 = "1";
      std::string rab_3 = "1";
      std::string rab_4 = "1";
      std::string rab_5 = "1";

      std::string check_kill_rab;
      std::string check_result;
      int wsego_rabow = 5;
      int l;
      int r;
      int result;
      if (massiw[0] == key) {
        check_kill_rab += rab_1;
        check_kill_rab += rab_2;
        check_kill_rab += rab_4;
        check_kill_rab += rab_5;
        l = 0;
        r = 1;
        wsego_rabow -= check_kill_rab.size();
        result = check_ho_rip(wsego_rabow, key - l);
        std::cout << "Номер отравленной бочки = " << result + l << std::endl;
      }
      for (int i = 1; i < 3; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_2;
          check_kill_rab += rab_3;
          check_kill_rab += rab_4;
          l = 1;
          r = 3;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }
      for (int i = 3; i < 5; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_2;
          check_kill_rab += rab_3;
          check_kill_rab += rab_5;
          l = 3;
          r = 5;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 5; i < 7; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_2;
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 5;
          r = 7;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 7; i < 9; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_3;
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 7;
          r = 9;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 9; i < 11; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          check_kill_rab += rab_3;
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 9;
          r = 11;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 11; i < 15; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_2;
          check_kill_rab += rab_3;
          l = 11;
          r = 15;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 15; i < 19; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_2;
          check_kill_rab += rab_4;
          l = 15;
          r = 19;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 19; i < 23; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_2;
          check_kill_rab += rab_5;
          l = 19;
          r = 23;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 23; i < 27; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_3;
          check_kill_rab += rab_4;
          l = 23;
          r = 27;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 27; i < 31; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_3;
          check_kill_rab += rab_5;
          l = 27;
          r = 31;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 31; i < 35; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 31;
          r = 35;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 35; i < 39; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          check_kill_rab += rab_3;
          check_kill_rab += rab_4;
          l = 35;
          r = 39;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 39; i < 43; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          check_kill_rab += rab_3;
          check_kill_rab += rab_5;
          l = 39;
          r = 43;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 43; i < 47; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 43;
          r = 47;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 47; i < 51; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_3;
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 47;
          r = 51;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 51; i < 59; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_2;
          l = 51;
          r = 59;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 59; i < 67; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_3;
          l = 59;
          r = 67;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 67; i < 75; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_4;
          l = 67;
          r = 75;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 75; i < 83; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          check_kill_rab += rab_5;
          l = 75;
          r = 83;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 83; i < 91; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          check_kill_rab += rab_3;
          l = 83;
          r = 91;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 91; i < 99; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          check_kill_rab += rab_4;
          l = 91;
          r = 99;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 99; i < 107; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          check_kill_rab += rab_5;
          l = 99;
          r = 107;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 107; i < 115; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_3;
          check_kill_rab += rab_4;
          l = 107;
          r = 115;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 115; i < 123; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 115;
          r = 123;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 123; i < 131; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_4;
          check_kill_rab += rab_5;
          l = 123;
          r = 131;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 131; i < 147; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_1;
          l = 131;
          r = 147;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 147; i < 163; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_2;
          l = 147;
          r = 163;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 163; i < 179; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_3;
          l = 163;
          r = 179;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 179; i < 195; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_4;
          l = 179;
          r = 195;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }

      for (int i = 195; i < 211; i++) {
        if (massiw[i] == key) {
          check_kill_rab += rab_5;
          l = 195;
          r = 211;
          wsego_rabow -= check_kill_rab.size();
          result = check_ho_rip(wsego_rabow, key - l);
          std::cout << "Номер отравленной бочки = " << result + l << std::endl;
        }
      }
      //
      if (check_kill_rab.empty()) {
        l = 211;
        r = 240;
        wsego_rabow -= check_kill_rab.size();
        result = check_ho_rip(wsego_rabow, key - l);
        std::cout << "Номер отравленной бочки = " << result + l << std::endl;
      }
    }
    std::cout << "\n\nВведите 1 - завершить программу\n";
    std::cout << "Введите не 1 - запустить программу еще раз\n";
    int number_for_restart = write_for_task_5();
    if (number_for_restart == 1) {
      break;
    }
  }

  return 0;
}