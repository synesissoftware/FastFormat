add_executable( example.arguments.void_pointers example.arguments.void_pointers.cpp )
target_link_libraries( example.arguments.void_pointers
    FastFormat
)
add_custom_target( examples DEPENDS example.arguments.void_pointers )

