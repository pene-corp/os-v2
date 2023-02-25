//=======================================================================
// Copyright Aiden Lang 2020-2023
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#include <tlib/system.hpp>

volatile int a = 0;

int main(int /*argc*/, char* /*argv*/[]){
    a = 42 / a;

    return a;
}
