if( ATOMIC_INTEGER_OPERATIONS )
add_executable( example.memory.1 example.memory.1.cpp )
target_link_libraries( example.memory.1
    FastFormat
)
add_custom_target( examples DEPENDS example.memory.1 )
endif( ATOMIC_INTEGER_OPERATIONS )

