#include "task1.h"
#include <cstring>
#include <iostream>
#include <string>

// Зчитування довжини рядка з масиву символів
// Вважається, що рядок збережено в коректному форматі
// (закінчення вказано як \0)
std::size_t get_len(const char *str) {
  std::size_t len = 0;
  while (str[len] != '\0')
    len++;
  return len;
}

// Заміна підрядка
// str - посилання на вхідний рядок
// pos - позиція, з якої починати заміну
// len - кількість символів, що слід замінити
// n -  кількість символів, що слід вставити
// c - символ, що слід вставити
void replace(char **str, std::size_t pos, std::size_t len, std::size_t n,
             char c) {
  std::size_t L = get_len(*str);     // Отримуємо довжину рядку
  std::size_t new_len = L - len + n; // Вираховуємо нову довжину рядку
  int off = 0;
  char *new_str =
      new char[new_len + 1]; // Створюємо новий масив символів для заміни
  for (int i = 0; i < L; i++) {
    if (i > pos &&
        i < pos +
                len) // Якщо символ лежить в проміжку для заміни, ігноруємо його
      continue;
    else if (i == pos) {          // Якщо ми дійшли до першого символа заміни
      off = n - len;              // Змінюємо зміщення копіювання
      for (int j = 0; j < n; j++) // Додаємо n символів c до масиву
        new_str[i + j] = c;
    } else // Інакше додаємо символ старого масиву до нового
      new_str[i + off] = (*str)[i];
  }
  new_str[new_len] = '\0'; // Додаємо символ закінчення рядку
  delete[] *str;           // Очищуємо пам'ять
  *str = new_str;          // Підімняємо старий рядок на новий
}

// Повне завдання 1
void task1() {
  // Визначення змінних
  int max_len = 50;
  std::size_t pos = 0;
  std::size_t len = 0;
  std::size_t n = 0;
  char c = ' ';
  char *str = new char[max_len];
  // Зчитуємо дані з консолі
  std::cout << "Введіть рядок (до 50 символів): ";
  std::cin.getline(str, max_len);
  std::string base = str;
  std::cout << "Введіть початкову позицію: ";
  std::cin >> pos;
  std::cout << "Введіть кількість символів для заміни: ";
  std::cin >> len;
  std::cout << "Введіть кількість символів для вставки: ";
  std::cin >> n;
  std::cout << "Введіть символ для вставки: ";
  std::cin >> c;
  // Власна функція заміни
  replace(&str, pos - 1, len, n, c);
  std::cout << std::endl << "Результат заміни: " << str << std::endl;
  // Системна функція заміни
  std::cout << "Результат заміни (стандартна бібліотека): "
            << base.replace(pos - 1, len, n, c) << std::endl;
}
