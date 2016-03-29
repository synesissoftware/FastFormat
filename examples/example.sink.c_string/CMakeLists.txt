add_executable( example.sink.c_string example.sink.c_string.cpp )
target_link_libraries( example.sink.c_string
    FastFormat
)
add_custom_target( examples DEPENDS example.sink.c_string )

