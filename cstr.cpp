#include "cstr.hpp"

void CString::set_str(int len){
  if (len > 0){
    length  = len;
    stroka = new char[length];
  }
  else{
    cout << "ERROR: zero length assignment.\n";
    length = 0;
    stroka = NULL;
  }
}

void CString::set_element(int pos, char el){
  if (length > pos && pos >= 0){
    stroka[pos] = el;
  }
  else{
    cout << "ERROR: position out of range. Note that the numeration starts from 0. \n";
  }
}

void CString::set_filename(string filename){
  fileout = filename;
}

char CString::get_element(int pos){
  if (length > pos && pos >= 0){
    return stroka[pos];
  }
  else{
    cout << "ERROR: position out of range. Note that the numeration starts from 0. \n";
    return '\0';
  }
}

int CString::get_length(){
  return length;
}

string CString::get_filename(){
  return fileout;
}

void CString::output(const char *FILE_NAME){}

CString::CString(const char* tmp, int len, string filename){
  if (tmp != NULL){
      set_str(len);
      for (int i = 0; i < len; i++){
        stroka[i] = tmp[i];
      }
      fileout = filename;
  }
  else{
    cout << "ERROR: NULL ptr.\n";
  }
}

CString::CString(CString &tmp, string filename){
  if (tmp.stroka != NULL){
      set_str(tmp.length);
      for (int i = 0; i < tmp.length; i++){
        stroka[i] = tmp.stroka[i];
      }
      fileout = filename;
  }
  else{
    cout << "ERROR: NULL CString.\n";
  }
}

CString::CString(){
  length = 0;
  stroka = NULL;
  fileout = "STDOUT";
}

CString::~CString(){
  delete &length;
  delete []stroka;
  delete &fileout;
}

CString& CString::operator= (const CString& a){
  set_str(a.length);
  for (int i = 0; i < a.length; i++)
    stroka[i] = a.stroka[i];
  fileout = a.fileout;
  return *this;
}

CString& CString::operator= (const string& a){
  set_str(a.size());
  for (int i = 0; i < a.size(); i++)
    stroka[i] = a[i];
  fileout = "STDOUT";
  return *this;
}

const CString CString::operator+ (const CString a){
  CString ans;
  ans.set_str(length + a.length);
  for(int i = 0; i < length; i++){
    ans.set_element(i, stroka[i]);
  }
  for(int i = 0; i < a.length; i++){
    ans.set_element(length + i, a.stroka[i]);
  }
  return ans;
}
