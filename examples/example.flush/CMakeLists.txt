add_executable( example.flush example.flush.cpp )
target_link_libraries( example.flush
    FastFormat
)
add_custom_target( examples DEPENDS example.flush )

