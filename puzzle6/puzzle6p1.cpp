#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main() {
	string input_string;
	string big_string;
	int valid_counter = 0;
	int all_yes_counter = 0;
	while (1) {
		unordered_set<char> input_set;
		int yes_counter = 0;
		while (getline(cin, input_string)) {
			if (input_string.empty()) {
					break;
			}
			for (int i = 0; i < input_string.size(); i++) {
				if (!input_set.count(input_string[i])) {
					yes_counter++;
					input_set.emplace(input_string[i]);
				}
			}
			cout << "Yes counter: " << yes_counter << endl;
		}
		all_yes_counter += yes_counter;
		if (input_set.empty()) {
			cout << all_yes_counter;
			return 0;
		}
	}
}