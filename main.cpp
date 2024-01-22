#include <iostream>

struct data {
  int day;
  int month;
  int year;
};

int isLeapYear(int year) {
  int res = 0;
  if (year % 4 != 0)
    res = 0;
  else if (year % 100 != 0)
    res = 1;
  else if (year % 400 == 0)
    res = 1;
  return res;
}

bool checkData(data& data) {
  int res = 1;
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (data.year < 1) {
    res = 0;
  } else if (data.month < 1 || data.month > 12) {
    res = 0;
  } else {
    if (isLeapYear(data.year) && data.month == 2) {
      daysInMonth[1] = 29;
    }
    if (data.day < 1 || data.day > daysInMonth[data.month - 1]) {
      res = 0;
    }
  }
  return res;
}

int main() {
  int size;
  std::cin >> size;
  while (size--) {
    data data;
    std::cin >> data.day;
    std::cin >> data.month;
    std::cin >> data.year;
    std::cout << (checkData(data) ? "YES" : "NO") << std::endl;
  }
  return 0;
}