#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "stack.h"
/* Stores and performs the calculations
class Stack {
 public:
  std::vector<double> items;

  double stod(std::string s) {
    std::istringstream temp(s);
    double storage;

    if (!(temp >> storage))
      return 0;

    return storage;
  }

  // Constructor to perform the calculation
  explicit Stack(std::string input) {
    unsigned int counter = 0;
    unsigned int length = 0;
    int placeholder = 0;
    int after_operator = 0;
    double temp = 0;
    double temp_1, temp_2;

    for (counter = 0; counter < input.length(); counter++)  {
      if ((isspace(input[counter]) ||
           input[counter] == '\n') &&
           after_operator == 0) {
        items.push_back(stod(input.substr(placeholder, length)));
        placeholder = counter+1;
        length = 0;
      } else {
        length++;
      }

      if ((isspace(input[counter]) ||
           input[counter] == '\n') &&
           after_operator == 1) {
        after_operator = 0;
        placeholder = counter+1;
        length = 0;
      }

      // Check for operators
      if (input[counter] == '+') {
        if (items.size() >= 2) {
          temp_1 = items[items.size() - 1];
          temp_2 = items[items.size() - 2];
          temp = temp_2 + temp_1;

          items.pop_back();
          items.pop_back();
          items.push_back(temp);
        } else {
          std::cerr << "Error: invalid expression" << std::endl;
        }
        after_operator = 1;
      }

      if (input[counter] == '-') {
        if (input.size() >= 2) {
          temp_1 = items[items.size() - 1];
          temp_2 = items[items.size() - 2];
          temp = temp_2 - temp_1;

          items.pop_back();
          items.pop_back();
          items.push_back(temp);
        } else {
          std::cerr << "Error: invalid expression" << std::endl;
        }
        after_operator = 1;
      }

      if (input[counter] == '*') {
        if (input.size() >= 2) {
          temp_1 = items[items.size() - 1];
          temp_2 = items[items.size() - 2];
          temp = temp_2 * temp_1;

          items.pop_back();
          items.pop_back();
          items.push_back(temp);
        } else {
          std::cerr << "Error: invalid expression" << std::endl;
        }
        after_operator = 1;
      }

      if (input[counter] == '/') {
        if (input.size() >= 2) {
          temp_1 = items[items.size() - 1];
          temp_2 = items[items.size() - 2];
          temp = temp_2 / temp_1;

          items.pop_back();
          items.pop_back();
          items.push_back(temp);
        } else {
          std::cerr << "Error: invalid expression" << std::endl;
        }
        after_operator = 1;
      }
    }
  }

  // Show final solution
  friend std::ostream& operator<< (std::ostream& os, const Stack& stack) {
    os << stack.items[0] << std::endl;

    return os;
  }
};
*/
int main() {
  std::string input;
  unsigned int counter, condition, condition2;
  int number, signs, beginning;

  // Get user input
  while (getline(std::cin, input)) {
    // Reset conditions, number, and signs
    condition = 0;
    number = 0;
    signs = 0;
    condition2 = 0;

    // Make sure all input is valid
    for (counter = 0; counter < input.length(); counter++) {
      if (input[counter] != ' ' &&
          input[counter] != '\n' &&
          input[counter] != '+' &&
          input[counter] != '-' &&
          input[counter] != '*' &&
          input[counter] != '/' &&
          input[counter] != '.' &&
          !isdigit(input[counter])) {
        std::cerr << "Error: unknown symbol \'"
                  << input[counter] << "\'" << std::endl;
        condition = 1;
      }

      if (condition == 0) {
        if (isdigit(input[counter])) {
          if (counter > 0) {
            if (isspace(input[counter - 1]))
              number++;
          } else {
            number++;
          }
        }
        if (input[counter] != ' ' &&
            !isdigit(input[counter]) &&
            input[counter] != '.') {
          if (counter == 0) {
            signs++;
          } else {
            if (input[counter - 1] != ' ') {
              if (condition2 == 0)
                beginning = counter - 1;
              condition2++;
            } else {
              signs++;
            }
          }
        }
      }
    }

    // Make sure chain of known symbols was not input
    if (condition2 != 0) {
      std::cerr << "Error: unknown symbol \'"
                << input.substr(beginning, condition2 + 1)
                << "\'" << std::endl;
      condition = 1;
    }

    // Make sure correct amount of numbers and signs were input
    if (condition == 0) {
      if (!(number == signs + 1)) {
        std::cerr << "Error: invalid expression" << std::endl;
        condition = 1;
      }
    }

    if (condition == 0) {
      Stack calculator(input);

      // If input was valid, return answer
      if (calculator.items.size() == 1) {
        std::cout << calculator;
      } else {
        std::cerr << "Error: invalid expression" << std::endl;
       }
    }
  }
  std::cout << "Bye!" << std::endl;

  return 0;
}
