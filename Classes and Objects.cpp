// Classes and Objects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::string;

/*
A constructor is a special type of method that is invoked each time an object of a class is created

In case a constructor isn't created by the user then the compiler will automatically give a constructor which is called default constructor

Three rules for constructors:
1. A constructor is just a method but unlike other methods a constructor doesn't have a return type
2. A constructor has the same name of the class it belongs to
3. Constructor must be public (not always) 
*/


/*
Encapsulation is the idea of bundling together data and methods that operate from that data

Encapsulation is used to prevent something outside of the class from effecting the class and to be able to access the data in the class

You access the class's data thorugh it's methods (normally in terms of getters and setters)
*/


/*
Abstraction is hiding complex things behind a procedure that makes them look more simple

For example to take a picture on a phone it's simple for the user but it is actually very complex
*/


/*
Inheritance is when a class (child class) inherits from another class (parent class) including it's attributes/methods
*/


/*
Public = able to be accessed by everyone
Private = only accessible through that class
Protected = accessible only through that class and it's derived classes
*/


/*
Polymorphism 

The most common use of polymorphism is when a parent class reference is used to refer to a child class object
*/


// This is an abstract/contract class 
class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
//if it isn't in an access modifier then it is automatically private
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    void setAge(int age) {
        if (age >= 18) { Age = age; }
    }
    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion() {
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << ", sorry no promotion for you!" << std::endl;
    }

    //virtual keyword is used to check whether the derived classes have their own Work function and if they do to instead use the derived classes function
    virtual void Work() {
        std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
    }
};

//Inheritance is private by default so adding public fixes this issue and makes everything from class Employee accessible from the derived class Developer
class Developer:public Employee {
    string FavProgrammingLanguage;
public:
    Developer(string name, string company, int age, string favProgrammingLanguage) 
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void introduction() {
        IntroduceYourself();
    }
    void Work() {
        std::cout << Name << " is writing "<<FavProgrammingLanguage << " code" << std::endl;
    }
};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
    }
    Teacher(string name, string company, int age, string subject) 
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work() {
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
};

int main()
{
    Employee employee1 = Employee("Liam", "Unemployed", 24);
    employee1.IntroduceYourself();

    Employee employee2 = Employee("John", "Amazon", 35);
    employee2.IntroduceYourself();

    employee1.setAge(15);
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl;

    employee1.AskForPromotion();
    employee2.AskForPromotion();
    Developer d = Developer("Bob", "YT", 23, "C++");
    d.FixBug();
    d.FixBug();
    d.FixBug();
    d.introduction();
    d.AskForPromotion();

    Teacher t = Teacher("Jack", "Cool School", 35, "History");
    t.PrepareLesson();
    t.AskForPromotion();

    d.Work();
    t.Work();

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
