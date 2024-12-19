#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    string Name;
    int Year;
    map<string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& filename, const Groups& data){
    ofstream out;          
    out.open(filename);      
    if (out.is_open()){
        for (const auto& [groupp, students] : data){
            out << groupp << endl;
            for (int i=0; i<students.size(); ++i){
                out << students[i].Name << endl;
                out << students[i].Year << endl;
                for (const auto& [subject, scoree] : students[i].RecordBook){
                    out << subject << endl;
                    out << scoree << endl;
                }
            }
        }
    }
    out.close();
}


void loadFromFile(const string& filename, Groups& outGroups) {
    ifstream file(filename);
    string rt, gr;
    while (getline(file, rt)) {
        if (isupper(rt[0])){
            gr = rt; 
            outGroups[gr];
        }
        else {
            istringstream ft(rt);
            Student stu;
            string sub;
            ft >> stu.Name >> stu.Year;
            while (ft >> sub){
                int sc;
                ft >> sc;
            }
            outGroups[gr].push_back(stu);
        }
    }
    file.close();
}

int main()
{
    map<string, Score> a {{"Математика", Good}, {"Информатика", Excellent}};
    map<string, Score> b {{"Математика", Unsatisfactorily}, {"Информатика", Satisfactorily}};
    Student ivan = {"Иван", 18, a};
    Student anna = {"Анна", 17, b};
    Groups gr {{"первая", {anna}}, {"вторая", {ivan}}};
    saveToFile("text.txt", gr);
    loadFromFile("text.txt", gr);
}