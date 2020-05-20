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


bool CommandLine::parseStartingAt(int pos, int argc, const char* argv[])
{
  if (pos < 1) {
    FAIL("can not parse before pos 1");
  } else if (pos >= argc) {
    return true; // parsed all
  }

  const char* argAtPos = argv[pos];
  string currentArg = argAtPos;
  const char argAtPos0 = argAtPos[0];

  if (argAtPos0 != '-') {
    size_t count = m_commandStrings.size();
    for (size_t i = 0; i < count; i++)
      {
	string curString = m_commandStrings[i];
	cout << "AAAAAAAAA " << curString << endl;
	if (curString == currentArg) {
	  cout << "BBBBBBB " << currentArg << endl;
	  applyIfNotNull(m_commandActions[i], curString);
	}
      }
    
  } else {
  }


  NYI("");
  SHOWVARVAL(argAtPos);
  
  
  const char* arg0 = argv[0];
  SHOWVARVAL(arg0);
  const char arg00 = arg0[0];
  SHOWVARVAL(arg00);
  
  
  SHOWVARVAL(pos);
  SHOWVARVAL(argc);
  return false;
}

bool CommandLine::parse(int argc, const char* argv[])
{
  if (m_noCommandAction == NULL) {
    cout << "SSSSSSSSSSSSSSSSSSSS" << endl;
  }
  
  if (argc < 2) {
    applyIfNotNull(m_noCommandAction, " noCommandAction");
  } else if (! parseStartingAt(1, argc, argv)) {
    FAIL("parseStartingAt");
  } else {
    return true;
  }
  
  return false;
}

bool CommandLine::applyIfNotNull(CommandLineAction* action, string calledFrom)
{
  if (action == NULL) {
    FAIL("called From: " << calledFrom);
  } else {
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
