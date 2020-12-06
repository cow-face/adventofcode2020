#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int main() {
  string input_string;
  string big_string;
  int valid_counter = 0;
  int all_yes_counter = 0;
  while (true) {
    bool first = true;
    unordered_set<char> input_set;
    int yes_counter = 0;
    bool erased = false;
    while (getline(cin, input_string)) {
      if (input_string.empty()) {
        break;
      }
      if (!first) {
        for (const auto& elem:input_set) {
          if (input_string.find(elem) == string::npos) {
            while (input_set.count(elem)) {
              input_set.erase(elem);
            }
            erased = true;
          }
        }
      }
      else {
        for (char & i : input_string) {
          input_set.emplace(i);
        }
        first = false;
      }
    }
    yes_counter = input_set.size();
    all_yes_counter += yes_counter;
    for (const auto& elem: input_set) cout << " " << elem;
    cout << endl;
    if (input_set.empty() && !erased) {
      cout << all_yes_counter << endl;
      return 0;
    }
  }
}