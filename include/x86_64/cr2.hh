/*
 * libx86
 * Copyright (C) 2012  Vegard Nossum <vegardno@ifi.uio.no>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef X86_64_CR2_HH
#define X86_64_CR2_HH

#include <cassert>
#include <cstdint>

namespace x86_64 {

class cr2 {
public:
	uint64_t value;

	cr2(uint64_t value = 0):
		value(value)
	{
	}

	~cr2()
	{
	}

	static inline cr2 read()
	{
		cr2 x;
		asm volatile ("movq %%cr2, %0"
			: "=r" (x.value));
		return x;
	}

	static inline void write(cr2 x)
	{
		asm volatile ("movq %0, %%cr2"
			:
			: "r" (x.value));
	}
};

}

#endif
