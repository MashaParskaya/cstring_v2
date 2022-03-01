#include "cstrHori.hpp"

void CStringH::output(const char *FILE_NAME){
  if (FILE_NAME != "STDOUT"){
    ofstream fout;
    fout.open(FILE_NAME, ios::app);
    if (!fout.is_open()){
      cout << "Error! Cannot open file!\n";
    }
    else{
      for (int i = 0; i < this->get_length(); i++){
        fout << this->get_element(i);
      }
      fout << endl;
    }
    fout.close();
  }
  else{
    for (int i = 0; i < this->get_length(); i++){
      cout << this->get_element(i);
    }
    cout << endl;
  }
}

CStringH::CStringH(const char* tmp, int len, string filename) : CString(tmp, len, filename){}

CStringH::CStringH(CString &tmp, string filename) : CString(tmp, filename){}

CStringH::CStringH() : CString(){}

CStringH::~CStringH(){}
