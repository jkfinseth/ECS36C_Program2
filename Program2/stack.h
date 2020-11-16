#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <vector>

// A special implementation of stack
// performs calculations upon initialization
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

  // Constructor that performs calculations
  explicit Stack(std::string input) {
    unsigned int counter = 0;
    unsigned int length = 0;
    int placeholder = 0;
    int after_operator = 0;
    double temp = 0;
    double temp_1, temp_2;

    for (counter = 0; counter < input.length(); counter++) {
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

#endif  // STACK_H_
