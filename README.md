## tdlib
A cross-platform library for building Telegram clients with Python 😎

## Current progress

Working on generator of binding classes using pybind11.

## Issues

For now there are many critical problems... Short descriptions
- `Symbol not found: __lololo` when try to bind non-abstract classes. 
  For example `contact` or `accountTtl`. Maybe problems with pointers. 
  I already tried to use tdlib's smart pointer with pybind11. 
  There is no way to bind templates from C++ to Python.
- `.def_readwrite` doesn't work properly with nested objects.
  Again issue can be in templated `array` (just a vector) or `object_ptr`.

**You are welcome to help me with resolving this issues!**

## The roadmap in my dreams

- Generate Python binding to all classes and functions from td_api scheme.
- Add binding for `Client`, `ClientManager` and so on...
- Generate Python wrappers for already generated native classes (docs, typehints).
- Generate `.rts` files for Sphinx docs.
- Provide wrapper and helper classes for `Client` to send request to tdlib sync/asynchronously.
- Generate exceptions.
- Provide some high level methods.
