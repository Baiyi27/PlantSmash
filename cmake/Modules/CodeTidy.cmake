find_package(ClangTidy)

set_property(GLOBAL PROPERTY clangTidyFiles)

if(clangTidyExe)
    set(enableClangTidy OFF CACHE BOOL "Enable clang-tidy integration")
    set(doClangTidy "${clangTidyExe}")

function(TidyCode target)

    if(TARGET ${target})
            # Enable CMake integration of clang-tidy when compiling
            if(enableClangTidy)
                set_target_properties(${target} PROPERTIES
                    C_CLANG_TIDY "${doClangTidy}"
                    CXX_CLANG_TIDY "${doClangTidy}")
            endif()
            
            # Add the source file to the global property
            get_target_property(srcFiles ${target} SOURCES)
            get_property(allTidyFiles GLOBAL PROPERTY clangTidyFiles)

            foreach(fileToTidy ${srcFiles})
                if(NOT ${fileToTidy} MATCHES "h$")
                    list(APPEND allTidyFiles ${fileToTidy})
                endif()
            endforeach()

            list(REMOVE_DUPLICATES allTidyFiles)
            set_property(GLOBAL PROPERTY clangTidyFiles ${allTidyFiles})
    else()
        message(WARNING "Target ${target} does not exists.")
    endif()
endfunction()

function(DefTidyCodeCustom)
    if(clangTidyExe)
        get_property(allTidyFiles GLOBAL PROPERTY clangTidyFiles)
        set(commands)

        foreach(fileToTidy ${allTidyFiles})
            list(APPEND commands COMMAND ${clangTidyExe} -p ${CMAKE_BINARY_DIR} ${fileToTidy})
        endforeach()

        list(LENGTH allTidyFiles numFiles)
        add_custom_target(
            tidyCode
            ${commands}
            COMMENT "Applying clang-tidy fixes on ${numFiles} files")

        # Ensure 'tidyCode' is run before the build step
        # add_dependencies(${PROJECT_NAME} tidyCode)
    endif()
endfunction()

else()
    message(WARNING "'clang-tidy.exe' not found")
endif()