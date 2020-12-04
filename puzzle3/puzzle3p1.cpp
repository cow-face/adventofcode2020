#include<iostream>
#include<vector>
#include<sstream>

using std::vector;
using std::string;
using std::cin;
using std::stringstream;
using std::cout;
using std::endl;

int main() {
	vector<vector<char> > char_array;
	string input_string;
	while (getline(cin, input_string)) {
		char input_char;
		vector<char> temp_vec;
		stringstream input_stream(input_string);
		while (input_stream >> input_char) {
			temp_vec.push_back(input_char);
		}
		char_array.push_back(temp_vec);
	}
	for (int i=0; i < char_array.size(); i++){
		vector<char> temp_vec = char_array.back();
		char_array.pop_back();
		for (int j=0; j < temp_vec.size(); j++) {
			cout << temp_vec[j];
		}
		cout << endl;
	}
}