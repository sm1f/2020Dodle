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

  size_t count = m_commandStrings.size();
  for (size_t i = 0; i < count; i++) {
    cout << "  " << m_commandStrings[i] << ": " << m_commandDescriptions[i] << endl;
  }
}

bool CommandLine::parse(int argc, const char* argv[])
{
  if (m_noCommandAction == NULL) {
    cout << "SSSSSSSSSSSSSSSSSSSS" << endl;
  }
  
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
  m_commandStrings.push_back(commandString);
  m_commandDescriptions.push_back(commandDescription);
  m_commandActions.push_back(act);
}

CommandLineAction::CommandLineAction(string commandString, string commandDescription)
  : __super(), m_commandString(commandString), m_commandDesciption(commandDescription)
{
}

/*************************************/

CommandLineAction_setBool::CommandLineAction_setBool(string commandString, string commandDescription, bool& var)
  : __super(commandString, commandDescription), m_var(var)
{}

/*************************************/

CommandLine_PrintHelpAction::CommandLine_PrintHelpAction(string commandString, string commandDescription, CommandLine* cLine)
  : __super(commandString, commandDescription), m_cLine(cLine)
{
}
