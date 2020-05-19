// CopyRight Stephen Morrisson 2020
// All rights reserved.


#include "Dodle.h"

DodleCommandLine::DodleCommandLine()
  : __super()
{
}

DodleCommandLine* DodleCommandLine::create(Dodle* that)
{
  DodleCommandLine* result = new DodleCommandLine();
  result->addNoCommandAction(new CommandLine_PrintHelpAction(result));
  NYI("");
  return result;
}

bool DodleCommandLine::setup(Dodle* that)
{
  FAIL("");
  return false;
}

/**********************************************/

Dodle::Dodle()
  : CppBase()
{
}

bool Dodle::setup()
{
  if (! setup_commandLine()) {
    FAIL("");
  } else {
    NYI("");
    return true;
  }
  return false;
}

bool Dodle::setup_commandLine()
{
  m_commandLine = DodleCommandLine::create(this);
  return true;
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






