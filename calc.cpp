#include <iostream>
#include <vector>
#include <sstream>
#include <string>

long double calc(std::vector<std::string> s) {
  std::vector<std::string> so(s);
  for (unsigned short i = 0; i <= s.size(); i++) {
    if (s[i] == "(") {
      for (unsigned short x = i; x <= s.size(); x++) {
        if (s[x] == ")") {
          so.erase(so.begin()+i, so.begin()+x+1);
          std::vector<std::string> sb(s.begin()+i+1, s.begin()+x);
          so.insert(so.begin()+i, std::to_string(calc(sb)));
          return calc(so);
        }
      }
    }
  }
  for (unsigned short i = 0; i <= s.size(); i++) {
    if (s[i] == "*") {
      so.erase(so.begin()+i-1, so.begin()+i+2);
      so.insert(so.begin()+i-1, std::to_string(stod(s[i-1]) * stod(s[i+1])));
      return calc(so);
    }
    else if (s[i] == "/") {
      so.erase(so.begin()+i-1, so.begin()+i+2);
      so.insert(so.begin()+i-1, std::to_string(stod(s[i-1]) / stod(s[i+1])));
      return calc(so);
    }
  }
  for (unsigned short i = 0; i <= s.size(); i++) {
    if (s[i] == "+") {
      so.erase(so.begin()+i-1, so.begin()+i+2);
      so.insert(so.begin()+i-1, std::to_string(stod(s[i-1]) + stod(s[i+1])));
      return calc(so);
    }
    else if (s[i] == "-") {
      so.erase(so.begin()+i-1, so.begin()+i+2);
      so.insert(so.begin()+i-1, std::to_string(stod(s[i-1]) - stod(s[i+1])));
      return calc(so);
    }
  }
  unsigned short op = 0;
  for (unsigned short i = 0; i <= s.size(); i++) {
    if (s[i] == "*" || s[i] == "/" || s[i] == "+" || s[i] == "-" ) {
      op++;
    }
  }
  if (op == 0) {
    return stod(s[0]);
  }
  return 1;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> sv;
  const char del = ' ';
  std::string val;
  std::string exp;
  if (argc == 2) {
    exp = argv[1];
  }
  else {
    std::cout << "Give an expression: ";
    std::getline(std::cin, exp);
  }
  std::stringstream streamExp(exp);
  while (std::getline(streamExp, val, del)) {
    sv.push_back(val);
  }
  std::cout << calc(sv) << std::endl;
  return 0;
}
