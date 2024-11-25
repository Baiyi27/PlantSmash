project(Framework)

find_package(Qt5 CONFIG REQUIRED Core Widgets)

add_executable(${PROJECT_NAME} Qt5test.cc)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)

add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME})

FormatCode(${PROJECT_NAME})