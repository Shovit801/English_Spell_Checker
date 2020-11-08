#include "bits/stdc++.h"
#include <fstream>

using namespace std;

int main()
{
    std::ofstream myFile("dict_new.csv");

    std::vector<vector<string> > v;
    string str="abcdefghijklmnopqrstuvwxyz";                        //creating the 1st column of our lexicon consisting of all the combination of bigrams possible      
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
        cout<<"enter all the words"<<endl;                      //to run the prgramme copy the entire list of words from the text file and paste in the terminal
        for(int i=0;i<370103;i++){                              //running the loop for the entire list of words and storing it in a vector named "words"
            string scpy;
            cin>>scpy;
            words.push_back(scpy);
        }
        int n=words.size();     
        for(int i=0;i<n;i++){                                   //creating a 2d vector of our Lexicon by pushing the words along their respective bigrams 
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
    for(int i=0;i<v.size();i++){                            //sorting the list of words in the lexicon for easy traversal 
        sort(v[i].begin()+1,v[i].end());
    }
    for(int i=0;i<v.size();i++){                            //storing the entire vector in CSV format 
        for(int j=0;j<v[i].size();j++){
              myFile << v[i][j]<<",";
        }
          myFile <<endl;
        cout<<endl;
    }
    myFile.close();

    return 0;
}

