cmake_minimum_required(VERSION 3.00)

project(LogColors VERSION 0.1.0)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SCT/${PROJECT_NAME})
