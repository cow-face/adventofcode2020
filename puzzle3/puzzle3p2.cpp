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
	for (int i=0; i < char_array.size(); i++) {
		for (int j=0; j < char_array[i].size(); j++) {
			cout << char_array[i][j];
		}
		cout << endl;
	}
	long product = 1;
	for (int j = 1; j < 8; j+= 2) {
		int x_pos = 0;
		int tree_counter = 0;
		for (int i = 0; i < char_array.size(); i++) {
			if (char_array[i][x_pos % char_array[i].size()] == '#') {
				tree_counter++;
			}
			x_pos += j;
		}
		cout << "Right " << j << " " << tree_counter << endl;
		product *= tree_counter;
	}
	int x_pos = 0;
	int tree_counter = 0;
	for (int i = 0; i < char_array.size(); i+=2) {
		if (char_array[i][x_pos % char_array[i].size()] == '#') {
			tree_counter++;
		}
		x_pos++;
	}
	cout << "Right 1 down 2 " << tree_counter << endl;
	product *= tree_counter;
	cout << "Product " << product << endl;

}