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
  }
  
  return false;
}

bool CommandLine::applyIfNotNull(Action* action)
{
  if (action != NULL) {
    action->apply();
    return true;
  }
  return false;
}

void CommandLine::addNoCommandAction(Action* action)
{
  m_noCommandAction = action;
}


CommandLine_PrintHelpAction::CommandLine_PrintHelpAction(CommandLine* cLine)
  : m_cLine(cLine)
{
}
