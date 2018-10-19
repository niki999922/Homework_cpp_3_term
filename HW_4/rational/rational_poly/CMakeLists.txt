project(rational_poly)

add_executable(rational_poly rational_poly.cpp)
include_directories(../lib_rational ../polynom)

target_link_libraries(rational_poly lib_rational polynom)


install(
	TARGETS rational_poly
	COMPONENT user
		DESTINATION bin)
install(
	TARGETS rational_poly
	COMPONENT developer
	RUNTIME
		DESTINATION bin)