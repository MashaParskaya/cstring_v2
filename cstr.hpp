#ifndef CSTR_HPP_INCLUDED
#define CSTR_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class CString {
private:
  int length;
  char* stroka;
  string fileout;
public:
  void set_str(int len);

  void set_element(int pos, char el);

  void set_filename(string filename);

  char get_element(int pos);

  int get_length();

  string get_filename();

  virtual void output(const char *FILE_NAME=NULL);

  CString(const char* tmp, int len, string filename="STDOUT");

  CString(CString &tmp, string filename="STDOUT");

  CString();

  ~CString();

  CString& operator= (const CString& a);

  CString& operator= (const string& a);

  const CString operator+ (const CString a);

};

#endif
