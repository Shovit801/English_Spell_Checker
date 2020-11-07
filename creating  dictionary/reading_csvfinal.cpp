#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    ifstream input_from_file("dict_final.csv");
    string line;
     vector<vector<string> >  words(676);
     string word;




       for(int i=0;i<676;i++){
         getline(input_from_file, line,'\n');
            {
                stringstream ss(line);
                {
                    while (getline(ss, word, ','))
                        words[i].push_back(word);
                }
            }
       }
       /* for(int i=0;i<9;i++)
            {
                for(int j=0;j<words[i].size();j++)
                {
                cout<<words[i][j]<<" ";

                }
        cout<<endl;
        }*/
         cout<<words[544][5];
          return 0;

    }

