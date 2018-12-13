# Homework_cpp_3_term
1. Домашние задания
 * [Домашка №1](#HW1);
 * [Домашка №2](#HW2);
 * [Домашка №3](#HW3);
 * [Домашка №4](#HW4);
 * [Домашка №5](#HW5);
 * [Домашка №6](#HW6);
 * [Домашка №7](#HW7);
 * [Домашка №8](#HW8);
 * [Домашка №9](#HW9);
 * [Домашка №10](#HW10);
2. Полезные ссылки
 * [Ссылки](#links);

## <a name="HW1"></a> First HW


```
1. Write  a Program to demonstrate functions.
2. Write  a Program to demonstrate function overloading.
3. Write  a Program to demonstrate default arguments.
4. Write  a Program to demonstrate pass by value, pass by reference and return by reference.
5. Write  a Program to demonstrate classes and objects.
6. Write  a Program to demonstrate  constructors.
```

## <a name="HW2"></a> Second HW

```
You have to realize class **Student**  
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
```

## <a name="HW3"></a> Third HW

```
* Напишите простые файлы  hello.cpp, here.cpp, bye.cpp, mylib.h . В hello.cpp, функция должна выводить "Hello!";
в  here.cpp , другая функция должна выводить "I am here!";
еще одна функция должна выводить "Bye bye!" в  bye.cpp. mylib.h должен содержать объявления  всех трех функций
* Напишите  main.cpp, который вызывает все три функции, результатом работы программы является "Hello!" "I am here!" "Bye bye!" 
В файле main.cpp нет операторов вывода: 
* Напишите Makefile, который компилирует все файлы  и строит статическую библиотеку mylib.a, содержащую hello.cpp, here.cpp, bye.cpp, но не main.cpp
* Напишите Makefile, который компилирует все файлы  и строит динамическую библиотеку с soname библиотеки libmylib.so.5.
* Установите  minor версию .1 и релиз .10. 
Таким образом вы получите динамическую библиотеку с именем файла "libmylib.so.5.1.10" c установленными .so ссылками
```
## <a name="HW4"></a> Fourth HW

![HW_4_pic_1](/img/HW_4_pic_1.jpg)

![HW_4_pic_2](/img/HW_4_pic_2.jpg)

## <a name="HW5"></a> Fifth HW

```
Cоздадим свой простой аналог стандартного класса string для удобной работы со
строками.
Начнем мы с написания конструктора. В этой задаче вам требуется реализовать
конструктор, который принимает на вход C-style строку, вычисляет ее размер (без
учета завершающего 0 символа) и сохраняет его в поле size, кроме того,
конструктор должен аллоцировать память достаточную для хранения копии
переданной строки (вместе с завершающим 0 символом), копирует переданную
строку в выделенную память и сохраняет указатель на начало этой области
памяти в поле str. Т.е. в результате работы конструктора в поле str должен
оказаться указатель на C-строку c копией исходной строки, а в поле size — длина
строки без учета завершающего нулевого символа.
Конструкторов у структуры может быть несколько. Для строки может оказаться
полезным заполняющий конструктор (например, чтобы создать строку пробелов).
Заполняющий конструктор принимает число и символ, и создает строку с
заданным количеством повторений переданного символа. Условия налагаемые на
реализацию конструктора те же самые (в поле size размер без учета
завершающего 0 символа, в поле str C-style строка, т.е. с завершающим 0
символом). Кроме конструктора в этой задаче вам нужно также реализовать и
деструктор, который освободит выделенную память.
Для работы со строками можно придумать множество полезных методов
(подумайте, какие методы пригодились бы вам, и чего вам не хватает для их
реализации). Примером такого метода может послужить метод append — он
добавляет копию строки-аргумента в конец текущей строки (т.е. в конец строки, у
которой он был вызван).
String s1("Hello,");
String s2(" world!");
s1.append(s2); // теперь s1 хранит "Hello, world!"
Ваша задача реализовать метод append.
При выполнении задания будьте аккуратны при работе с памятью — при вызове
метода не должно возникать утечек памяти. Кроме того, не забудьте, что size
хранит размер без учета завершающего 0 символа.
Кроме того, ваша реализация должна корректно работать в следующем тесте:
String s("Hello");
s.append(s); // теперь s хранит "HelloHello"
Добавьте в класс String реализацию конструктора копирования. Инвариант класса
остается тем же (в size хранится размер строки без завершающего 0 символа, str
указывает на C-style строку, т. е. с завершающим нулевым символом).
Завершите класс String, добавив к нему оператор присваивания. Будьте аккуратны при
работе с памятью. Инвариант класса остается тем же (в size хранится размер строки без
завершающего 0 символа, str указывает на C-style строку, т. е. с завершающим нулевым
символом).
```

## <a name="HW6"></a> Sixth HW

```
Придумайте некоторый класс, для которого разумно переопределить все доступные для переопределения операторы в C++. Использовать String, BigInt и Vector запрещено. Чем оригинальнее у вас будет класс, тем больше шансов, что вас будут не сильно мучать на сдаче.

Отлично, выбрали, теперь переоределите для него все доступные для переопределения операторы в C++ (кроме операторов работы с памятью).
```

## <a name="HW7"></a> Seventh HW
[Homework 7](/pdf/hw7.pdf)

## <a name="HW8"></a> Eighth HW
[Homework 8](/pdf/hw8.pdf)

## <a name="HW9"></a> Ninth HW
[Homework 9](/pdf/hw9.pdf)

## <a name="HW10"></a> Tenth HW
[Homework 10](/pdf/hw10.pdf)

## <a name="links"></a> Useful links

* [Страничка курса](http://neerc.ifmo.ru/teaching/cpp/year2017/sem3/)
* [Книжка по CMake](http://ru.b-ok.org/book/2933576/d7760f)
