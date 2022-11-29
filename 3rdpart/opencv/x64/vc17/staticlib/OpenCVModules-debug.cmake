#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "zlib" for configuration "Debug"
set_property(TARGET zlib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(zlib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/x64/vc17/staticlib/zlibd.lib"
  )

list(APPEND _cmake_import_check_targets zlib )
list(APPEND _cmake_import_check_files_for_zlib "${_IMPORT_PREFIX}/x64/vc17/staticlib/zlibd.lib" )

# Import target "libopenjp2" for configuration "Debug"
set_property(TARGET libopenjp2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libopenjp2 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/x64/vc17/staticlib/libopenjp2d.lib"
  )

list(APPEND _cmake_import_check_targets libopenjp2 )
list(APPEND _cmake_import_check_files_for_libopenjp2 "${_IMPORT_PREFIX}/x64/vc17/staticlib/libopenjp2d.lib" )

# Import target "ippiw" for configuration "Debug"
set_property(TARGET ippiw APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ippiw PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/x64/vc17/staticlib/ippiwd.lib"
  )

list(APPEND _cmake_import_check_targets ippiw )
list(APPEND _cmake_import_check_files_for_ippiw "${_IMPORT_PREFIX}/x64/vc17/staticlib/ippiwd.lib" )

# Import target "ittnotify" for configuration "Debug"
set_property(TARGET ittnotify APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ittnotify PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/x64/vc17/staticlib/ittnotifyd.lib"
  )

list(APPEND _cmake_import_check_targets ittnotify )
list(APPEND _cmake_import_check_files_for_ittnotify "${_IMPORT_PREFIX}/x64/vc17/staticlib/ittnotifyd.lib" )

# Import target "opencv_core" for configuration "Debug"
set_property(TARGET opencv_core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(opencv_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/x64/vc17/staticlib/opencv_core460d.lib"
  )

list(APPEND _cmake_import_check_targets opencv_core )
list(APPEND _cmake_import_check_files_for_opencv_core "${_IMPORT_PREFIX}/x64/vc17/staticlib/opencv_core460d.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
