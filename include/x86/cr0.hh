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
#ifndef X86_CR0_HH
#define X86_CR0_HH

#include <cassert>
#include <cstdint>

namespace x86 {

class cr0 {
public:
	uint32_t value;

	cr0(uint32_t value = 0):
		value(value)
	{
	}

	~cr0()
	{
	}

	static inline cr0 read()
	{
		cr0 x;
		asm volatile ("movl %%cr0, %0"
			: "=r" (x.value));
		return x;
	}

	static inline void write(cr0 x)
	{
		asm volatile ("movl %0, %%cr0"
			:
			: "r" (x.value));
	}

private:
	template<unsigned int i, unsigned int n = 1>
	uint32_t read() const
	{
		return (value >> i) & ((1 << n) - 1);
	}

	template<unsigned int i, unsigned int n = 1>
	cr0 &write(uint32_t x)
	{
		assert((x & ~((1 << n) - 1)) == 0);

		value &= ~(((1 << n) - 1) << i);
		value |= x << i;
		return *this;
	}

public:
	bool protection_enable() const
	{
		return read<0>();
	}

	cr0 &protection_enable(bool x)
	{
		return write<0>(x);
	}

	bool monitor_coprocessor() const
	{
		return read<1>();
	}

	cr0 &monitor_coprocessor(bool x)
	{
		return write<1>(x);
	}

	bool emulation() const
	{
		return read<2>();
	}

	cr0 &emulation(bool x)
	{
		return write<2>(x);
	}

	bool task_switched() const
	{
		return read<3>();
	}

	cr0 &task_switched(bool x)
	{
		return write<3>(x);
	}

	bool extension_type() const
	{
		return read<4>();
	}

	cr0 &extension_type(bool x)
	{
		return write<4>(x);
	}

	bool numeric_error() const
	{
		return read<5>();
	}

	cr0 &numeric_error(bool x)
	{
		return write<5>(x);
	}

	bool write_protect() const
	{
		return read<16>();
	}

	cr0 &write_protect(bool x)
	{
		return write<16>(x);
	}

	bool alignment_mask() const
	{
		return read<18>();
	}

	cr0 &alignment_mask(bool x)
	{
		return write<18>(x);
	}

	bool not_writethrough() const
	{
		return read<29>();
	}

	cr0 &not_writethrough(bool x)
	{
		return write<29>(x);
	}

	bool cache_disable() const
	{
		return read<30>();
	}

	cr0 &cache_disable(bool x)
	{
		return write<30>(x);
	}

	bool paging() const
	{
		return read<31>();
	}

	cr0 &paging(bool x)
	{
		return write<31>(x);
	}
};

}

#endif
