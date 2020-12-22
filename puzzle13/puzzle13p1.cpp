#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int depart;
	cin >> depart;
	cout << "depart:" << depart << endl;
	string input_string;
	vector<int> buses;
	while (getline(cin, input_string, ',')) {
		if (input_string == "x") continue;
		int input = stoi(input_string);
		buses.push_back(input);
		cout << input << endl;
	}
	sort(buses.begin(), buses.end());
	long int earliest_bus = 0;
	long int number_of_mins = 0;
	for (int i = depart; true; i++) {
		for (const auto& bus: buses) {
			if (i % bus == 0) {
				earliest_bus = bus;
				break;
			}
		}
		if (earliest_bus) {
			number_of_mins = i-depart;
			break;
		}
	}
	cout << number_of_mins << endl;
	cout << earliest_bus << endl;
	cout << number_of_mins * earliest_bus << endl;
}