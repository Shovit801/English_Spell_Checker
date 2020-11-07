#include <fstream>
#include"bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include"unordered_map"
using namespace std;
void lower(string& str)
{
    int length = str.length();
    for (int i = 0; i < length; i++) {
        int c = str[i];
        if (isupper(c))
            str[i] = tolower(c);
    }
}
int editDist(string str1, string str2,int m,int n)
{


    if (m == 0)
        return n;


    if (n == 0)
        return m;


    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);


    return 1 + min(editDist(str1, str2, m, n - 1), // Insert
                   min(editDist(str1, str2, m - 1, n), // Remove
                   editDist(str1, str2, m - 1, n - 1)) // Replace
                   );
}
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

         cout<<"enter your query"<<endl;
         string query;
         cin>>query;
         lower(query);
    string str=query;
    int query_size=query.size()-3;
        vector<string> v;
        for(int i=0;i<query.size()-1;i++){
                string s="";
                s.push_back(str[i]);
                s.push_back(str[i+1]);
                v.push_back(s); //here we are pushing the bigrams from the query entered into the v vector
        }
        int y;

        vector<string> final_list;
        unordered_map<string,int> m;
        int count=0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<676;j++)
               {
                   if(words[j][0]==v[i]) //and here we are comparing it with the first column of the csv file (the 2d vector)
                   {
                        for(int itr=1;itr<words[j].size();itr++)
                        {
                            final_list.push_back(words[j][itr]); //needs to be edited as shown in the youtube video
                            m[words[j][itr]]++;
                        }
                        break;
                   }

               }
        }
        //cout<<m.size()<<endl;
        vector<string> final_final_list;
        for(int i=0;i<final_list.size();i++){
            if(m[final_list[i]]>=query_size && (final_list[i].size()<=query.size()+1 && final_list[i].size()>=query.size()-1)){
                m[final_list[i]]=0;
                final_final_list.push_back(final_list[i]);
            }
        }

        vector<string> suggestions;
        int count1=0;
        int k;
        for(int i=0;i<final_final_list.size();i++){
            k=editDist(query,final_final_list[i],query.size(),final_final_list[i].size());
            if(k==1){
                string q=final_final_list[i];
                suggestions.push_back(q);
            }
            if(k==0){
                cout<<"The word is correct"<<endl;
                count++;
                break;
            }
        }
        if(count==0){
        for(int i=0;i<suggestions.size();i++)
            cout<<suggestions[i]<<endl;
        }
        if(k!=0 && suggestions.empty())
            cout<<"No matching words found"<<endl;

}
