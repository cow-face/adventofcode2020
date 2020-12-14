#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<string, int> > instructions;


bool DoesLoop() {
	int acc = 0;
	vector <int> executed;
	for (int i = 0; i < instructions.size();) {
		if (count(executed.begin(), executed.end(), i)) {
			cout << "loops" << endl;
			return true;
		}
		if (instructions[i].first == "acc") {
			acc += instructions[i].second;
			executed.push_back(i);
		}
		if (instructions[i].first == "nop") {
			executed.push_back(i);
		}
		if (instructions[i].first == "jmp") {
			executed.push_back(i);
			i += instructions[i].second;
		}
		else {
			i++;
		}
	}
	cout << "doesn't loop" << endl;
	return false;
}

int main() {
	string input_string;
	while (getline(cin, input_string)) {
		string instruction;
		string argument;
		stringstream input_stream(input_string);
		input_stream >> instruction;
		input_stream >> argument;
		int number = stoi(argument.substr(1));
		if (argument[0] == '-') {
			number *= -1;
		}
		instructions.push_back(pair(instruction, number));
	}
	/*for (auto& [instruct, num]: instructions) {
		cout << instruct << " " << num << endl;
	}*/
	for (int i = 0; i < instructions.size(); i++){
		if (instructions[i].first == "jmp" || instructions[i].first == "nop") {
			if (instructions[i].first == "jmp") {
				instructions[i].first = "nop";
			}
			else {
				instructions[i].first = "jmp";
			}
			if (!DoesLoop()) {
				break;
			}
			if (instructions[i].first == "jmp") {
				instructions[i].first = "nop";
			}
			else {
				instructions[i].first = "jmp";
			}
		}
		
	}
	int acc = 0;
	for (int i = 0; i < instructions.size();) {
		cout << "executing instruction " << i << endl;
		if (instructions[i].first == "acc") {
			acc += instructions[i].second;
		}
		if (instructions[i].first == "nop") {
		}
		if (instructions[i].first == "jmp") {
			i += instructions[i].second;
		}
		else {
			i++;
		}
	}
	cout << acc << endl;
}