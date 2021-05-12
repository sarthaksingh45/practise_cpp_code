#include <iostream>
using namespace std;

class Student{
    public:
    string name;
    int age;
    bool gender;

    Student(string s, int n, bool g){
        name = s;
        age = n;
        gender = g;
    }

    Student(string s){
        name=s;
        age =21;
        gender =0;
    }

    bool operator ==(Student &abc){
        if((name == abc.name) && (age == abc.age) && (gender == abc.gender)){
            return true;
        }
        return false;
    }

    ~Student(){
        cout << "Destructor Called" <<endl;
    }
};

int main(){
    Student a("Sarthak",21,0);

    Student b("Sarthak");
    

    cout<< a.name << endl;
    cout << a.age <<endl;
    cout << a.gender << endl;

    cout<< b.name << endl;
    cout << b.age <<endl;
    cout << b.gender << endl;

    if(a==b){
        cout << "Same" <<endl;
    }
    else{
        cout << "not same" <<endl;
    }



    return 0;
}