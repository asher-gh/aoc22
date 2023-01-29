#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> parse_input(string path);

int main(int argc, char *argv[]) {
  vector<string> rucksack_items;
  int sum = 0;

  try {
    rucksack_items = parse_input("inputs/d3");
  } catch (const char *x) {
    cout << x;
  }
  // rucksack_items.push_back("hellow_world!");

  //==========Solution==========
  // a-z = [97-122]
  // A-Z = [65-90]

  // 1. split each string in middle

  // 2. compare which character is repeating in both strings (could use sets
  // for this)
  // 3. use ascii values to compute the priority and add it to sum

  for (const string &s : rucksack_items) {
    set<char> chars_left;
    set<char> chars_right;
    char *common = new char();

    for (char c : s.substr(0, s.size() / 2)) {
      chars_left.insert(c);
    }

    for (char c : s.substr(s.size() / 2)) {
      chars_right.insert(c);
    }

    set_intersection(chars_left.begin(), chars_left.end(), chars_right.begin(),
                     chars_right.end(), common);

    sum += (*common > 96 && *common < 123) ? *common - 96 : *common - 38;
  }

  cout << "[Day 3.1] \x1b[32m" << sum << endl;

  return 0;
}

/**
 * Read a file line-by-line, pushing each line to a vector and returning it.
 */
vector<string> parse_input(string path) {
  ifstream file(path);
  vector<string> v;
  string buf;

  if (file.is_open()) {

    while (file >> buf) {
      v.push_back(buf);
    }
  } else {
    throw "could not open file!\n"; // this is not best practice but works for
                                    // this simple problem
  }

  return v;
}
