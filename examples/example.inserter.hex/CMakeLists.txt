add_executable( example.inserter.hex example.inserter.hex.cpp )
target_link_libraries( example.inserter.hex
    FastFormat
)
add_custom_target( examples DEPENDS example.inserter.hex )

