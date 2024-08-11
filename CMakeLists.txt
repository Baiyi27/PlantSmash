cmake_minimum_required(VERSION 3.27)

project(PlantSuperSmash
    VERSION 0.0.1
    HOMEPAGE_URL "https://github.com/Baiyi27/PlantSmash.git"
    LANGUAGES "CXX")

message("++ '${CMAKE_PROJECT_NAME}' current version: ${CMAKE_PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(enableCtest "Enable Modules test" ON)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    set(isRoot ON)
endif()

if(enableCtest) 
    add_subdirectory(tests)
endif()

if(isRoot)
    message("++ is root CMakeLists.txt")
endif()