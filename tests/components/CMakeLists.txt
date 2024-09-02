project(CharacterSelection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

file(GLOB srcFiles ${CMAKE_SOURCE_DIR}/tests/components/*.cc ${CMAKE_SOURCE_DIR}/tests/view/LoginWindow.cc)
message(${CMAKE_SOURCE_DIR})
file(GLOB headers ${CMAKE_SOURCE_DIR}/src/include/components/*.hh ${CMAKE_SOURCE_DIR}/src/include/view/*.hh)
message("++ headers: ${headers}")
qt5_wrap_cpp(mocSrc ${headers})

add_executable(${PROJECT_NAME}
  ${srcFiles}
  ${mocSrc}
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/include/components ${CMAKE_SOURCE_DIR}/src/include/view )
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)

set_target_propertieS(${PROJECT_NAME} PROPERTIES AUTOMOC ON)
set_target_propertieS(${PROJECT_NAME} PROPERTIES AUTOUIC ON)
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})