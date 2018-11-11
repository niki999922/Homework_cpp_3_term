#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "polynom" for configuration ""
set_property(TARGET polynom APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(polynom PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libpolynom.dll.a"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "lib_rational"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/libpolynom.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS polynom )
list(APPEND _IMPORT_CHECK_FILES_FOR_polynom "${_IMPORT_PREFIX}/lib/libpolynom.dll.a" "${_IMPORT_PREFIX}/bin/libpolynom.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
