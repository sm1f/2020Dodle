// CopyRight Stephen Morrisson 2020
// All rights reserved.


#ifndef  __COMMANDLINE_H__
#define __COMMANDLINE_H__

#include "CppBase.h"
#include "Action.h"

class CommandLine : public CppBase
{
 public:
  CommandLine();
  virtual ~CommandLine() {}
  virtual string className() { return "CommandLine"; }
  virtual void help();
  virtual bool parse(int argc, const char* argv[]);

  virtual bool applyIfNotNull(Action* action);
  virtual void addNoCommandAction(Action* action);

 private:
  typedef CppBase __super;

  Action* m_noCommandAction;
};

class CommandLine_PrintHelpAction : public Action {
 public:
  CommandLine_PrintHelpAction(CommandLine* cLine);
  virtual ~CommandLine_PrintHelpAction() {}
  virtual string className() { return "CommandLine_PrintHelpAction"; }
  virtual bool apply() { m_cLine->help(); return true; }
 private:
  typedef CommandLine __super;
  CommandLine* m_cLine;
};


#endif //  __COMMANDLINE_H__

