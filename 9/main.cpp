#include "task1.h"
#include "task2.h"
#include <iostream>

int main() {
  int n;
  // Головне меню
  while (n != 0) {
    std::cout << std::endl << std::endl;
    std::cout << "[      Головне Меню      ]" << std::endl << std::endl;
    std::cout << "[ 1 ] Завдання 1" << std::endl;
    std::cout << "[ 2 ] Завдання 2" << std::endl;
    std::cout << "[ 0 ] Вихід" << std::endl << std::endl;
    std::cout << "Оберіть пункт меню: ";
    std::cin >> n;
    std::cin.ignore();
    switch (n) {
    case 1:
      std::cout << std::endl << std::endl;
      std::cout << "[      Завдання 1        ]" << std::endl << std::endl;
      task1();
      break;
    case 2:
      std::cout << std::endl << std::endl;
      std::cout << "[      Завдання 2        ]" << std::endl << std::endl;
      task2();
      break;
    case 0:
      return 0;
    default:
      std::cout << std::endl
                << std::endl
                << "Невірно обрано пункт меню. Спробуйте знову";
      break;
    }
    // Очікування на Enter
    std::cout << std::endl
              << std::endl
              << "Натисніть Enter для повернення до головного меню";
    std::cin.get();
    std::cin.ignore();
  }
}
