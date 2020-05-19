// CopyRight Stephen Morrisson 2020
// All rights reserved.


#include "Dodle.h"

int main(int argc, const char* argv[])
{
  
  cout << "dodle V0.1" << endl;
  Dodle* that = new Dodle();
  int result = that->setupAndRun(argc, argv);

  cout << "dodle result: " << result << endl;
  return result;
}
