add_executable( example.ff_101 example.ff_101.cpp )
target_link_libraries( example.ff_101
    FastFormat
)
add_custom_target( examples DEPENDS example.ff_101 )

