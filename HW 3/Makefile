CFLAGS=-O1 -std=c++11

# make
# make create_exe_sl
# make libmy.lib
# make create_exe_dl
# make libmylib.dll
# make clean
# make full_clean

all:  hello.obj here.obj bye.obj main.obj
	g++ $(CFLAGS) hello.obj here.obj bye.obj main.obj -o TestProgram

test:
	./TestProgram

# -lmy it's lib + my + .a
# -L. where he have to find lib, without -L it;s  /lib or /usr/lib
create_exe_sl : main.obj libmy.lib
	g++ $(CFLAGS) main.obj -L. libmy.lib -o TestProgram

# name have to be with pref = lib and suff = .a or for Unix system .lib (may be)
libmy.lib: hello.obj here.obj bye.obj
	ar cr libmy.lib hello.obj here.obj bye.obj

create_exe_dl: main.obj libmylib.dll.5.1.10
	g++ $(CFLAGS) main.obj -L. libmylib.dll.5.1.10 -o TestProgram

libmylib.dll.5.1.10: d_hello.obj d_here.obj d_bye.obj
	g++ -shared -Wl,-soname,libmylib.dll.5 d_hello.obj d_here.obj d_bye.obj -o libmylib.dll.5.1.10

d_hello.obj: hello.cpp
	g++ $(CFLAGS) -c -fPIC $^ -o $@

d_here.obj: here.cpp
	g++ $(CFLAGS) -c -fPIC $^ -o $@

d_bye.obj: bye.cpp
	g++ $(CFLAGS) -c -fPIC $^ -o $@

clean:
	DEL *.obj

full_clean:
	DEL *.obj *.exe *.lib *.dll*

%.obj: %.cpp
	g++ $(CFLAGS) -c $^ -o $@

