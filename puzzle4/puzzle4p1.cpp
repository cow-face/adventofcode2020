#include<iostream>
#include<unordered_map>
#include<sstream>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::stringstream;
using std::string;

int main() {
	string input_string;
	string big_string;
	int valid_counter = 0;
	while (1) {
		unordered_map<string, string> input_map;
		while (getline(cin, input_string)) {
			if (input_string.empty()) {
					break;
			}
			stringstream input_stream1(input_string);
			while (input_stream1 >> input_string) { 
				stringstream input_stream(input_string);
				string key;
				string data_string;
				getline(input_stream, key, ':');
				getline(input_stream, data_string);
				input_map[key] = data_string;
				cout << input_string << endl;
			}
		}
		if (input_map.count("byr") && input_map.count("iyr") &&
			input_map.count("eyr") && input_map.count("hgt") &&
			input_map.count("hcl") && input_map.count("ecl") &&
			input_map.count("pid")) {

			valid_counter++;
		}
		if (input_map.empty()) {
			cout << valid_counter << endl;
			return 0;
		}
		cout << endl;
	}
}