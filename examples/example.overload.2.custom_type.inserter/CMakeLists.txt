add_executable( example.overload.2.custom_type.inserter example.overload.2.custom_type.inserter.cpp )
target_link_libraries( example.overload.2.custom_type.inserter
    FastFormat
)
add_custom_target( examples DEPENDS example.overload.2.custom_type.inserter )

