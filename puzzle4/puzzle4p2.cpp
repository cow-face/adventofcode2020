#include<iostream>
#include<unordered_map>
#include<sstream>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::stringstream;
using std::string;
using std::stoi;
using std::isdigit;

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
			bool valid = true;

			if (!(stoi(input_map["byr"]) >= 1920 && stoi(input_map["byr"]) <= 2002 &&
				stoi(input_map["iyr"]) >= 2010 && stoi(input_map["iyr"]) <= 2020 &&
				stoi(input_map["eyr"]) >= 2020 && stoi(input_map["eyr"]) <= 2030)) {
				valid = false;
				
			}
			string height = input_map["hgt"];
			if (height[height.size() - 2] == 'c'){
				if (!(stoi(height) >= 150 && stoi(height) <= 193)) {
					valid = false;
				}
			}  
			else if (height[height.size() - 2] == 'i'){
				if (!(stoi(height) >= 59 && stoi(height) <= 76)) {
					valid = false;
				}
			}
			else {
				valid = false;
			}
			string hair_color = input_map["hcl"]; 
			if (hair_color.size() != 7) {
				valid = false;
			}
			if (hair_color[0] == '#') {
				for (int i = 1; i < hair_color.size(); i++) {
					if (!isdigit(hair_color[i])) {
						char tmp = hair_color[i];
						if (!(tmp == 'a' || tmp == 'b' || tmp == 'c' 
							|| tmp == 'd' || tmp == 'e' || tmp == 'f')) {
							valid = false;
						}
					}
				}
			}
			else {
				valid = false;
			}

			string e_color = input_map["ecl"];
			if (!(e_color == "amb" || e_color == "blu" || e_color == "brn" ||
				e_color == "gry" || e_color == "grn" || e_color == "hzl" || e_color == "oth")) {
				valid = false;
			}

			string pid = input_map["pid"];
			if (pid.size() != 9) {
				valid = false;
			}

			if (valid) {
				valid_counter++;
			}

		}
		
		if (input_map.empty()) {
			cout << valid_counter << endl;
			return 0;
		}
		cout << endl;
	}
}