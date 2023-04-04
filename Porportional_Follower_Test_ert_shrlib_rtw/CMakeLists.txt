######################################################################
# CMakeLists.txt generated for component Porportional_Follower_Test
# Product type: shared library
######################################################################
cmake_minimum_required(VERSION 3.12)
project(Porportional_Follower_Test)
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT /usr/local/MATLAB/R2022b CACHE PATH "")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
if(${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(BUILDING_IN_SOURCE_DIR TRUE)
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BUILDING_IN_SOURCE_DIR FALSE)
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()

######################################################################
## Target definition and commands
######################################################################
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()
add_library(Porportional_Follower_Test SHARED ${START_DIR}/Porportional_Follower_Test_ert_shrlib_rtw/Porportional_Follower_Test.c)
set_target_properties(Porportional_Follower_Test PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
if(CMAKE_CXX_COMPILER)
    set_target_properties(Porportional_Follower_Test PROPERTIES LINKER_LANGUAGE CXX)
endif()
target_compile_features(Porportional_Follower_Test PUBLIC c_std_99)
target_compile_definitions(Porportional_Follower_Test PRIVATE -DMODEL=Porportional_Follower_Test
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0)
target_compile_options(Porportional_Follower_Test PRIVATE -fwrapv)
target_include_directories(Porportional_Follower_Test PUBLIC $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${START_DIR}/Porportional_Follower_Test_ert_shrlib_rtw>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/Porportional_Follower_Test_ert_shrlib_rtw>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/simulink/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src/ext_mode/common>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/ert>)
find_library(FOUND_LIBM m)
if(FOUND_LIBM)
   target_link_libraries(Porportional_Follower_Test PUBLIC m)
endif()


######################################################################
## Target install and export rules
######################################################################
install(TARGETS Porportional_Follower_Test EXPORT Porportional_Follower_TestTargets RUNTIME DESTINATION .
    LIBRARY DESTINATION .
    ARCHIVE DESTINATION .)
install(EXPORT Porportional_Follower_TestTargets NAMESPACE Porportional_Follower_Test:: DESTINATION Porportional_Follower_Test_ert_shrlib_rtw/export)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Porportional_Follower_Test.cmake 
 "include(\"\${CMAKE_CURRENT_LIST_DIR}/Porportional_Follower_TestTargets.cmake\")" \n
    "target_include_directories(Porportional_Follower_Test::Porportional_Follower_Test INTERFACE \n"
    "    \${MATLAB_ROOT}/extern/include" \n 
    "    \${MATLAB_ROOT}/simulink/include" \n 
    "    \${MATLAB_ROOT}/rtw/c/src" \n 
    "    \${MATLAB_ROOT}/rtw/c/src/ext_mode/common" \n 
    "    \${MATLAB_ROOT}/rtw/c/ert)" \n )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Porportional_Follower_Test.cmake DESTINATION Porportional_Follower_Test_ert_shrlib_rtw/export)

######################################################################
## Build success message
######################################################################
add_custom_command(TARGET Porportional_Follower_Test POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created library: $<TARGET_FILE:Porportional_Follower_Test>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(Porportional_Follower_Test)
endif()
