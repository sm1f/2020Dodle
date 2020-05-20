// CopyRight Stephen Morrisson 2020
// All rights reserved.


#include "CommandLine.h"

CommandLine::CommandLine()
  : CppBase(),
    m_noCommandAction(NULL)
{
}

void CommandLine::help()
{
  NYI("");
  cout << "Help:" << endl;
  cout << "  help: print command info" << endl;
  cout << "  init: initial an empty game" << endl;
  cout << "  play: continue play" << endl;
  cout << "  reset: reset to empty game." << endl;
}

bool CommandLine::parse(int argc, const char* argv[])
{
  if (argc < 2) {
    applyIfNotNull(m_noCommandAction);
  } else {
    SHOWVARVAL(argc);
    NYI("");
  }
  
  return false;
}

bool CommandLine::applyIfNotNull(CommandLineAction* action)
{
  if (action != NULL) {
    action->apply();
    return true;
  }
  return false;
}

void CommandLine::addNoCommandAction(CommandLineAction* action)
{
  m_noCommandAction = action;
}

void CommandLine::addCommand(string commandString, string commandDescription, CommandLineAction* act)
{
  NYI("");
}

CommandLineAction::CommandLineAction(string commandString, string commandDescription)
  : __super(), m_commandString(commandString), m_commandDesciption(commandDescription)
{
}

CommandLine_PrintHelpAction::CommandLine_PrintHelpAction(string commandString, string commandDescription, CommandLine* cLine)
  : __super(commandString, commandDescription), m_cLine(cLine)
{
}
