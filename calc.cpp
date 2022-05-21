#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

unsigned short parens(std::vector<std::string> s, unsigned short i) {
  std::stack<unsigned short> st;
  for (unsigned short ii=i; ii < s.size(); ii++) {
    if (s[ii] == "(") {
      st.push(0);
    }
    else if (s[ii] == ")") {
      st.pop();
      if (st.empty()) {
        return ii;
      }
    }
  }
  return 0;
}

long double calc(std::vector<std::string> s) {
  std::vector<std::string> so(s);
  for (unsigned short i = 0; i <= s.size(); i++) {
    if (s[i] == "("){
      unsigned short d = parens(s, i);
      so.erase(so.begin()+i, so.begin()+d+1);
      std::vector<std::string> sb(s.begin()+i+1, s.begin()+d);
      so.insert(so.begin()+i, std::to_string(calc(sb)));
      return calc(so);
    }
  }
  for (unsigned short i = 0; i <= s.size(); i++) {
    if (s[i] == "**") {
      so.erase(so.begin()+i-1, so.begin()+i+2);
      so.insert(so.begin()+i-1, std::to_string(std::pow(stod(s[i-1]), stod(s[i+1]))));
      return calc(so);
    }
    else if (s[i] == "//") {
        so.erase(so.begin()+i, so.begin()+i+1);
        so.insert(so.begin()+i, std::to_string(std::sqrt(stod(s[i+1]))));
        return calc(so);
    }
  }
  for (unsigned short i = 1; i <= s.size(); i++) {
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
  for (unsigned short i = 1; i <= s.size(); i++) {
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
  return stod(s[0]);
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
