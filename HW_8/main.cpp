#include <iostream>

#include "BearPigMan.h"
#include "functions.cpp"

using namespace functions;
using std::cout;
using std::string;


void testGame() {
    cout << "======= GAME =======\n";
    auto firstUnit = BearPigMan(1, Unit::MAX_HP, Unit::DEFAULT_ARMOR, 15);
    auto secondUnit = BearPigMan(2, Unit::MAX_HP, -2);
    firstUnit.printInfo();
    secondUnit.printInfo();
    cout << '\n';

    secondUnit.shieldsUp();
    secondUnit.printInfo();
    cout << '\n';

    firstUnit.attack(secondUnit);
    secondUnit.grunt();
    secondUnit.printInfo();
    cout << '\n';

    secondUnit.healWounds();
    secondUnit.printInfo();
    cout << '\n';

    secondUnit.sitIntoTheBurningCar();
    secondUnit.log(secondUnit.isDead() ? "dead now" : "not dead yet!");
    secondUnit.printInfo();
}


void testComplexFunctions() {
    cout << "======= COMPLEX FUNCTION =======\n";
    complexFunction complex = [](int x, parameterFunction f) -> resultFunction {
        cout << "In complex\n";

        cout << f(x) << '\n';

        resultFunction result = [](char const * x) -> int* {
            cout << "In result\n";
            return const_cast<int*>(reinterpret_cast<const int*>(x));
        };

        return result;
    };

    parameterFunction other = [](double x) -> int {
        cout << "In parameter: ";
        return (int) x;
    };

    cout << (complex(4, other))("3") << '\n';
}


void testCompare() {
    cout << "======= COMPARE =======\n";
    string first = "Elf";
    string second = "Archer";
    cout << "first : " << first << "\nsecond : " << second << '\n';
    cout << "first < second: "
         << (compare(first, second, &string::size) ? "true" : "false")
         << '\n';

    cout << "first < first: "
         << (compare(first, first, &string::size) ? "true" : "false")
         << '\n';
}

void testSameObject() {
    cout << "======= SAME OBJECT =======\n";
    auto firstUnit = BearPigMan(1, Unit::MAX_HP, Unit::DEFAULT_ARMOR, 15);
    auto secondUnit = BearPigMan(1, Unit::MAX_HP, Unit::DEFAULT_ARMOR, 15);
    auto pig = Pig(1, Unit::MAX_HP, Unit::DEFAULT_ARMOR, 15);
    auto* pigCast = dynamic_cast<Pig*>(&firstUnit);

    cout << "first is second: "
         << (isSameObject(&firstUnit, &secondUnit) ? "true" : "false")
         << '\n';

    cout << "first is first: "
         << (isSameObject(&firstUnit, &firstUnit) ? "true" : "false")
         << '\n';

    cout << "first is pig: "
         << (isSameObject(&pig, pigCast) ? "true" : "false")
         << '\n';
}


void test() {
    testGame();
    cout << '\n';
    testComplexFunctions();
    cout << '\n';
    testCompare();
    cout << '\n';
    testSameObject();
}


int main() {
    test();
    system("pause");
    return 0;
}