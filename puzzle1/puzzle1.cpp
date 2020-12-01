#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

int main() {
	vector<int> invec;
	int input;
	while (cin >> input) {
		invec.push_back(input);
	}
	for (int i = 0; i < invec.size(); i++){
		for (int j = 0; j < invec.size(); j++) {
			if (invec[i] + invec[j] == 2020) {
				cout << (invec[i] * invec[j]) << endl;
				break;
			}
		}
	}
}