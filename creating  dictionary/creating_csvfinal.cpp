#include "bits/stdc++.h"
#include <fstream>

using namespace std;

int main()
{
    std::ofstream myFile("dict6.csv");

    std::vector<vector<string> > v;
    string str="abcdefghijklmnopqrstuvwxyz";
        vector<string> temp(1);
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                string s="";
                s.push_back(str[i]);
                s.push_back(str[j]);
                temp[0]=s;
                v.push_back(temp);
            }
        }
        vector<string> words;
        for(int i=0;i<370103;i++){
            string scpy;
            cin>>scpy;
            words.push_back(scpy);
        }
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int k=0;k<words[i].size()-1;k++){
                string s="";
                s.push_back(words[i][k]);
                s.push_back(words[i][k+1]);
                for(int j=0;j<v.size();j++){
                    if(v[j][0]==s){
                        v[j].push_back(words[i]);
                    }
                }
            }
        }
    for(int i=0;i<v.size();i++){
        sort(v[i].begin()+1,v[i].end());
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
           // cout<<v[i][j]<<" ";
              myFile << v[i][j]<<",";
        }
          myFile <<endl;
        cout<<endl;
    }
    myFile.close();

    return 0;
}

