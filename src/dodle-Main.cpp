// CopyRight Stephen Morrisson 2020
// All rights reserved.


#include "common.h"


class CommandLine {
public:
  CommandLine() {}
  virtual ~CommandLine() {}

  virtual void help();
  virtual bool parse(int argc, const char* argv[]);
};

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

class Dodle {
  public:
  Dodle() {}
  virtual ~Dodle() {}

  virtual bool setup();

  virtual int setupAndRun(int argc, const char* argv[]);
};

bool Dodle::setup()
{
  NYI("");
  return false;
}

int Dodle::setupAndRun(int argc, const char* argv[])
{
  SHOWVARVAL(argc);
  if (! setup()) {
    FAIL("");
  } else {
    NFI("");
  }
  return -1;
}


int main(int argc, const char* argv[])
{
  
  cout << "dodle V0.0" << endl;
  Dodle* that = new Dodle();
  int result = that->setupAndRun(argc, argv);

  cout << "dodle result: " << result << endl;
  return result;
}
