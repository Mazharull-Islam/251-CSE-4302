#include<iostream>
using namespace std;

class Person {
    protected :
    string name;
    public :
    Person(string n) : name(n){}
    virtual void display()
    {
        cout<<"Name : "<<name<<endl;
    }
    virtual ~Person() {};
};

class Employee : public Person {
    protected :
    float salary;
    public :
    Employee(string n, int id, float s) : Person(n), emp_id(id), salary(s){}
    void display() override
    {
        cout << "Name : " << name << endl;
        cout << "Employee ID : " << emp_id << endl;
        cout << "Salary : " << salary << endl;
    }
    private :
    int emp_id;
};

class Intern : public Employee {
    private :
    string schoolName;
    public :
    Intern(string n, int id, float s,string sn) : Employee(n,id,s), schoolName(sn){}
    void display() override
    {
        Employee::display();
        cout << "School Name : " << schoolName << endl;
    }
};

class Manager : private Employee {
    private :
    string department;
    public :
    Manager(string n, int id, float sal, string dept) : Employee(n, id, sal), department(dept) {}
    void display() override
    {
        Employee::display();
        cout << "Department : " << department << endl;
        cout << "Salary : " << salary << endl;
    }
};

class Director : private Manager {
    private :
    float bonus;
    public :
    Director(string n, int id, float sal, string dept, float bon) : Manager(n, id, sal, dept), bonus(bon) {}
    void display() override
    {
        Manager::display();
        cout << "Bonus : " << bonus << endl;
    }
};

int main() {

     Person* p1 = new Intern("Alice", 101, 5000.0f, "Harvard");
    Manager* m1 = new Manager("Bob", 102, 12000.0f, "HR");
    Director* d1 = new Director("Charlie", 103, 25000.0f, "Finance", 5000.0f);

    cout << "Intern details:" << endl;
    p1->display();
    cout << endl;

    cout << "Manager details:" << endl;
    m1->display();
    cout << endl;

    cout << "Director details:" << endl;
    d1->display();
    cout << endl;

    
    delete p1;
    delete m1;
    delete d1;
    
    return 0;
}
