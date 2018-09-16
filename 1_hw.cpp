#include <iostream>

class Person;

class Person {
private:
    std::string name, surename;
    std::string Account_number;
    long size;
    long *mas;

protected:
    std::string childrens;

public:
    Person(std::string name_user, std::string surename_user, std::string Account, long size_mas) :
        name(name_user),
        surename(surename_user),
        Account_number(Account),
        size(size_mas)  {
        mas = new long[size];
    }

    //when name and surename : name === sure_name
    Person(std::string name_user, std::string Account, long size_mas) {
        this->name = name_user;
        this->surename = name_user;
        this->Account_number = Account;
        this->size = size_mas;
        this->mas = new long[size];
    }

    ~Person() {
        delete [] mas;
    }

    std::string get_name() {
        return name;
    }

    std::string get_surename() {
        return surename;
    }

    std::string get_Account_number() {
        return Account_number;
    }

    static int sum(int a, int b) {
        return a + b;
    }

    static float sum(float a, float b) {
        return a + b;
    }

    //Can be rewrited with templates
    static void some_func(int arg, ...) {
        int *p1 = &arg;
        while (*p1) {
            std::cout << *p1 << " ";
            p1++;
        }
        std::cout << std::endl;
    }

    static void foo() {
        std::cout << "void function" << std::endl;
    }

    static int def_arg(int b = 100000) {
        return b;
    }

    static void pass_by_value(int a, int b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    static void pass_by_reference(int& a, int& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    static int& return_by_reference(int a) {
        int l = 7;
        l += a;
        return l;
    }

    int some_f(int);
};

int Person::some_f(int a) {
    return a * 2;
}


int main() {
    Person Nikita("Nikita", "Kochetkov", "312f123as", rand() % 1000 + 1);
    Person *Alena = new Person("Alena", "Mordvinceva", "321sd23sa2f", rand() % 1000 +1);
    delete Alena;
    std::cout << static_cast<long>(pow(13,3)) << std::endl;
    std::cout << Person::sum(3, 4) << " = 7" << std::endl;
    std::cout << Person::sum((float)3.0, 5.0) << " = 8.0" << std::endl;
    Person::some_func(1, 5, 123, 3, 5, 4, 3, 2  , 1, 0);
    Person::foo();
    std::cout << "Without use def arg = " << Person::def_arg(15) << std::endl;
    std::cout << "With use def arg = " << Person::def_arg() << std::endl;
    int a = 11, b = 13;
    std::cout << "Pre: " << std::endl;
    std::cout << "a = " << a << " b = " << b << std::endl;
    Person::pass_by_value(a, b);
    std::cout << "value a = " << a << " b = " << b << std::endl;
    Person::pass_by_reference(a, b);
    std::cout << "reference a = " << a << " b = " << b << std::endl;
    //why it's work?   
    int &t = Person::return_by_reference(4);
    std::cout << t << std::endl;
    system("pause");
    return 0;
}

/*
1. Write  a Program to demonstrate functions. OK
2. Write  a Program to demonstrate function overloading. OK
3. Write  a Program to demonstrate default arguments. OK
4. Write  a Program to demonstrate pass by value, pass by reference and return by reference. OK
5. Write  a Program to demonstrate classes and objects. OK
6. Write  a Program to demonstrate  constructors. OK
*/