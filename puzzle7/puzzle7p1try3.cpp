#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int ContainsBagHelper(string attribute, int counter);
int ContainsBag(string attribute);

vector< pair<string, string> > bags;

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
			bags.push_back(pair(attribute, "none"));
		}
		else {
			int num_of_bags;
			string contained_adj1;
			string contained_adj2;
			string ignored;
			while (input_stream >> num_of_bags >> contained_adj1 >> contained_adj2 >> ignored) {
				bags.push_back(pair(attribute, contained_adj1+contained_adj2));
			}
		}
	}
	for (auto& [val1, val2]: bags) {
		cout << val1 << ":" << val2 << endl;
	}
	cout << ContainsBag("shinygold") << endl;
}

bool ContainsBagHelper(string attribute, string attribute2) {
	bool contains = false;
	for (auto& [val1, val2]: bags) {
		if (val1 == attribute2) {
			if (val2 == attribute) {
				return true;
			}
			if (val2 == "none") return false;
			contains = ContainsBagHelper(attribute, val2);
			if (contains) return true;
		} 
	}
	return false;
}

int ContainsBag(string attribute) {
	int counter = 0;
	string alreadycounted = "";
	for (auto& [val1, val2]: bags){
		if (alreadycounted.find(val1) == string::npos) {
			if (ContainsBagHelper(attribute, val1)) {
				counter++;
				alreadycounted += val1;
			}
		}
	}
	return counter;
}