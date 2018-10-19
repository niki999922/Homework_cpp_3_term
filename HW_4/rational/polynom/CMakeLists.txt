project(polynom)

add_library(polynom polynom.cpp polynom.h)
include_directories(../lib_rational)

target_link_libraries(polynom lib_rational)


get_property(
	LIB_TYPE
	TARGET polynom
	PROPERTY TYPE)

if(LIB_TYPE STREQUAL SHARED_LIBRARY)
	install(
		TARGETS polynom
		COMPONENT user
		RUNTIME
			DESTINATION bin
		LIBRARY
			DESTINATION lib)
endif()


install(
	TARGETS polynom
	EXPORT polynom
	COMPONENT developer
	RUNTIME
		DESTINATION bin
	LIBRARY
		DESTINATION lib
	ARCHIVE
		DESTINATION lib)

install(
	DIRECTORY .
	DESTINATION include
	COMPONENT developer
	FILES_MATCHING
		PATTERN "*.h")

install(
	EXPORT polynom
	DESTINATION share
	COMPONENT developer)