#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "cstrHori.hpp"
#include "cstrVert.hpp"
#include "cstr.hpp"
#include "autotest.hpp"

using namespace std;
using namespace cstr_hori_vert;

int main(){
  Autotest();
  string datafile;
  cin >> datafile;
  ifstream fin;
  fin.open(datafile.c_str(), ios::in);
  if (!fin.is_open()){
    cout << "Error! Cannot open file!\n";
    return 0;
  }
  vector<CString*> vectorVector;
  string tmp;
  while (getline(fin, tmp)){
    tmp += " ";
    vector<string> parsed = {};
    string tmp_parse = "";
    for (int i = 0; i < tmp.length(); i++){
      if (tmp.at(i) == ' '){
        parsed.push_back(tmp_parse);
        tmp_parse = "";
      }
      else{
        tmp_parse += tmp[i];
      }
    }
    if (parsed[0] == "0"){
      vectorVector.push_back(new CStringH(parsed[2].c_str(), parsed[2].length(), parsed[1]));
    }
    else if (parsed[0] == "1"){
      vectorVector.push_back(new CStringV(parsed[2].c_str(), parsed[2].length(), parsed[1]));
    }
  }
  fin.close();

  for (int i = 0; i < vectorVector.size(); i++){
        vectorVector[i]->output(vectorVector[i]->get_filename().c_str());
  }

  return 1;
}
