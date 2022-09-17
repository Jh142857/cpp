#include <iostream>
using namespace std;
#include <string>

struct Student
{
    /* data */
    string name;
    int age;
    int score;
};

struct Teacher
{
    int id;
    Student student;
};

void printInfo(Student * stu) {
    cout << stu->age << endl;
}

int main()
{
    struct Student stu1 = {"ÕÅÈı", 20, 100};

    struct Teacher teacher = {1, stu1};
    Teacher *p = &teacher;

    printInfo(&stu1);
    system("pause");
    return 0;
}