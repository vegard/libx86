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
#ifndef X86_EFLAGS_HH
#define X86_EFLAGS_HH

#include <cassert>
#include <cstdint>

namespace x86 {

class eflags {
public:
	uint32_t value;

	eflags(uint32_t value = 0):
		value(value)
	{
	}

	~eflags()
	{
	}

private:
	template<unsigned int i, unsigned int n = 1>
	uint32_t read() const
	{
		return (value >> i) & ((1 << n) - 1);
	}

	template<unsigned int i, unsigned int n = 1>
	eflags &write(uint32_t x)
	{
		assert((x & ~((1 << n) - 1)) == 0);

		value &= ~(((1 << n) - 1) << i);
		value |= x << i;
		return *this;
	}

public:
	bool carry_flag() const
	{
		return read<0>();
	}

	eflags &carry_flag(bool x)
	{
		return write<0>(x);
	}

	bool parity_flag() const
	{
		return read<2>();
	}

	eflags &parity_flag(bool x)
	{
		return write<2>(x);
	}

	bool auxiliary_carry_flag() const
	{
		return read<4>();
	}

	eflags &auxiliary_carry_flag(bool x)
	{
		return write<4>(x);
	}

	bool zero_flag() const
	{
		return read<6>();
	}

	eflags &zero_flag(bool x)
	{
		return write<6>(x);
	}

	bool sign_flag() const
	{
		return read<7>();
	}

	eflags &sign_flag(bool x)
	{
		return write<7>(x);
	}

	bool trap_flag() const
	{
		return read<8>();
	}

	eflags &trap_flag(bool x)
	{
		return write<8>(x);
	}

	bool interrupt_enable_flag() const
	{
		return read<9>();
	}

	eflags &interrupt_enable_flag(bool x)
	{
		return write<9>(x);
	}

	bool direction_flag() const
	{
		return read<10>();
	}

	eflags &direction_flag(bool x)
	{
		return write<10>(x);
	}

	bool overflow_flag() const
	{
		return read<11>();
	}

	eflags &overflow_flag(bool x)
	{
		return write<11>(x);
	}

	uint8_t io_privilege_level() const
	{
		return read<12, 2>();
	}

	eflags &io_privilege_level(uint8_t x)
	{
		return write<12, 2>(x);
	}

	bool nested_task() const
	{
		return read<14>();
	}

	eflags &nested_task(uint8_t x)
	{
		return write<14>(x);
	}

	bool resume_flag() const
	{
		return read<16>();
	}

	eflags &resume_flag(bool x)
	{
		return write<16>(x);
	}

	bool virtual_8086_mode() const
	{
		return read<17>();
	}

	eflags &virtual_8086_mode(bool x)
	{
		return write<17>(x);
	}

	bool alignment_check() const
	{
		return read<18>();
	}

	eflags &alignment_check(bool x)
	{
		return write<18>(x);
	}

	bool virtual_interrupt_flag() const
	{
		return read<19>();
	}

	eflags &virtual_interrupt_flag(bool x)
	{
		return write<19>(x);
	}

	bool virtual_interrupt_pending() const
	{
		return read<20>();
	}

	eflags &virtual_interrupt_pending(bool x)
	{
		return write<20>(x);
	}

	bool id_flag() const
	{
		return read<21>();
	}

	eflags &id_flag(bool x)
	{
		return write<21>(x);
	}
};

}

#endif
