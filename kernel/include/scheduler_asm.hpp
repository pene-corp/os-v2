//=======================================================================
// Copyright Aiden Lang 2020-2023
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#ifndef SCHEDULER_H
#define SCHEDULER_H

extern "C" {

uint64_t get_context_address(size_t pid);
uint64_t get_process_cr3(size_t pid);

} //end of extern "C"

#endif
