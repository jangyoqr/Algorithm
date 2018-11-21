/*
����:���տ���
20130940 �����а� 3�г� �����
*/
#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned int uint;

int main(int argc, char argv[]){
 fstream infile;
 int numcases;

 infile.open("input.txt");

 infile >> numcases;

 while (numcases--){
  int data1, data2;
  int num;
  int i,j;
  uint arr1[132] = { 0, }, arr2[132] = { 0, };
  uint kyo[132] = { 0, };
  uint hab[132] = { 0, };
  uint ca[132] = { 0, };
  int kyoc, habc, cac;

  kyoc = habc = cac = 0;

  //ó�� �迭�� ���� �Է¹ޱ�
  infile >> data1;
  for (i = 0; i < data1; i++){
   infile >> num;
   arr1[num]++;
  }
  infile >> data2;
  for (i = 0; i < data2; i++){
   infile >> num;
   arr2[num]++;
  }
  for (i = 0; i < 132; i++){
   if (arr1[i] & arr2[i]){
    kyo[i]++;
    kyoc++;
   }
   if (arr1[i] | arr2[i]){
    hab[i]++;
    habc++;
   }
   if (!arr2[i] & arr1[i]){
    ca[i]++;
    cac++;
   }
  }

  //�������� ������ �� ��Ÿ����
  cout << kyoc << " ";
  for (i = 0; i < 132; i++){
   if (kyo[i] != 0){
    cout << i << " ";
   }
  }
  cout << endl;
  //�������� ������ �� ��Ÿ����
  cout << habc << " ";
  for (i = 0; i < 132; i++){
   if (hab[i] != 0){
    cout << i << " ";
   }
  }
  cout << endl;
  //�������� ������ �� ��Ÿ����
  cout << cac << " ";
  for (i = 0; i < 132; i++){
   if (ca[i] != 0){
    cout << i << " ";
   }
  }
  cout << endl;
 }
 infile.close();
}
