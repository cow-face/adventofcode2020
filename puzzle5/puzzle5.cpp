#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	string input_string;
	int biggest_id = 0;
	vector<int> input_vec;
	while (cin >> input_string) {
		int cmin = 0;
		int cmax = 127;
		for (int i = 0; i < 7; i++) {
			if (input_string[i] == 'B') {
				cmin = (cmax-cmin)/2+1+cmin;
			}
			else {
				cmax = ((cmax-cmin)/2)+cmin;
			}
		}
		int rmin = 0;
		int rmax = 7;
		for (int i = 7; i < 10; i++) {
			if (input_string[i] == 'R') {
				rmin = (rmax-rmin)/2+1+rmin;
			}
			else {
				rmax = ((rmax-rmin)/2)+rmin;
			}
		}
		int id = (cmax * 8) + rmax;
		input_vec.push_back(id);
		if (id > biggest_id) {
			biggest_id = id;
		}
	}
	sort(input_vec.begin(), input_vec.end());
	int missing_id;
	for (int i = 0; i < input_vec.size()-1; i++) {
		cout << input_vec[i] << endl;
		if (input_vec[i+1] != input_vec[i]+1) {
			missing_id = input_vec[i]+1;
		}
	}
	cout << endl;
	cout << "Biggest_id: " << biggest_id << endl;
	cout << "Missing_id: " << missing_id << endl;
}