project(rational_poly)

add_executable(${PROJECT_NAME} rational_poly.cpp)
include_directories(../lib_rational ../polynom)

target_link_libraries(${PROJECT_NAME} lib_rational polynom)


install(
	TARGETS ${PROJECT_NAME}
	COMPONENT user
		DESTINATION bin)
install(
	TARGETS ${PROJECT_NAME}
	COMPONENT developer
	RUNTIME
		DESTINATION bin)