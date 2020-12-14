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
	int sum_target;
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
			sum_target = numbers[i];
			cout << numbers[i] << endl;
		}
	}

	for (int i = 0; i < numbers.size(); i++){
		int smallest = numbers[i];
		int largest = numbers[i];
		int sum = smallest;
		int j = i+1;
		while (sum < sum_target && j < numbers.size()) {
			sum += numbers[j];
			if (numbers[j] > largest) largest = numbers[j];
			if (numbers[j] < smallest) smallest = numbers[j];
			if (sum == sum_target) {
				cout << "smallest: " << smallest << endl;
				cout << "largest: " << largest << endl;
				cout << "sum: " << sum << endl;
				cout << smallest + largest << endl;
			}
			j++;
		}
	}
}