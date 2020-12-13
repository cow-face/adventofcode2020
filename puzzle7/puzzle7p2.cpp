//I'm extremely sorry to anyone who has to read this code


#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct triplet {
	string x;
	int y;
	string z;
};

int NumOfContainedBags(string attribute);
int NumOfContainedBagsHelper(string attribute);

vector< triplet > bags;

int main() {
	string input_string;
	while (getline(cin, input_string)) {
		stringstream input_stream(input_string);
		string attribute;
		string adj1;
		string adj2;
		input_stream >> adj1 >> adj2;
		attribute = adj1 + adj2;
		input_stream >> adj1 >> adj2; //gets rid of "contains" and "bags"
		if (input_stream.peek() == 'n') {
			bags.push_back({attribute, 0, "none"});
		}
		else {
			int num_of_bags;
			string contained_adj1;
			string contained_adj2;
			string ignored;
			while (input_stream >> num_of_bags >> contained_adj1 >> contained_adj2 >> ignored) {
				bags.push_back({attribute, num_of_bags, contained_adj1+contained_adj2});
			}
		}
	}
	for (auto& [val1, num, val2]: bags) {
		cout << val1 << ":" << num << ":" << val2 << endl;
	}
	cout << NumOfContainedBags("shinygold") << endl;
}

int NumOfContainedBagsHelper(string attribute) {
	int counter = 0;
	for (auto& [val1, num, val2]: bags) {
		if (val1 == attribute) {
			counter += num;
			if (val2 == "none") {
				return 0;
			}
			counter += num * NumOfContainedBagsHelper(val2);
		}
	}
	return counter;
}

int NumOfContainedBags(string attribute) {
	return NumOfContainedBagsHelper(attribute);
}