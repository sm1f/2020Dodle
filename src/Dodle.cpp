// CopyRight Stephen Morrisson 2020
// All rights reserved.


#include "Dodle.h"

Dodle::Dodle()
  : CppBase()
{
}

string Dodle::className()
{
  return "Dodle";
}

bool Dodle::setup()
{
  NYI("");
  return false;
}

int Dodle::setupAndRun(int argc, const char* argv[])
{
  SHOWVARVAL(argc);
  if (! setup()) {
    FAIL("");
  } else {
    NFI("");
  }
  return -1;
}




