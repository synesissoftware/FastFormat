add_executable( example.arguments.reals example.arguments.reals.cpp )
target_link_libraries( example.arguments.reals
    FastFormat
)
add_custom_target( examples DEPENDS example.arguments.reals )

