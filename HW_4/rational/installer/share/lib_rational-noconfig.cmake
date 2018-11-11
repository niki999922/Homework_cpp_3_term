#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "lib_rational" for configuration ""
set_property(TARGET lib_rational APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(lib_rational PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/liblib_rational.dll.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/liblib_rational.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS lib_rational )
list(APPEND _IMPORT_CHECK_FILES_FOR_lib_rational "${_IMPORT_PREFIX}/lib/liblib_rational.dll.a" "${_IMPORT_PREFIX}/bin/liblib_rational.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
