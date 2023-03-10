//=======================================================================
// Copyright Aiden Lang 2020-2023
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#ifndef ACPI_HPP
#define ACPI_HPP

namespace acpi {

void init();
bool initialized();

void shutdown();
bool reboot();

} //end of acpi namespace

#endif
