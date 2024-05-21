
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector of int.
// used to store the records
typedef vector<int> Records;

// https://www.cplusplus.com/doc/tutorial/files/
class RecordsManager {
 private:
  fstream _file;
  string _filename;

 public:
  RecordsManager(string filename) : _filename(filename) {}
  void read(Records& records) {
    _file.open(_filename, ios::in);
    if (_file.is_open()) {
      string line;
      try {
        while (std::getline(_file, line)) {
          records.push_back(stoi(line));
        }
      } catch (const std::invalid_argument& e) {
        _file.close();
        throw;
      }
      _file.close();
    }
  }
};

int main() {
  try {
    RecordsManager recordM("test_corrupt1.txt");
    Records myRecords;
    recordM.read(myRecords);

    // calculate and print out the sum
    int sum = 0;
    for (int i = 0; i < myRecords.size(); i++) {
      sum += myRecords[i];
    }
    cout << sum << endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "An error occurred: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
