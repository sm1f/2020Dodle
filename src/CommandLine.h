// CopyRight Stephen Morrisson 2020
// All rights reserved.


#ifndef  __COMMANDLINE_H__
#define __COMMANDLINE_H__

#include <map>

#include "CppBase.h"
#include "Action.h"

class CommandLineAction;
typedef CommandLineAction* CommandLineActionP;

class CommandLine : public CppBase
{
 public:
  CommandLine();
  virtual ~CommandLine() {}
  virtual string className() { return "CommandLine"; }
  virtual void help();
  virtual bool parse(int argc, const char* argv[]);

  virtual bool applyIfNotNull(CommandLineAction* action, string calledFrom);
  virtual void addNoCommandAction(CommandLineAction* action);
  virtual void addCommand(string commandString, string commandDescription, CommandLineAction* act);

 private:
  typedef CppBase __super;

  CommandLineAction* m_noCommandAction;
  vector<string> m_commandStrings;
  vector<string> m_commandDescriptions;
  vector<CommandLineActionP> m_commandActions;

  bool parseStartingAt(int pos, int argc, const char* argv[]);
};

class CommandLineAction : public Action
{
 public:
  CommandLineAction(string commandString, string commandDescription);
  virtual ~CommandLineAction() {}
 private:
  typedef Action __super;
  string m_commandString;
  string m_commandDesciption;
};

class CommandLineAction_setBool : public CommandLineAction
{
  CommandLineAction_setBool(string commandString, string commandDescription, bool& var);
  virtual ~CommandLineAction_setBool() {}
 private:
  typedef CommandLineAction __super;
  bool& m_var;
};


class CommandLine_PrintHelpAction : public CommandLineAction {
 public:
  CommandLine_PrintHelpAction(string commandString, string commandDescription, CommandLine* cLine);
  virtual ~CommandLine_PrintHelpAction() {}
  virtual string className() { return "CommandLine_PrintHelpAction"; }
  virtual bool apply() { m_cLine->help(); return true; }
 private:
  typedef CommandLineAction __super;
  CommandLine* m_cLine;
};


#endif //  __COMMANDLINE_H__

