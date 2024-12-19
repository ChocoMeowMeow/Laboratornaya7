#include<fstream>
#include<vector>
#include<string>
#include <iostream>
using namespace std;

void saveToFile(const string& filename, const vector<string>& data){
    ofstream out;          
    out.open(filename);      
    if (out.is_open()){
        for (int i=0; i<data.size(); ++i){
            out << data[i] << endl;
        }
    }
    out.close();
}


void loadFromFile(const string& filename, vector<string> outData){
    string line;
    ifstream in;
    in.open(filename); 
    if (in.is_open())
    {
        while (getline(in, line))
        {
            outData.push_back(line);
        }
    }
    in.close();
}

int main()
{
    saveToFile("text.txt", {"Hello ", "world"});
    loadFromFile("text.txt", {});
}
