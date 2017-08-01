#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Global variables
int numOfCases;
int numOfSearchEngines;
int numOfQueries;

int ChooseSearchEngine(string searchEngines[], string queries[], int startingQueryIndex, int curIndex);

int main()
{
  string currentSearchEngine = "";
  int firstOccurence = 0;
  int numOfSwitches = 0;
  string temp = "";
  stringstream ss;

  // Gets the number of test cases
  getline(cin, temp);
  ss.str(temp);
  ss >> numOfCases;

  // Resets the string stream
  ss.str("");
  ss.clear();

  for(int i = 1; i <= numOfCases; i++)
  {
    numOfSwitches = 0;
    firstOccurence = 0;

    // Gets the number of search engines
    getline(cin, temp);
    ss.str(temp);
    ss >> numOfSearchEngines;

    // Creates a string array to store the search engines
    string searchEngines[numOfSearchEngines] = {};

    for(int j = 0; j < numOfSearchEngines; j++)
    {
      getline(cin, temp);
      searchEngines[j] = temp;
      //cout << searchEngines[j] << endl;
    }

    ss.str("");
    ss.clear();

    getline(cin, temp);
    ss.str(temp);
    ss >> numOfQueries;

    string queries[numOfQueries] = {};
    for(int z = 0; z < numOfQueries; z++)
    {
      getline(cin, temp);
      queries[z] = temp;
      //cout << queries[z] << endl;
    }

    // This loop calculates which optimal search engine to
    // start off the query processings.
    int temp = 0;
    int startingIndex = 0;
    for(int k = 0; k < numOfSearchEngines; k++)
    {
      firstOccurence = 0;
      for(int m = 0; m < numOfQueries; m++)
      {
        if(searchEngines[k].compare(queries[m]) == 0)
        {
          break;
        }
        else
        {
          firstOccurence++;
        }
      }
      if(k == 0)
      {
        temp = firstOccurence;
      }
      else if(firstOccurence > temp)
      {
        temp = firstOccurence;
        startingIndex = k;
      }
    }

    bool isMatch = false;

    // Query processing
    for(int k = 0; k < numOfQueries; k++)
    {
      // If there is a Collision
      if(searchEngines[startingIndex].compare(queries[k]) == 0)
      {
        numOfSwitches++;
        startingIndex = ChooseSearchEngine(searchEngines, queries, k, startingIndex);
      }
    }

    cout << "Case #" << i << ": " << numOfSwitches << endl;
    ss.str("");
    ss.clear();
  }

  return 0;
}

int ChooseSearchEngine(string searchEngines[], string queries[], int startingQueryIndex, int curIndex)
{
  int temp = 0;
  int k = 0;
  int startingIndex = k;
  int firstOccurence = 0;
  for(int k = 0; k < numOfSearchEngines; k++)
  {
    if(k == curIndex)
    {
      continue;
    }
    firstOccurence = 0;
    for(int m = startingQueryIndex; m < numOfQueries; m++)
    {
      if(searchEngines[k].compare(queries[m]) == 0)
      {
        break;
      }
      else
      {
        firstOccurence++;
      }
    }
    if(k == 0)
    {
      temp = firstOccurence;
    }
    else if(firstOccurence > temp)
    {
      temp = firstOccurence;
      startingIndex = k;
    }
  }
  return startingIndex;
}
