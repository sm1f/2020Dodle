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

  result->addNoCommandAction(new CommandLine_PrintHelpAction("help", "print command info", result));
  result->addCommand("help", "print command info", NULL);
  result->addCommand("init", "initial an empty game", NULL);
  result->addCommand("play", "continue play", NULL);
  result->addCommand("reset", "reset to empty game", NULL);

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
  NFI("");
  return true;
}

int Dodle::setupAndRun(int argc, const char* argv[])
{
  if (! setup()) {
    FAIL("setup");
  } else if (! setup_commandLine()) {
    FAIL("setup_commandLine");
  } else if (m_commandLine->parse(argc, argv)) {
    FAIL("parse");
  } else {
    NFI("");
  }
  return -1;
}






