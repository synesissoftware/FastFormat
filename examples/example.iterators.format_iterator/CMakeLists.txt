add_executable( example.iterators.format_iterator example.iterators.format_iterator.cpp )
target_link_libraries( example.iterators.format_iterator
    FastFormat
)
add_custom_target( examples DEPENDS example.iterators.format_iterator )

