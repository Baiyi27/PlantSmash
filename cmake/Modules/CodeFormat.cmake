find_package(ClangFormat)

set_property(GLOBAL PROPERTY clangFormatFiles)

if(clangFormatExe)
function(FormatCode target)
        set(options)
        set(oneValueArgs)
        set(multiValueArgs EXCLUDES)
        cmake_parse_arguments(clang_format "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

        if(TARGET ${target})
            get_target_property(srcFiles ${target} SOURCES)
            get_property(allSrcFiles GLOBAL PROPERTY clangFormatFiles)

            foreach(fileToFormat ${srcFiles})
                set(excluded FALSE)

                foreach(exclude ${clang_format_EXCLUDES})
                    if(${fileToFormat} MATCHES ${exclude})
                        set(excluded TRUE)
                        message("++ Excluding file to format: ${fileToFormat} because it matches ${exclude}")
                    endif()
                endforeach()

                if(NOT ${excluded})
                    get_filename_component(relativeFile ${fileToFormat} ABSOLUTE)
                    list(APPEND allSrcFiles ${relativeFile})
                endif()
            endforeach()

            list(REMOVE_DUPLICATES allSrcFiles)
            set_property(GLOBAL PROPERTY clangFormatFiles ${allSrcFiles})
        else()
            message(WARNING "Target ${target} does not exists.")
        endif()
    endfunction()

    function(DefFormatCodeCustom)
        if(clangFormatExe)
            get_property(allFiles GLOBAL PROPERTY clangFormatFiles)
            # message("+++ Formatting files: ${allFiles}")
            set(commands)

            foreach(fileToFormat ${allFiles})
                # message("+++ Current fileToFormat: ${fileToFormat}")
                list(APPEND commands COMMAND ${clangFormatExe} -i -style=file -fallback-style=webkit -verbose ${fileToFormat})
            endforeach()

            list(LENGTH allFiles numFiles)
            add_custom_target(
                formatCode
                ${commands}
                COMMENT "Format ${numFiles} source files")
        endif()
    endfunction()

    function(DefFormatCodeAuto)
        if(clangFormatExe)
            get_property(allFiles GLOBAL PROPERTY clangFormatFiles)
            # message("+++ Formatting files: ${allFiles}")

            # Set up commands for clang-format
            set(commands)

            foreach(fileToFormat ${allFiles})
                # message("+++ Current fileToFormat: ${fileToFormat}")
                list(APPEND commands COMMAND ${clangFormatExe} -i -style=file -fallback-style=webkit -verbose ${fileToFormat})
            endforeach()

            list(LENGTH allFiles numFiles)
            add_custom_target(
                formatCode ALL
                ${commands}
                COMMENT "Format ${numFiles} source files")

            # Ensure format_code is run before the build step
            add_dependencies(${PROJECT_NAME} formatCode)
        endif()
    endfunction()

else()
    message(WARNING "'clang-format.exe' not found")
endif()