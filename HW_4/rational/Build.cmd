mkdir _build
cd _build

set PATH=C:\Users\Nikita\source\repos\Homework_cpp_3_term\HW_4\rational;%PATH%

cmake^
	-G "MinGW Makefiles"^
	-D CMAKE_INSTALL_PREFIX=C:\Users\Nikita\source\repos\Homework_cpp_3_term\HW_4\rational\installer^
	C:\Users\Nikita\source\repos\Homework_cpp_3_term\HW_4\rational
	
mingw32-make
cmake -D COMPONENT=developer -P cmake_install.cmake

cd ..