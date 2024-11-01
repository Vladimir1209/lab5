#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

struct Student
{
    std::string Name;
    std::string GroupId;
    std::vector<float> Ratings[3];
    std::vector<std::string> Subjects;
};


struct Group
{
    std::string Id;
    std::vector<Student> Students;
};


void SortByName(vector<Student> &a)
{
    for (int i = 0; i < a.size() - 1; ++i)
    {
        for (int g = 0; g < a.size() - i - 1; ++g)
        {
            if (a[g].Name[0] > a[g + 1].Name[0])
            {
                swap(a[g], a[g + 1]);
            }
        }
    }
};

float summ(vector<float> a)
{
    float s = 0.0;
    for (int i = 0; i < a.size(); ++i)
    {
        s = s + a[i];
    }
    return s;
};
void SortByRating(vector<Student> &a)
{
    
    float s1, s2 = 0;
    
    for (int i = 0; i < a.size() - 1; ++i)
    {
        for (int g = 0; g < a.size() - i - 1; ++g)
        {

            for (int s = 0; s < a[g].Subjects.size(); ++s)
            {
                s1 = s1 + summ(a[g].Ratings[s]);
            }
            for (int ss = 0; ss < a[g + 1].Subjects.size(); ++ss)
            {
                s2 = s2 + summ(a[g + 1].Ratings[ss]);
            }
            if ((s1 / a[g].Subjects.size()) < (s2 / a[g + 1].Subjects.size()))
            {
                swap(a[g], a[g + 1]);
                s1 = 0;
                s2 = 0;
            }
            else
            {
                s1 = 0;
                s2 = 0;
            }
        }
    }
};

size_t CountTwoness(const std::vector<Student>& a){
    int f =0;
    
    for (int i = 0; i < a.size() - 1; ++i)
    {
        for (int g = 0; g < a[i].Subjects.size(); ++g)
        {
             for (int s = 0; s < a[i].Ratings[g].size(); ++s){
                 if(a[i].Ratings[g][s] == 2){
                     f+=1;
                     break;
                 }
                 
             }
        
        }
    }
    return f;
    
    
};

size_t CountExcellent(const std::vector<Student>& a){
    int f =0;
    bool t = false;
    for (int i = 0; i < a.size() - 1; ++i)
    {
        for (int g = 0; g < a[i].Subjects.size(); ++g)
        {
             for (int s = 0; s < a[i].Ratings[g].size(); ++s){
                 if(a[i].Ratings[g][s] == 5){
                     t=true;
                 }else{
                     t=false;
                 }
                 
             }
        
        }
        if(t==true){
            f++;
        }
    }
    return f;
};

vector<Student> VectorMathExcellent(const std::vector<Student>& a){
    vector<Student> spisok;
    int p = 0;
    for(int i = 0; i < a[1].Subjects.size(); ++i){
        if (a[1].Subjects[i] == "Math"){p=i;break;}
    }
    for (int i = 0; i < a.size(); ++i)
    {
       if((summ(a[i].Ratings[p])/a[i].Ratings[p].size())==5){
           spisok.push_back(a[i]);
       }
    }
    return spisok;
    
    
};

vector<std::string> GroupsId(const std::vector<Student>& a){
    vector<string> spisok;
    set<string> sp;
    for(int i = 0; i < a.size(); ++i){
        sp.insert(a[i].GroupId);
    }
    set<string> :: iterator g = sp.begin();
    for(int i = 0; i < sp.size(); ++i){
        spisok.push_back(*g++);
    }
    return spisok;
    
};

vector<Group> Groups(const std::vector<Student>& a){
   
    
};


Student Ivan = {"Ivan", "1", {{4, 2, 5}, {5, 4, 5}, {3, 4, 3}}, {"Math", "English", "History"}};
Student Borya = {"Borya", "2", {{4, 3, 5}, {5, 4, 2}, {2, 4, 3}}, {"Math", "English", "History"}};
Student Evgeniy = {"Evgeniy", "1", {{5,5,5}, {5, 5, 5}, {5,5,5}}, {"Math", "English", "History"}};
Student Alexy = {"Alexy", "2", {{5, 5, 5}, {5,5,5}, {5,5,5}}, {"Math", "English", "History"}};
Student Vova = {"Vova", "1", {{4, 2, 4}, {3, 4, 2}, {3, 4, 2}}, {"Math", "English", "History"}};
int main()
{

    vector<Student> students = {Ivan, Borya, Evgeniy, Alexy, Vova};
    SortByRating(students);

    for (int i = 0; i < Groups(students).size(); ++i)
    {
        cout << Groups(students)[i].Id << endl;
    }
    
}
