#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int depart;
	cin >> depart;
	string input_string;
	vector<int> buses;
	while (getline(cin, input_string, ',')) {
		if (input_string == "x") {
			buses.push_back(0); 
			continue;
		}
		int input = stoi(input_string);
		buses.push_back(input);
	}
	for (auto& elem : buses) cout << elem << endl;
	long long int timestamp;
	unsigned long long int i_start = (100000000000000/buses[0])*buses[0];
	cout << i_start << endl;
	for (long long int i = i_start; true; i+=buses[0]) {
		bool valid = true;
		long long int j = i-1;
		for (const auto& bus : buses) {
			j++;
			if (bus == 0) continue;
			if (j % bus != 0) {
				valid = false;
				break;
			}
		}
		cout << i << "\n";
		if (valid) {
			timestamp = i; 
			break; 
		}
	}
	cout << timestamp << endl;
}