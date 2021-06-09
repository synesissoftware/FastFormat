add_executable( example.arguments.boolean example.arguments.boolean.cpp )
target_link_libraries( example.arguments.boolean
    FastFormat
)
add_custom_target( examples DEPENDS example.arguments.boolean )

