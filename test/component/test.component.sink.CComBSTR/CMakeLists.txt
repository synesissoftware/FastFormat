include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  add_executable( test.component.sink.CComBSTR test.component.sink.CComBSTR.cpp )
  target_link_libraries( test.component.sink.CComBSTR
      api
      fmt_cache
      fmt_spec_defect_handlers
      init_code_strings
      memory_pool
      replacements
      snprintf
      xTests::xTests
  )
  add_test( test.component.sink.CComBSTR test.component.sink.CComBSTR )
  add_custom_target( tests DEPENDS test.component.sink.CComBSTR )
endif( WIN32 )

