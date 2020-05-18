#include "common.h"


string string_random(std::string::size_type length)
{
  static auto& chrs = "0123456789"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  thread_local static std::mt19937 rg{std::random_device{}()};
  thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

  std::string s;

  s.reserve(length);

  while(length--)
    s += chrs[pick(rg)];

  return s;
}

bool string_startsWith(const string& hayStack, const string& needle)
{
  if (&hayStack == &needle) { return true; }
  size_t hayStackLength = hayStack.length();
  size_t needleLength = needle.length();
  if (hayStackLength < needleLength) { return false; }
  for (size_t i = 0; i < needleLength; i++) {
    if (needle[i] != hayStack[i]) {
      return false;
    }
  }
  return true;
}
