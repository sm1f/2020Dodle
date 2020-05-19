// CopyRight Stephen Morrisson 2020
// All rights reserved.


#ifndef  __DODLE_H__
#define __DODLE_H__

#include "CppBase.h"

class Dodle : public CppBase
{
 public:
  Dodle();
  virtual ~Dodle() {}
  virtual string className();

  virtual bool setup();

  virtual int setupAndRun(int argc, const char* argv[]);

 private:
  typedef CppBase __super;
};

#endif //  __DODLE_H__

