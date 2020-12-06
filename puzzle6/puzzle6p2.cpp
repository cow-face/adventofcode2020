#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int main() {
  string input_string;
  int all_yes_counter = 0;
  while (true) {
    bool first = true;
    unordered_set<char> input_set;
    string erase_string = "";
    int yes_counter = 0;
    bool erased = false;
    while (getline(cin, input_string)) {
      if (input_string.empty()) {
        break;
      }
      if (!first) {
        for (auto& elem : input_set) {
          if (input_string.find(elem) > input_string.size()) {
            erase_string += elem;
            erased = true;
          }
        }
        for (char& character: erase_string) {
	      	while (input_set.count(character)) {
	      		input_set.erase(character);
	      	}
      	}
      }
      else {
        for (char & elem : input_string) {
          input_set.insert(elem);
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