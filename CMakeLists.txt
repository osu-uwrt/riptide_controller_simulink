
project(build_x86_and_arm)
cmake_minimum_required(VERSION 3.8)
include(ExternalProject)

set(INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/include)
set(SO_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/bin)
set(FINAL_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../)

ExternalProject_Add(Porportional_Follower_Test_x86
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin/x86
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Porportional_Follower_Test_ert_shrlib_rtw
    CMAKE_ARGS string(CONCAT "-DCMAKE_INSTALL_PREFIX=${SO_INSTALL_DIR}/x86"))

ExternalProject_Add(Porportional_Follower_Test_arm
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin/arm
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Porportional_Follower_Test_ert_shrlib_rtw
    CMAKE_ARGS  string(CONCAT "-DCMAKE_INSTALL_PREFIX=${SO_INSTALL_DIR}/arm")
                "-DCMAKE_C_COMPILER=/usr/bin/aarch64-linux-gnu-gcc-9"
                "-DCMAKE_CXX_COMPILER=/usr/bin/aarch64-linux-gnu-g++-9")

file(GLOB HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Porportional_Follower_Test_ert_shrlib_rtw ${CMAKE_CURRENT_SOURCE_DIR}/Porportional_Follower_Test_ert_shrlib_rtw/*.h)

add_custom_target( move_headers ALL 
    tar -cf headers.tar ${HEADER_FILES}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${INCLUDE_DIR}
    COMMAND mv headers.tar ${INCLUDE_DIR}/headers.tar
    COMMAND tar -xf ${INCLUDE_DIR}/headers.tar -C ${INCLUDE_DIR}/

    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Porportional_Follower_Test_ert_shrlib_rtw
    DEPENDS Porportional_Follower_Test_x86 Porportional_Follower_Test_arm

    COMMENT "Copying MATLAB Generated Headers"
    VERBATIM
)

add_custom_command(
    TARGET move_headers POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove ${INCLUDE_DIR}/headers.tar
)

add_custom_target( move_final_build_dir ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${FINAL_INSTALL_DIR}
    COMMAND mv ${CMAKE_CURRENT_BINARY_DIR}/build ${FINAL_INSTALL_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS move_headers

    COMMENT "Moving build directory outside of riptide_controller_simulink"
    VERBATIM
)