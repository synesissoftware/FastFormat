add_executable( example.pad.hash example.pad.hash.cpp )
target_link_libraries( example.pad.hash
    FastFormat
)
add_custom_target( examples DEPENDS example.pad.hash )

