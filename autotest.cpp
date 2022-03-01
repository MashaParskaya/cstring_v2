#include "autotest.hpp"

int test1(){
  int n = 10;
  char b[n];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  CString s(b, n);
  if (s.get_length() != n){
    cout << "TEST 1 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s.get_element(i) != b[i]){
      cout << "TEST 1 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 1 CORRECT\n";
  return 0;
}

int test2(){
  int n = 10;
  char b[n];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  CString s(b, n);
  if (s.get_length() != n){
    cout << "TEST 2 ERROR\n";
    return 0;
  }
  CString s1(s);
  if (s1.get_length() != n){
    cout << "TEST 2 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s1.get_element(i) != b[i]){
      cout << "TEST 2 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 2 CORRECT\n";
  return 0;
}

int test3(){
  int n = 10;
  char b[n];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  CString s(b, n);
  if (s.get_length() != n){
    cout << "TEST 3 ERROR\n";
    return 0;
  }
  CString s1;
  s1 = s;
  if (s1.get_length() != n){
    cout << "TEST 3 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s1.get_element(i) != b[i]){
      cout << "TEST 3 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 3 CORRECT\n";
  return 0;
}

int test4(){
  int n = 10;
  int m = 5;
  char b[n];
  char c[m];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  for (int i = 0; i < m; i++){
    c[i] = '1';
  }
  CString s(b, n);
  CString s1(c, m);
  if (s.get_length() != n){
    cout << "TEST 4 ERROR\n";
    return 0;
  }
  if (s1.get_length() != m){
    cout << "TEST 4 ERROR\n";
    return 0;
  }
  CString s2(s);
  s2 = s + s1;
  if (s2.get_length() != n + m){
    cout << "TEST 4 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s2.get_element(i) != b[i]){
      cout << "TEST 4 ERROR\n";
      return 0;
    }
  }
  for (int i = 0; i < m; i++){
    if (s2.get_element(n + i) != c[i]){
      cout << "TEST 4 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 4 CORRECT\n";
  return 0;
}

int test5(){
  string b = "aaaaaaaaaa";
  CString s;
  s = b;
  if (s.get_length() != b.size()){
    cout << "TEST 5 ERROR\n";
    return 0;
  }
  for (int i = 0; i < s.get_length(); i++){
    if (s.get_element(i) != b[i]){
      cout << "TEST 5 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 5 CORRECT\n";
  return 0;
}

int test6(){
  string b = "aaaaaaaaaa";
  CString s;
  s = b;
  CStringH sH(s);
  sH.output("CString_test6.test");
  ifstream fin;
  fin.open("CString_test6.test", ios::in);
  string tmp;
  getline(fin, tmp);
  fin.close();
  remove("CString_test6.test");
  if (tmp == b){
    cout << "TEST 6 CORRECT\n";
  }
  else{
    cout << "TEST 6 ERROR\n";
  }
  return 0;
}

int test7(){
  string b = "aaaaaaaaaa";
  CString s;
  s = b;
  CStringV sV(s);
  sV.output("CString_test7.test");
  ifstream fin;
  fin.open("CString_test7.test", ios::in);
  string tmp;
  string it;
  while (getline(fin, it)){
    tmp += it;
  }
  fin.close();
  remove("CString_test7.test");
  if (tmp == b){
    cout << "TEST 7 CORRECT\n";
  }
  else{
    cout << "TEST 7 ERROR\n";
  }
  return 0;
}

void Autotest(){
  cout << "Testing...\n";
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
}
