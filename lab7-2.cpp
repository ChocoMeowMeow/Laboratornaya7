#include<fstream>
#include<vector>
#include<string>
#include <iostream>
using namespace std;

struct Book
{
    string Author;
    string Title;
    int Year;
};

void saveToFile(const string& filename, const vector<Book>& data){
    ofstream out;          
    out.open(filename);      
    if (out.is_open()){
        for (int i=0; i<data.size(); ++i){
            out << data[i].Author << endl;
            out << data[i].Title << endl;
            out << data[i].Year << endl;
        }
    }
    out.close();
}


void loadFromFile(const string& filename, vector<Book> outData){
    string line;
    ifstream in;
    in.open(filename); 
    int i = 0;
    vector <string> vec;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            i += 1;
            vec.push_back(line);
            if (i==3){
                Book k = {vec[0], vec[1], stoi(vec[2])};
                vec.clear();
                outData.push_back(k);
                i = 0;
            }
        }
    }
    in.close();
}

int main()
{
    Book a = {"Пушкин","Лето", 1900};
    Book b = {"Толстой","Зима", 1901};
    vector <Book> books {a, b};
    saveToFile("text.txt", books);
    loadFromFile("text.txt", {});
}
