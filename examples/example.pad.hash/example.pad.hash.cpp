
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

#include <iostream>
#include <string>

int main()
{
    // Write empty string to pad

    ff::fmtln(std::cout, "padding empty string to 10, with space: [{0,10}]", "");
    ff::fmtln(std::cout, "padding empty string to 10, with hash:  [{0,10,,<#}]", "");

    // Write non-empty string to pad of various lengths

    { for(size_t i = 1; i != 32; i *= 2)
    {
        std::string format_space;
        std::string format_hash;

        // Use ff::write to create format strings, e.g.
        //
        // "padding string to 10 with space: [{0,10,,< }]"
        // "padding string to 10 with space: [{0,10,,<#}]"

        ff::write(format_space, "padding string to ", i, ", with space: [{0,", i, ",,< }]");
        ff::write(format_hash,  "padding string to ", i, ", with hash:  [{0,", i, ",,<#}]");

        ff::fmtln(std::cout, format_space, "abc");
        ff::fmtln(std::cout, format_hash, "abc");
    }}

    return 0;
}
