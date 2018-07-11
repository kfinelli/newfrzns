#include <string>
#include <cstdio>
#include <iostream>

#define CHECK(val,fmt) check_status( val, __FUNCTION__, fmt)

enum statusCode (kSuccess, kFail, NSTATUS);

template<typename ... Args>
void check_status( bool status, const std::string& func,
  const std::string& format, Args ... args) {
  //based on SO answer from iFreilicht
  if (status) return;
  std::string fullfmt = func.append(": ");
  fullfmt.append(format);
  size_t size = snprintf(nullptr, 0, fullfmt.c_str(), args ...) + 1;
  unique_ptr<char[]> buf( new char[size] );
  printf(buf.get(), size, fullfmt.c_str(), args ...);
}
