#include<iostream>
#include<thread> 

using namespace std;


void say_hi(string s) {
    cout << "Hello: " << s << endl;
    return ;
}


void test_thread_1() {
    // simple function
    string str = "Paladnix";

    thread thr(say_hi, str);

    cout << "Others" << endl;

    thr.detach();
    // thr.join();
}

class Person {
    string name;
    int age;
public:

    Person() {}
    Person(string name, int age):name(name), age(age){}

    void say_hi(string hi) {
        cout << hi << ' ' << name << endl;
        cout << __LINE__ << ": " << this_thread::get_id() << endl;
    }
}; 


void test_thread_2() {
    Person a("Paladnix", 18);
    thread thr(&Person::say_hi, a, "Hi");

    thr.join();
    cout << __LINE__ << ": " << this_thread::get_id() << endl;


}




int main() {
    test_thread_2();
    return 0;
}
