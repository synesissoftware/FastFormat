add_executable( example.overload.2.custom_type.string_access_shims example.overload.2.custom_type.string_access_shims.cpp )
target_link_libraries( example.overload.2.custom_type.string_access_shims
    FastFormat
)
add_custom_target( examples DEPENDS example.overload.2.custom_type.string_access_shims )

