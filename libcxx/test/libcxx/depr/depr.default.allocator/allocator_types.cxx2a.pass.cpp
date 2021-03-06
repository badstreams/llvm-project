//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// check nested types:

// template <class T>
// class allocator
// {
// public:
//     typedef size_t                                size_type;
//     typedef ptrdiff_t                             difference_type;
//     typedef T*                                    pointer;
//     typedef const T*                              const_pointer;
//     typedef typename add_lvalue_reference<T>::type       reference;
//     typedef typename add_lvalue_reference<const T>::type const_reference;
//
//     template <class U> struct rebind {typedef allocator<U> other;};
// ...
// };

// MODULES_DEFINES: _LIBCPP_ENABLE_CXX20_REMOVED_ALLOCATOR_MEMBERS
// MODULES_DEFINES: _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#define _LIBCPP_ENABLE_CXX20_REMOVED_ALLOCATOR_MEMBERS
#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS

#include <memory>
#include <type_traits>
#include <cstddef>

#include "test_macros.h"

int main(int, char**)
{
    static_assert((std::is_same<std::allocator<char>::size_type, std::size_t>::value), "");
    static_assert((std::is_same<std::allocator<char>::difference_type, std::ptrdiff_t>::value), "");
    static_assert((std::is_same<std::allocator<char>::pointer, char*>::value), "");
    static_assert((std::is_same<std::allocator<char>::const_pointer, const char*>::value), "");
    static_assert((std::is_same<std::allocator<char>::reference, char&>::value), "");
    static_assert((std::is_same<std::allocator<char>::const_reference, const char&>::value), "");
    static_assert((std::is_same<std::allocator<char>::rebind<int>::other,
                                std::allocator<int> >::value), "");

  return 0;
}
