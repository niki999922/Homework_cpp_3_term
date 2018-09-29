#include <iostream>

class Person;

class Person {
public:
    Person(std::string userName, std::string userSurename, std::string account, long sizeMas, long cash) :
        name(userName),
        surename(userSurename),
        accountNumber(account),
        size(sizeMas),  
        cash(cash) 
    {
        mas = new long[size];
    }

    //Pre : name === surename
    Person(std::string userName, std::string account, long sizeMas, long cash) {
        this->name = userName;
        this->surename = userName;
        this->accountNumber = account;
        this->size = sizeMas;
        this->cash = cash;
        this->mas = new long[size];
    }

    ~Person() {
        delete [] mas;
    }

    std::string getName() {
        return name;
    }

    std::string getSurename() {
        return surename;
    }

    std::string getAccountNumber() {
        return accountNumber;
    }

    long getCash() {
        return cash;
    }

    static int sum(int a, int b) {
        return a + b;
    }

    static float sum(float a, float b) {
        return a + b;
    }

    //Can be rewrited with templates
    static void someFunction(int arg, ...) {
        int *p1 = &arg;
        while (*p1) {
            std::cout << *p1 << " ";
            p1++;
        }
        std::cout << '\n';
    }

    static void foo() {
        std::cout << "void function" << std::endl;
    }

    static int defArg(int b = 100000) {
        return b;
    }

    static void passByValue(int a, int b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    static void passByReference(int& a, int& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    static Person& maxCashReturnByReference(Person& p1, Person& p2) {
        return (p1.getCash() > p2.getCash()) ? p1 : p2;
    }

    int pow2(int);

protected:
    std::string childrens;

private:
    std::string name, surename;
    std::string accountNumber;
    long size;
    long cash;
    long *mas;
};

int Person::pow2(int a) {
    return a * a;
}


int main(int argc, char* argv[]) {
    Person Nikita("Nikita", "Kochetkov", "312f123as", rand() % 1000 + 1,1000);
    Person *Alena = new Person("Alena", "Mordvinceva", "321sd23sa2f", rand() % 1000 +1,17000);
    std::cout << Person::maxCashReturnByReference(Nikita, *Alena).getCash() << std::endl;
    delete Alena;
    std::cout << static_cast<long>(pow(13,3)) << std::endl;
    std::cout << Person::sum(3, 4) << " = 7" << std::endl;
    std::cout << Person::sum((float)3.0, 5.0) << " = 8.0" << std::endl;
    Person::someFunction(1, 5, 123, 3, 5, 4, 3, 2, 1, 0);
    Person::foo();
    std::cout << "Without use def arg = " << Person::defArg(15) << std::endl;
    std::cout << "With use def arg = " << Person::defArg() << std::endl;
    int a = 11, b = 13;
    std::cout << "Was:      a = " << a << " b = " << b << std::endl;
    Person::passByValue(a, b);
    std::cout << "value:    a = " << a << " b = " << b << std::endl;
    Person::passByReference(a, b);
    std::cout << "reference a = " << a << " b = " << b << std::endl;
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