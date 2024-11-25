cmake_minimum_required(VERSION 3.27)

project("PlantSuperSmash"
    VERSION "0.0.1"
    HOMEPAGE_URL "https://github.com/Baiyi27/PlantSmash.git"
    LANGUAGES "CXX")

message("++ Project '${CMAKE_PROJECT_NAME}' current version: '${CMAKE_PROJECT_VERSION}'")

option(enableCTest "Enable Modules test" OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
include(ToolsChain)
include(CodeFormat)
include(CodeTidy)
find_package(Git)

# Library
add_subdirectory(lib)

# file(GLOB headerDirs CONFIGURE_DEPENDS lib/include/*/)
# foreach(dir IN LISTS headerDirs)
#     if(IS_DIRECTORY ${dir})
#         message("++ Adding include directory: ${dir}")
#         target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${dir})
#     endif()
# endforeach()

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/include)

if(enableCTest)
    add_subdirectory(tests)
endif()

# message("++ ${CMAKE_CXX_CLANG_TIDY}")
DefFormatCodeAuto()
DefTidyCodeCustom()

message(">> Optional: build the target 'tidyCode' (cmake --build build --target tidyCode) before building 'all' target")
