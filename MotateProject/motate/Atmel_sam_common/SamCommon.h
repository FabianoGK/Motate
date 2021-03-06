/*
 utility/SamCommon.h - Library for the Motate system
 http://github.com/synthetos/motate/

 Copyright (c) 2013 - 2018 Robert Giseburt

 This file is part of the Motate Library.

 This file ("the software") is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License, version 2 as published by the
 Free Software Foundation. You should have received a copy of the GNU General Public
 License, version 2 along with the software. If not, see <http://www.gnu.org/licenses/>.

 As a special exception, you may use this file as part of a software library without
 restriction. Specifically, if other files instantiate templates or use macros or
 inline functions from this file, or you compile this file and link it with  other
 files to produce an executable, this file does not by itself cause the resulting
 executable to be covered by the GNU General Public License. This exception does not
 however invalidate any other reasons why the executable file might be covered by the
 GNU General Public License.

 THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef SAMCOMMON_H_ONCE
#define SAMCOMMON_H_ONCE

#include "sam.h"

namespace Motate {

// HERE we do a stupid anti-#define dance, since these defines screw EVERYTHING up
// Also note that we are defining global (inside the Motate namespace) variables
// from a .h file, so they must be (in order of most-preferred to least-preferred):
// constexpr, static, don't, DO NOT, please don't, a define

struct SamCommon {
    static inline void sync() { __DMB(); };

    static void enablePeripheralClock(uint32_t peripheralId) {
        if (peripheralId < 32) {
            uint32_t id_mask = 1u << (peripheralId);
            if ((PMC->PMC_PCSR0 & id_mask) != id_mask) {
                PMC->PMC_PCER0 = id_mask;
            }
#if (SAM3S || SAM3XA || SAM4S || SAM4E || SAM4C || SAM4CM || SAM4CP || SAMG55 || SAMV71 || SAMV70 || SAME70 || SAMS70)
        } else {
            uint32_t id_mask = 1u << (peripheralId - 32);
            if ((PMC->PMC_PCSR1 & id_mask) != id_mask) {
                PMC->PMC_PCER1 = id_mask;
            }
#endif
        }
    };

    static void disablePeripheralClock(uint32_t peripheralId) {
        if (peripheralId < 32) {
            uint32_t id_mask = 1u << (peripheralId);
            if ((PMC->PMC_PCSR0 & id_mask) == id_mask) {
                PMC->PMC_PCDR0 = id_mask;
            }
#if (SAM3S || SAM3XA || SAM4S || SAM4E || SAM4C || SAM4CM || SAM4CP || SAMG55 || SAMV71 || SAMV70 || SAME70 || SAMS70)
        } else {
            uint32_t id_mask = 1u << (peripheralId - 32);
            if ((PMC->PMC_PCSR1 & id_mask) == id_mask) {
                PMC->PMC_PCDR1 = id_mask;
            }
#endif
        }
    };

    static uint32_t getPeripheralClockFreq() {
#if (SAM4E || SAMV71 || SAMV70 || SAME70 || SAMS70)
        return SystemCoreClock >> ((PMC->PMC_MCKR & PMC_MCKR_PRES_Msk) >> PMC_MCKR_PRES_Pos);
#else
        return SystemCoreClock;
#endif
    };

    struct InterruptDisabler {
        volatile uint32_t flags;
        InterruptDisabler() : flags{__get_PRIMASK()} {
            __disable_irq();
            sync();
        };
        ~InterruptDisabler() {
            sync();
            __enable_irq();
         };
    };
};

}  // namespace Motate

#endif /* end of include guard: SAMCOMMON_H_ONCE */
