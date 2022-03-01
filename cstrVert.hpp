#ifndef CSTR_VERT_HPP_INCLUDED
#define CSTR_VERT_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "cstr.hpp"

using namespace std;

class CStringV : public CString {
public:

  virtual void output(const char *FILE_NAME=NULL);

  CStringV(const char* tmp, int len, string filename="STDOUT");

  CStringV(CString &tmp, string filename="STDOUT");

  CStringV();

  ~CStringV();
};

#endif
