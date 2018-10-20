project(polynom)

set(BUILD_SHARED_LIBS ON)

add_library(${PROJECT_NAME} polynom.cpp polynom.h)
include_directories(../lib_rational)

target_link_libraries(${PROJECT_NAME} lib_rational)


get_property(
	LIB_TYPE
	TARGET ${PROJECT_NAME}
	PROPERTY TYPE)

if(LIB_TYPE STREQUAL SHARED_LIBRARY)
	install(
		TARGETS ${PROJECT_NAME}
		COMPONENT user
		RUNTIME
			DESTINATION bin
		LIBRARY
			DESTINATION lib)
endif()


install(
	TARGETS ${PROJECT_NAME}
	EXPORT ${PROJECT_NAME}
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
	EXPORT ${PROJECT_NAME}
	DESTINATION share
	COMPONENT developer)