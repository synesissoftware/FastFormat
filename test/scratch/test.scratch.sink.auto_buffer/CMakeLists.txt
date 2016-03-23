include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
  ${shwild_INCLUDE_DIRS}
)

if( shwild_FOUND )
  add_executable( test.scratch.sink.auto_buffer test.scratch.sink.auto_buffer.cpp )
  target_link_libraries( test.scratch.sink.auto_buffer
      api
      fmt_cache
      fmt_spec_defect_handlers
      init_code_strings
      memory_pool
      replacements
      snprintf
      shwild::shwild
      xTests::xTests
  )
  add_test( test.scratch.sink.auto_buffer test.scratch.sink.auto_buffer )
  add_custom_target( tests DEPENDS test.scratch.sink.auto_buffer )
else( shwild_FOUND )
  message(AUTHOR_WARNING "The shwild library not found. Cannot build test test.scratch.sink.auto.")
endif( shwild_FOUND )

