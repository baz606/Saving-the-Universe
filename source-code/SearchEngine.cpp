#include "SearchEngine.h"

SearchEngine::SearchEngine()
{
  name = "";
  occurrenceGap = 0;
  occurrences = 0;
}

SearchEngine::SearchEngine(string n)
{
  name = n;
  occurrenceGap = 0;
  occurrences = 0;
}

int SearchEngine::GetNumOfSwitches()
{
  return numOfSwitches;
}

void CalculateSwitches(string queries[], int totalQueries)
{
  for(int i = 0; i < totalQueries; i++)
  {
    if(queries[i].compare(name) == 0)
    {
      // Collision
    }
  }
}
