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
		int first_pos = stoi(min_string);
		int second_pos = stoi(max_string);
		cout << input << endl;
		if ((input[first_pos+1] == character[0]) ^ (input[second_pos+1] == character[0])) { 
			counter++;
		} 
		
	}
	cout << counter;
	cout << endl;
}