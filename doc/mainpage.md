# FastFormat {#mainpage}

**FastFormat** is an extremely fast, 100% type-safe, infinitely-extensible,
I18N/L10N-friendly C++ output/formatting library.


## Components

| Module | Header | Summary |
| ------ | ------ | ------- |
| \ref group__core_library | `<fastformat/fastformat.h>` | Core formatting API |
| \ref group__application_layer | `<fastformat/fastformat.hpp>` | Application-layer API |
| \ref group__interface_functions | `<fastformat/fastformat.hpp>` | Format and Write interface functions |
| \ref group__init | `<fastformat/fastformat.h>` | Library initialisation |
| \ref group__format_specification_defect_handling | `<fastformat/fastformat.h>` | Ill-formed / mismatched argument handling |
| \ref group__utility | `<fastformat/fastformat.h>` | Utility helpers |
| Inserters | `<fastformat/inserters/*.hpp>` | Typed inserters (`to_i`, `to_x`, `real`, …) |
| Sinks | `<fastformat/sinks/*.hpp>` | Output sinks (`ostream`, `FILE`, …) |


## Quick start

```cpp
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

#include <iostream>

int main()
{
    fastformat::fmtln(std::cout, "Hello, {0}!", "World");

    return 0;
}
```

Consumer **CMake** projects may use `find_package(FastFormat)` and link the
exported targets. See
[INSTALL.md](https://github.com/synesissoftware/FastFormat/blob/master/INSTALL.md)
for build and install instructions.


## Related projects

* [STLSoft](https://github.com/synesissoftware/STLSoft/) — required dependency
* [shwild](https://github.com/synesissoftware/shwild) — optional, for enhanced **xTests** matching
* [xTests](https://github.com/synesissoftware/xTests) — test harness


<!-- ########################### end of file ########################### -->
