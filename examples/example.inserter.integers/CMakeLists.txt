add_executable( example.inserter.integers example.inserter.integers.cpp )
target_link_libraries( example.inserter.integers
    FastFormat
)
add_custom_target( examples DEPENDS example.inserter.integers )

