#include<iostream>

class Student {
public:
    void takeData() {
        std::cout << "_______________________\n\n";
        std::cout << "Enter the value of admno: ";
        std::cin >> admno;
        std::cout << "Enter the value of sname: ";
        std::cin >> sname;
        std::cout << "Enter the value of english: ";
        std::cin >> english;
        std::cout << "Enter the value of science: ";
        std::cin >> science;
        std::cout << "Enter the value of maths: ";
        std::cin >> maths;
        total = cTotal();
    }

    void showData() {
        std::cout << "_______________________\n\n";
        std::cout << "admno: " << admno << '\n';
        std::cout << "sname: " << sname << '\n';
        std::cout << "english: " << english << '\n';
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
    Student student;
    student.takeData();
    student.showData();
    system("pause");
    return 0;
}


/*

You have to realize class student  
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