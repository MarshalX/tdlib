cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0076 NEW)

project(tdlib_native
    LANGUAGES C CXX
    DESCRIPTION "A cross-platform library for building Telegram clients with Python"
    HOMEPAGE_URL "https://github.com/MarshalX/tdlib"
    VERSION "0.0.1"
)

get_filename_component(src_loc "src/native" REALPATH)
get_filename_component(third_party_loc "third_party" REALPATH)

if (APPLE)
    set(OPENSSL_ROOT_DIR "/opt/homebrew/opt/openssl@1.1")
endif (APPLE)

configure_file("${src_loc}/config.h.in" "${src_loc}/config.h")

add_subdirectory(${third_party_loc}/td)
add_subdirectory(${third_party_loc}/pybind11)

list(APPEND SOURCES
    ${src_loc}/config.h
    ${src_loc}/tdlib_native.cpp
)

pybind11_add_module(tdlib_native ${SOURCES})

target_link_libraries(tdlib_native
PRIVATE
    Td::TdStatic
)
