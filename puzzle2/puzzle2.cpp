#include<iostream>
#include<sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stringstream;

int main() {
	string input;
	int counter = 0;
	string min_max;
	string character;
	while (cin >> min_max >> character >> input) {
		string min_string;
		string max_string;
		stringstream min_max_stream(min_max);
		getline(min_max_stream, min_string, '-');
		getline(min_max_stream, max_string);
		int min = stoi(min_string);
		int max = stoi(max_string);
		int char_counter = 0;
		for (int i=0; i < input.size(); i++) {
			if (input[i] == character[0]) {
				char_counter++;
			}
		}
		if (char_counter >= min && char_counter <= max) {
			counter++;
		}
	}
	cout << counter;
	cout << endl;
}