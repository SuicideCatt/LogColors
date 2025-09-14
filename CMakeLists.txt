cmake_minimum_required(VERSION 3.12)

project(LogColors VERSION 0.3.1)

option(TESTS "Enable tests" OFF)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(TESTS)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

	add_executable(test tests/main.cpp)
	add_executable(for_readme tests/for_readme.cpp)
endif()

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SCT/${PROJECT_NAME})
install(FILES LICENSE
		DESTINATION ${CMAKE_INSTALL_PREFIX}/share/licenses/SCT/${PROJECT_NAME})
