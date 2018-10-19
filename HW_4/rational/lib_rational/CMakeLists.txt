project(lib_rational)

add_library(lib_rational lib_rational.cpp lib_rational.h)

get_property(
	LIB_TYPE
	TARGET lib_rational
	PROPERTY TYPE)

if(LIB_TYPE STREQUAL SHARED_LIBRARY)
	install(
		TARGETS lib_rational
		COMPONENT user
		RUNTIME
			DESTINATION bin
		LIBRARY
			DESTINATION lib)
endif()


install(
	TARGETS lib_rational
	EXPORT lib_rational
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
	EXPORT lib_rational
	DESTINATION share
	COMPONENT developer)