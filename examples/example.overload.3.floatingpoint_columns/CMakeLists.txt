add_executable( example.overload.3.floatingpoint_columns example.overload.3.floatingpoint_columns.cpp )
target_link_libraries( example.overload.3.floatingpoint_columns
    FastFormat
)
add_custom_target( examples DEPENDS example.overload.3.floatingpoint_columns )

