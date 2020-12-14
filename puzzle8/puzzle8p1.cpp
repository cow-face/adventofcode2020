#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector< pair<string, int> > instructions;
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
	int acc = 0;
	vector <int> executed;
	for (int i = 0; i < instructions.size();) {
		cout << "executing instruction " << i << endl;
		if (count(executed.begin(), executed.end(), i)) {
			cout << "instruction executed twice!" << endl;
			while (!(instructions[executed.back()].first == "jmp" || instructions[executed.back()].first == "nop")) {
				executed.pop_back();
				cout << "popped back" << endl;
			}
			if (instructions[executed.back()].first == "jmp") {
				instructions[executed.back()].first = "nop";
				cout << "changed jmp to nop at " << executed.back() << endl;
			}
			else {
				instructions[executed.back()].first = "jmp";
				cout << "changed nop to jmp at " << executed.back() << endl;
			}
			break;
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
	acc = 0;
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