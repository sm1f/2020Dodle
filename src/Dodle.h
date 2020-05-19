// CopyRight Stephen Morrisson 2020
// All rights reserved.


#ifndef  __DODLE_H__
#define __DODLE_H__

#include "CppBase.h"
#include "CommandLine.h"

class Dodle;

class DodleCommandLine : public CommandLine {
 public:
  static DodleCommandLine* create(Dodle* that);
  
  virtual ~DodleCommandLine() {}
  virtual string className() { return "DodleCommandLine"; }

  virtual bool setup(Dodle* that);

 private:
  typedef CommandLine __super;

  DodleCommandLine();
};

class Dodle : public CppBase
{
 public:
  Dodle();
  virtual ~Dodle() {}
  virtual string className() { return "Dodle"; }

  virtual bool setup();
  virtual bool setup_commandLine();

  virtual int setupAndRun(int argc, const char* argv[]);

 protected:
  DodleCommandLine* m_commandLine;
  
 private:
  typedef CppBase __super;
};

#endif //  __DODLE_H__

