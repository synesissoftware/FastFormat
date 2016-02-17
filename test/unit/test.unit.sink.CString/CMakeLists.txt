include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  add_executable( test.unit.sink.CString test.unit.sink.CString.cpp )
  target_link_libraries( test.unit.sink.CString
      api
      fmt_cache
      fmt_spec_defect_handlers
      init_code_strings
      memory_pool
      replacements
      snprintf
      xTests::xTests
  )
  add_test( test.unit.sink.CString test.unit.sink.CString )
  add_custom_target( tests DEPENDS test.unit.sink.CString )
endif( WIN32 )

