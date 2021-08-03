cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0076 NEW)

project(tdlib
    LANGUAGES C CXX
    DESCRIPTION "A cross-platform library for building Telegram clients with Python"
    HOMEPAGE_URL "https://github.com/MarshalX/tdlib"
    VERSION "0.0.1"
)

get_filename_component(src_loc "src/native" REALPATH)
get_filename_component(third_party_loc "third_party" REALPATH)

configure_file("${src_loc}/config.h.in" "${src_loc}/config.h")

list(APPEND SOURCES
    ${src_loc}/config.h
    ${src_loc}/tdlib.cpp
)

add_subdirectory(${third_party_loc}/pybind11)
pybind11_add_module(tdlib_native ${SOURCES})

if (APPLE)
    set(OPENSSL_ROOT_DIR "/opt/homebrew/opt/openssl@1.1")
endif (APPLE)

add_subdirectory(${third_party_loc}/td)

target_link_libraries(tdlib_native
PRIVATE
    Td::TdStatic
)
