#include <string>

using namespace std;

class SearchEngine
{
private:
  int numOfSwitches;
  string name;

public:
  // Constructors
  SearchEngine();
  SearchEngine(string n);

  // Setters
  void SetName(string n);

  // Getters
  int GetName();
  int GetNumOfSwitches();

  void CalculateSwitches(string queries[], int totalQueries);
};
