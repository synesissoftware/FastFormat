add_executable( example.overload.3.record_insert example.overload.3.record_insert.cpp )
target_link_libraries( example.overload.3.record_insert
    FastFormat
)
add_custom_target( examples DEPENDS example.overload.3.record_insert )

