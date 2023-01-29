#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  ifstream file("inputs/d3");
  string buffer;

  if (file) {
    file >> buffer;
    cout << buffer;

    cout.write(buffer.c_str(), buffer.size());
  }

  cout << "hello";

  return 0;
}
