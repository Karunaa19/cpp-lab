/*  Create a 'STRING' class which char* and length as data member and  
overloads  ‘+’ ,’=’ and ‘ = = ‘  to perform respective operations. Use 
constructor and destructor whenever suitable.*/

#include<iostream>
#include<cstring>
using namespace std;
class String{
    char* str;
    int length;
public:
    String(const char t[]){
        length = strlen(t);
        str = new char[length + 1];
        strcpy(str, t);
    }
    String() : str(nullptr), length(0) {}


    String(const String &str2) {
        length = str2.length;
        str = new char[length + 1];
        strcpy(str, str2.str);
    }


    ~String(){
        delete[] str;
    }
    String operator+(const String &s2){
        String t;
        t.length = length + s2.length;
        t.str = new char[t.length + 1];
        strcpy(t.str, str);
        strcat(t.str, s2.str);
        return t;
    }
    void operator=(const String &t){
        if (this != &t) {
            delete[] str;
            length = t.length;
            str = new char[length + 1];
            strcpy(str, t.str);
        }
    }

  
    bool operator==(const String &o){
        return (strcmp(str, o.str) == 0);
    }

 
    void display() const {
        cout << str << endl;
    }
};

int main(){
    String str1("hello");
    String str2("world");
    String str3 = str1 + str2;
    String str4("helloworld");

    if(str3 == str4){
        cout << "strings are same" << endl;
        str3.display();
    } else {
        cout << "string are not same" << endl;
        str3.display();
        str4.display();
    }

    return 0;
}
