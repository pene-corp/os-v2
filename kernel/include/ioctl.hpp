//=======================================================================
// Copyright Aiden Lang 2020-2023
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#ifndef IOCTL_HPP
#define IOCTL_HPP

#include <types.hpp>
#include <expected.hpp>

#include <tlib/ioctl_codes.hpp>

std::expected<size_t> ioctl(size_t device_fd, io::ioctl_request request, void* data);

#endif
