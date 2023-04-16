#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "FaultControllerModel::FaultControllerModel" for configuration "Release"
set_property(TARGET FaultControllerModel::FaultControllerModel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(FaultControllerModel::FaultControllerModel PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./FaultControllerModel.so"
  IMPORTED_SONAME_RELEASE "FaultControllerModel.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS FaultControllerModel::FaultControllerModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_FaultControllerModel::FaultControllerModel "${_IMPORT_PREFIX}/./FaultControllerModel.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
