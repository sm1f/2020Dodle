// CopyRight Stephen Morrisson 2020
// All rights reserved.


#include "CommandLine.h"

CommandLine::CommandLine()
  : CppBase()
{
}

string CommandLine::className()
{
  return "CommandLine";
}


void CommandLine::help()
{
  cout << "Help:" << endl;
  cout << "  help: print command info" << endl;
  cout << "  init: initial an empty game" << endl;
  cout << "  play: continue play" << endl;
  cout << "  reset: reset to empty game." << endl;
}

bool CommandLine::parse(int argc, const char* argv[])
{
  SHOWVARVAL(argc);
  return false;
}


