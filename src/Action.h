// CopyRight Stephen Morrisson 2019, 2020
// All rights reserved.

#ifndef  __Action_H__
#define __Action_H__

#include "common.h"
#include "CppBase.h"

class Action : public CppBase
{
 public:
  Action() {}
  virtual ~Action() {}
  virtual string className() { return "Action"; }
  
  virtual bool apply();
 private:
  typedef CppBase __super;
};

#endif //  __Action_H__

