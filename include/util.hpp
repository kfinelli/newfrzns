#include <string>
#include <cstdio>
#include <iostream>
#include <memory>

#define CHECK(val,...) check_status( val, __FUNCTION__, ##__VA_ARGS__)

enum statusCode  {kSuccess, kFail, NSTATUS};

template<typename ... Args>
statusCode check_status( bool status, const std::string& func,
  const std::string& format, Args ... args) {
  //based on SO answer from iFreilicht
  if (status) return kSuccess;
  const std::string fullfmt = func + ": " + format;
  size_t size = snprintf(nullptr, 0, fullfmt.c_str(), args ...) + 1;
  std::unique_ptr<char[]> buf( new char[size] );
  printf(buf.get(), size, fullfmt.c_str(), args ...);
  return kFail;
}
