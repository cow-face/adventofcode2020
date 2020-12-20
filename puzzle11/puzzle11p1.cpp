#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector< vector<char> > seats;
vector< vector<char> > next_frame;

int OccupiedSeats() {
	int occupied_count = 0;
	for (auto& row : seats) {
		occupied_count += count(row.begin(), row.end(), '#');
	}
	return occupied_count;
}

bool IsEmpty(int x, int y) {
	if (x >= seats.size() || x < 0) return true;
	if (y >= seats[x].size() || y < 0) return true;
	if (seats[x][y] != '#') return true;
	return false;
}

int AdjOccupied(int x, int y) {
	int occupied_count = 0;
	if (!IsEmpty(x,y-1)) occupied_count++;
	if (!IsEmpty(x,y+1)) occupied_count++;
	if (!IsEmpty(x-1, y)) occupied_count++;
	if (!IsEmpty(x+1, y)) occupied_count++;
	if (!IsEmpty(x-1, y-1)) occupied_count++;
	if (!IsEmpty(x-1, y+1)) occupied_count++;
	if (!IsEmpty(x+1, y-1)) occupied_count++;
	if (!IsEmpty(x+1, y+1)) occupied_count++;
	return occupied_count;
}

void DisplaySeats() {
	for (auto& row: seats) {
			for (auto& elem: row) {
				cout << elem;
			}
			cout << endl;
		}
	cout << endl;
}

bool Stabilized() {
	if (seats == next_frame) return true;
	return false;
}

int main() {
	string input_string;
	while (getline(cin, input_string)) {
		stringstream input_stream(input_string);
		vector<char> new_row;
		char chair;
		while (input_stream >> chair) {
			new_row.push_back(chair);
		}
		seats.push_back(new_row);
	}

	int frame = 0;
	next_frame = seats;

	do {
		seats = next_frame;
		cout << frame << endl;
		DisplaySeats();
		for (int x = 0; x < seats.size(); x++) {
			for (int y = 0; y < seats[x].size(); y++) {
				if (seats[x][y] == 'L') {
					if (AdjOccupied(x,y) == 0) {
						next_frame[x][y] = '#';
					}
				}
				else if (seats[x][y] == '#') {
					if (AdjOccupied(x,y) >= 4) {
						next_frame[x][y] = 'L';
					}
				}
			}
		}
		frame++;
	} while (!Stabilized());
	cout << OccupiedSeats() << endl;
}