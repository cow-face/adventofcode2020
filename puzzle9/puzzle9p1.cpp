#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	vector<long long> numbers;
	string input_string;
	while (getline(cin, input_string)) {
		numbers.push_back(stoll(input_string));
	}

	bool valid = false;
	for (int i = 25; i < numbers.size(); i++) {
		valid = false;
		for (int j = i - 25; j < i; j++) {
			for (int k = i - 25; k < i; k++) {
				if (numbers[i] == numbers[j] + numbers[k]) {
					valid = true;
				}
			}
		}
		if (valid == false) {
			cout << numbers[i] << endl;
			return 0;
		}
	}
}