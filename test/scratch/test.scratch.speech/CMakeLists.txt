include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${shwild_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  if( shwild_FOUND )
    add_executable( test.scratch.speech test.scratch.speech.cpp )
    target_link_libraries( test.scratch.speech
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
    add_test( test.scratch.speech test.scratch.speech )
    add_custom_target( tests DEPENDS test.scratch.speech )
  else( shwild_FOUND )
    message(AUTHOR_WARNING "The shwild library not found. Cannot build test test.scratch.speech.")
  endif( shwild_FOUND )
endif( WIN32 )

