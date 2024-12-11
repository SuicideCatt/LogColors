cmake_minimum_required(VERSION 3.12)

project(LogColors VERSION 0.1.0)

option(TESTS "Enable tests" OFF)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(TESTS)
	add_executable(test tests/main.cpp)
	target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SCT/${PROJECT_NAME})
