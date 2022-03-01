#include "cstrVert.hpp"

void CStringV::output(const char *FILE_NAME){
  if (FILE_NAME != "STDOUT"){
    ofstream fout;
    fout.open(FILE_NAME, ios::app);
    if (!fout.is_open()){
      cout << "Error! Cannot open file!\n";
    }
    else{
      for (int i = 0; i < this->get_length(); i++){
        fout << this->get_element(i) << endl;
      }
    }
    fout.close();
  }
  else{
    for (int i = 0; i < this->get_length(); i++){
      cout << this->get_element(i) << endl;
    }
  }
}

CStringV::CStringV(const char* tmp, int len, string filename) : CString(tmp, len, filename){}

CStringV::CStringV(CString &tmp, string filename) : CString(tmp, filename){}

CStringV::CStringV() : CString(){}

CStringV::~CStringV(){}
