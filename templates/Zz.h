// CopyRight Stephen Morrisson 2019
// All rights reserved.

// CopyRight Stephen Morrisson 2020
// All rights reserved.

// removed first lines
// replace Zz with class name
// replace Yy with parent class name



#ifndef  __ZZ_H__
#define __ZZ_H__

#include "Yy.h"

class Zz : public Yy
{
 public:
  Zz();
  virtual ~Zz() {}
  virtual string className();
 private:
  typedef Yy __super;
};

#endif //  __ZZ_H__

