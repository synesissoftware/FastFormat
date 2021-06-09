add_executable( example.overload.3.server_log example.overload.3.server_log.cpp )
target_link_libraries( example.overload.3.server_log
    FastFormat
)
add_custom_target( examples DEPENDS example.overload.3.server_log )

