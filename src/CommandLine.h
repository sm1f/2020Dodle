// CopyRight Stephen Morrisson 2020
// All rights reserved.


#ifndef  __COMMANDLINE_H__
#define __COMMANDLINE_H__

#include "CppBase.h"

class CommandLine : public CppBase
{
 public:
  CommandLine();
  virtual ~CommandLine() {}
  virtual string className();
  virtual void help();
  virtual bool parse(int argc, const char* argv[]);

 private:
  typedef CppBase __super;
};

#endif //  __COMMANDLINE_H__

