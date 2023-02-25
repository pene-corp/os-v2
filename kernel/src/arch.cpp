//=======================================================================
// Copyright Aiden Lang 2020-2023
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#include "arch.hpp"

extern "C" {

void _arch_enable_sse();

} //end of extern "C"

void arch::enable_sse(){
    _arch_enable_sse();
}
