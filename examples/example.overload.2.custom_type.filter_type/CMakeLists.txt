add_executable( example.overload.2.custom_type.filter_type example.overload.2.custom_type.filter_type.cpp )
target_link_libraries( example.overload.2.custom_type.filter_type
    FastFormat
)
add_custom_target( examples DEPENDS example.overload.2.custom_type.filter_type )

