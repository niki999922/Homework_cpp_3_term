#include<iostream>

class Student {
public:
    void takeData() {
        std::cout << "_______________________\n\n";
        std::cout << "Enter the value of admno: ";
        std::cin >> admno;
        std::cout << "Enter the value of sname:\n";
        for (size_t i = 0; i < 20; ++i) {
            std::cout << "sname[" << i << "] = ";
            std::cin >> sname[i];
        }
        std::cout << "Enter the value of eng: ";
        std::cin >> english;
        std::cout << "Enter the value of science: ";
        std::cin >> science;
        std::cout << "Enter the value of maths: ";
        std::cin >> maths;
        total = cTotal();
    }

    void takeData(int admno, char* sname, float english, float maths, float science) {
        this->admno = admno;
        for (size_t i = 0; i < 20; ++i) {
            this->sname[i] = sname[i];
        }
        this->english = english;
        this->maths = maths;
        this->science = science;
        total = cTotal();
    }
    
    void showData() {
        std::cout << "_______________________\n\n";
        std::cout << "admno: " << admno << '\n';
        std::cout << "sname: ";
        for(size_t i = 0; i < 20; ++i) std::cout << sname[i] << ' ';
        std::cout << "\neng: " << english << '\n';
        std::cout << "science: " << science << '\n';
        std::cout << "maths: " << maths << '\n';
        std::cout << "total: " << total << '\n';
    }

private:
    int admno;
    char sname[20];
    float english, maths, science;
    float total;
            
    float cTotal() {
        return english + maths + science;
    }
};


int main(int argc, char* argv[]) {
    char* mas = new char[20];
    for (size_t i = 0; i < 20; ++i) {
        mas[i] = static_cast<char>(rand() % 256);
    }
    Student student;
    student.takeData();
    student.showData();
    student.takeData(rand() % 100 + 4, mas, rand() % 10 + 4, rand() % 10 + 4, rand() % 10 + 4);
    student.showData();
    system("pause");
    return 0;
}


/*

Необходимо реализовать класс student  
Private members of class student:
admno integer
sname 20 character 
eng. math, science float 
total float 
ctotal() 
    a function to calculate eng + math + science with float return type.

Public member function of class student:
Takedata() 
    Function to accept values for admno, sname, eng, science and invoke ctotal() to calculate total. 
Showdata() 
    Function to display all the data members on the screen

*/