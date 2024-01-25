include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  add_executable( test.scratch.sink.WindowsMessageBox test.scratch.sink.WindowsMessageBox.cpp )
  target_link_libraries( test.scratch.sink.WindowsMessageBox
      api
      fmt_cache
      fmt_spec_defect_handlers
      init_code_strings
      memory_pool
      replacements
      snprintf
      xTests::xTests
  )
  add_test( test.scratch.sink.WindowsMessageBox test.scratch.sink.WindowsMessageBox )
  add_custom_target( tests DEPENDS test.scratch.sink.WindowsMessageBox )
endif( WIN32 )

