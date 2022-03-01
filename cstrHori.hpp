#ifndef CSTR_HORI_HPP_INCLUDED
#define CSTR_HORI_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "cstr.hpp"

using namespace std;

class CStringH : public CString {
public:

  virtual void output(const char *FILE_NAME=NULL);

  CStringH(const char* tmp, int len, string filename="STDOUT");

  CStringH(CString &tmp, string filename="STDOUT");

  CStringH();

  ~CStringH();
};

#endif
