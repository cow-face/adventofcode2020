#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <algorithm>

using namespace std;

struct Bag {
	vector<Bag*> connections;
	string attribute;
};

int main() {
	string input_string;
	vector<Bag*> bags;
	while (getline(cin, input_string)) {
		stringstream input_stream(input_string);
		string adjective1;
		string adjective2;
		string ignored;
		input_stream >> adjective1 >> adjective2 >> ignored >> ignored;
		Bag bag;
		bag.attribute = adjective1 + adjective2;
		vector<Bag*> connections;
		int num_of_bags;
		while (input_stream >> num_of_bags >> adjective1 >> adjective2 >> ignored) {
			Bag contained_bag;
			contained_bag.attribute = adjective1 + adjective2;
			bool contained = false;
			for (int i = 0; i < bags.size(); i++) {
				Bag temp_bag = *bags[i];
				if (temp_bag.attribute == contained_bag.attribute) {
					contained = true;
				}
			}
			if (contained) {
				/*connections.push_back()*/
			}
			break;
		}
	}
}