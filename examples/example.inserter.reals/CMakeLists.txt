add_executable( example.inserter.reals example.inserter.reals.cpp )
target_link_libraries( example.inserter.reals
    FastFormat
)
add_custom_target( examples DEPENDS example.inserter.reals )

