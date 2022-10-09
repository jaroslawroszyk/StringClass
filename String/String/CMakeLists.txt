set(MODULE_NAME String)

set(SOURCES
        src/String.cpp
)

set(HEADERS
        include/String.hpp
        )

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS}) 
add_library(str::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include)
target_link_libraries(${MODULE_NAME}
    PUBLIC
        fmt::fmt
        str::StringCapacity
        str::StringElementAccess
        str::StringMember
        str::Utilities
    PRIVATE
)

add_subdirectory(ut)
