#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "SearchEngine.h"

using namespace std;

// Global variables
int numOfCases = 0;
int numOfSearchEngines = 0;
int numOfQueries = 0;

bool HandleCollision(string searchEngines[], string queries[], int curSearchEngineIndex, int queryIndex);

int main()
{
  srand(time(NULL));
  string currentSearchEngine = "";
  int numOfSwitches = 0;
  int randomIndex = 0;
  bool isOptimum = false;
  int totalSwitches = 0;
  int num = 0;
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

    //bool hasOccurred[numOfSearchEngines];
    //std::fill_n(hasOccurred, numOfSearchEngines, false);

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

    for(int k = 0; k < numOfSearchEngines; k++)
    {
      numOfSwitches = 0;
      currentSearchEngine = searchEngines[k];
      for(int m = 0; m < numOfQueries; m++)
      {
        //cout << m << endl;
        if(currentSearchEngine.compare(queries[m]) == 0)
        {
          //cout << m << endl;
          //cout << "true" << endl;
          // Collision
          isOptimum = HandleCollision(searchEngines, queries, k, m);
          if(isOptimum)
          {
            numOfSwitches++;
            break;
          }
          numOfSwitches++;

          /////////////////////////NEED TO WORK ON THIS///////////////////////////////////////
          randomIndex = rand() % ((numOfSearchEngines - 1) - (k + 1) + 1) + (k + 1);
          cout << randomIndex << endl;
          currentSearchEngine = searchEngines[randomIndex];
          ///////////////////////////////////////////////////////////////////////////////////
        }
      }
      if(k == 0)
      {
        totalSwitches = numOfSwitches;
      }
      if(numOfSwitches < totalSwitches)
      {
        totalSwitches = numOfSwitches;
      }
      //if(isOptimum) break;
    }

    cout << "Case #" << i << ": " << totalSwitches << endl;
    ss.str("");
    ss.clear();
  }

  return 0;
}

bool HandleCollision(string searchEngines[], string queries[], int curSearchEngineIndex, int queryIndex)
{
  bool isMatch = true;
  for(int j = 0; j < numOfSearchEngines; j++)
  {
    if(j == curSearchEngineIndex)
    {
      //j++;
      continue;
    }
    for(int i = queryIndex + 1; i < numOfQueries; i++)
    {
      if(queries[i].compare(searchEngines[j]) == 0)
      {
        isMatch = true;
        break;
      }
      else
      {
        isMatch = false;
      }
    }

    if(!isMatch)
    {
      return true;
    }
  }
  return false;
}
