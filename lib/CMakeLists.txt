find_package(Qt5 CONFIG REQUIRED Core Widgets)

file(GLOB_RECURSE srcFiles *.c*)

# message("++ headers: ${headers}")
message("++ srcFiles: ${srcFiles}")

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${srcFiles})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)

FormatCode(${PROJECT_NAME})
TidyCode(${PROJECT_NAME})