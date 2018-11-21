/*
	problem:숫자야구
	20130940 경제학과 3학년 장용훈
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (void){
	ifstream inStream;
	int TestCases, numQNA, l, m, n, o, data, st, ball;
	
	int temp[10000] = {};
	int t = 0;

    inStream.open("input.txt");
    inStream >> TestCases;
    for(int i=0;i<TestCases;++i){
    inStream >> numQNA;
    for(int j=0;j<numQNA;j++){
       inStream >> data >> st >> ball;
       int t=0,s=0,b=0, u=0;
       int num[4]={};
       int num2[4]={};
       int anslist[10000]={};                                                                                                                                                                                                                               
     t=0;

       for(t=0;t<9999;t++){
		   num[0]=t/1000;
		   num[1]=t/100%10;
		   num[2]=t/10%10;
		   num[3]=t%10;
		   num2[0]=data/1000;
		   num2[1]=data/100%10;
		   num2[2]=data/10%10;
		   num2[3]=data%10;
         s=0, b=0;
          for(int d=0;d<4;d++){
             for(int e=0;e<4;e++){
                if(d==e && num[d]== num2[e])
                   s+=1;
             }
          }for (int i = 0; i<4; i++) {
			  for (int j = 0; j<4; j++) {
				  if (i == j)
					  continue;
				  if (num[i] == -1 || num2[j] == -1)
					  continue;
				  if (num[i] == num2[i] || num[j] == num2[j])
					  continue;
				  if (num[i] == num2[j]) {
					  num[i] = num2[j] = -1;
					  b++;
					  break;
				  }
			  }
		  }
          if(s==st && b==ball){
             anslist[t]=t;
             if(j==0){temp[t]=anslist[t];}
             else if(j!=0){if(temp[t]!=0){temp[t]=anslist[t];}}                                                                                                                                                                                     
          }
          else temp[t]=0;
        }
    }
    int Anscount=0;
    int Answer=0;
    for(int x=0;x<9999;x++){
       if(temp[x]!=0){Anscount++;
          Answer=temp[x];
       }                                                                                                                                                                                                                                          
    }                                                                                                                                                                                                                                                        
  if(Anscount ==1){cout << Answer<<endl;}
    if(Anscount ==0){cout << "-2"<< endl;}
    else if(Anscount >1){cout << "-1" <<endl;}
}
inStream.close();
return 0;
}