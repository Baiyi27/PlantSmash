project(Mock)

find_package(Qt5 CONFIG REQUIRED Core Widgets)

file(GLOB mocHeaders include/QTmock.hh)
file(GLOB_RECURSE srcFiles src/*.cc)

qt5_wrap_cpp(mocSrc ${mocHeaders})

add_executable(${PROJECT_NAME}
    ${srcFiles}
    ${mocSrc}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)

add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME})

FormatCode(${PROJECT_NAME} EXCLUDES "moc_.*")
