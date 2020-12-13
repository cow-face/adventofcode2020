#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>

using namespace std;

class Bag {
private:
	vector<Bag> can_contain;
	string type_of_bag;
	int num = -1;

	bool CanContainHelper(string type_wanted, Bag bag) {
		for (const auto& elem: bag.can_contain) {
			if (type_wanted == elem.type_of_bag) {
				return true;
			}
		}
		bool contains = false;
		for (const auto& elem: bag.can_contain) {
			if (CanContainHelper(type_wanted, elem)) {
				contains = true;
			}
		}
		return contains;
	}

public:
	bool CanContain(string type_wanted) {
		return CanContainHelper(type_wanted, *this);
	}

	void DisplayCanContain() {
		for (const auto& bag: can_contain) {
			cout << bag.num << " of " << bag.type_of_bag << " bags" << endl;
		}
	}

	void AddCanContain(Bag bag, int n) {
		bag.num = n;
		can_contain.push_back(bag);
	}

	const string TypeOfBag() {
		return type_of_bag;
	}

	Bag(string adj1, string adj2) {
		type_of_bag = adj1 + adj2;
	}

	Bag(string type) {
		type_of_bag = type;
	}

	Bag operator=(const Bag&) {
		Bag bag(this->type_of_bag);
		bag.can_contain = this->can_contain;
		bag.num = this->num;
		return bag;
	}
};

int main() {
	string input_string;
	vector<Bag> bags;
	while (getline(cin, input_string)) {
		stringstream input_stream(input_string);
		string adjective1;
		string adjective2;
		string ignored;
		input_stream >> adjective1 >> adjective2 >> ignored >> ignored;
		Bag bag(adjective1,adjective2);
		int num_of_bags;
		while (input_stream >> num_of_bags >> adjective1 >> adjective2 >> ignored) {
			Bag contained_bag(adjective1, adjective2);
			bag.AddCanContain(contained_bag, num_of_bags);
		}
		bags.push_back(bag);
	}
	int contains_count = 0;
	for (int i = 0; i < bags.size(); i++) {
		cout << bags[i].TypeOfBag() << " Contains: "<< endl;
		if (bags[i].CanContain("shinygold")) {
			contains_count++;
		}
		bags[i].DisplayCanContain();
		cout << endl;
	}
	cout << endl;
	cout << contains_count << endl;
	return 0;
}