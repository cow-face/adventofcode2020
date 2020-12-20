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
	if (seats[x][y] != '#') return true;
	return false;
}

int AdjOccupied(int x, int y) {
	int occupied_count = 0;
	//verticals
	for (int i = 1; x-i >= 0; i++) {
		if (seats[x-i][y] == 'L') break;
		if (!IsEmpty(x-i,y)) {
			occupied_count++;
			break;
		}
	}
	for (int i = 1; x+i < seats.size(); i++) {
		if (seats[x+i][y] == 'L') break;
		if (!IsEmpty(x+i,y)) {
			occupied_count++;
			break;
		}
	}
	//diagonals
	for (int i = 1; x-i >= 0 && y-i >= 0; i++) {
		if (seats[x-i][y-i] == 'L') break;
		if (!IsEmpty(x-i,y-i)) {
			occupied_count++;
			break;
		}
	}
	for (int i = 1; x+i < seats.size() && y+i < seats[x].size(); i++) {
		if (seats[x+i][y+i] == 'L') break;
		if (!IsEmpty(x+i,y+i)) {
			occupied_count++;
			break;
		}
	}
	for (int i = 1; x+i < seats.size() && y-i >= 0; i++) {
		if (seats[x+i][y-i] == 'L') break;
		if (!IsEmpty(x+i,y-i)) {
			occupied_count++;
			break;
		}
	}
	for (int i = 1; x-i >= 0 && y+i < seats[x].size(); i++) {
		if (seats[x-i][y+i] == 'L') break;
		if (!IsEmpty(x-i,y+i)) {
			occupied_count++;
			break;
		}
	}
	
	//horizontals
	for (int i = 1; y-i >= 0; i++) {
		if (seats[x][y-i] == 'L') break;
		if (!IsEmpty(x,y-i)) {
			occupied_count++;
			break;
		}
	}
	for (int i = 1; y+i < seats[x].size(); i++) {
		if (seats[x][y+i] == 'L') break;
		if (!IsEmpty(x,y+i)) {
			occupied_count++;
			break;
		}
	}
	return occupied_count;
}

void DisplaySeats() {
	for (const auto& row: seats) {
			for (const auto& elem: row) {
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

	cout << seats.size() << endl;
	cout << seats[0].size() << endl;
	cout << endl;
	int frame = 0;
	next_frame = seats;

	do {
		seats = next_frame;
		cout << frame << endl;
		DisplaySeats();
		for (int x = 0; x < seats.size(); x++) {
			for (int y = 0; y < seats[0].size(); y++) {
				if (seats[x][y] == 'L') {
					if (AdjOccupied(x,y) == 0) {
						next_frame[x][y] = '#';
					}
				}
				else if (seats[x][y] == '#') {
					if (AdjOccupied(x,y) >= 5) {
						next_frame[x][y] = 'L';
					}
				}
			}
		}
		frame++;
	} while (!Stabilized());
	cout << OccupiedSeats() << endl;
}