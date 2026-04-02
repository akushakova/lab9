#include "task2.h"
#include <iostream>

// Обчислення кількості входжень підрядка lookup в рядок str
int count_inclusions(std::string src, std::string lookup) {
  std::size_t pos = 0; // Остання позиція входження
  int count = 0;       // Кількість входжень
  while (true) {
    pos = src.find(lookup, pos); // Шукаємо позицію входження
    if (pos ==
        std::string::npos) // Якщо позицію не визначено, завершуємо роботу
      break;
    pos += 1; // При вдалому визначенні, переходимо на 1 символ для уникнення
              // знаходження того ж підрядку
    count++;  // Збільшуємо кількість входжень
  }
  return count;
}

// Перевірка правильності вводу
bool is_valid(std::string str) {
  if (!str[0])
    return false; // Якщо рядок порожній, повертаємо false
  std::string allowed = "0123456789_ "
                        "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"
                        "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ"
                        "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя"; // Доступні символи
  for (int i = 0; str[i]; i++) {
    if (allowed.find(str[i]) ==
        std::string::npos) // Якщо символ не в списку доступних, повертаємо
                           // false
      return false;
  }
  return true;
}

// Допоміжна функція введення з перевіркою
std::string input_with_validator(std::string msg) {
  std::string str;
  // Зчитуємо та перевіряємо рядок у циклі до правильного введення
  while (true) {
    std::cout << msg;
    std::getline(std::cin, str);
    if (is_valid(str))
      return str;
    std::cout
        << std::endl
        << "Текст має містити лише англійські літери, кирилицю, числа або '_'"
        << std::endl;
  };
}

// Повне завдання 2
void task2() {
  std::string src = input_with_validator("Введіть рядок: ");
  std::string lookup = input_with_validator("Введіть підрядок: ");
  std::cout << "Кількість входжень: " << count_inclusions(src, lookup);
}
