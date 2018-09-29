#include <iostream>

#include "Student.h"
#include "Book.h"


int main(int argc, char* argv[]) {
    Book book;
    book.input();
    book.purchase();
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