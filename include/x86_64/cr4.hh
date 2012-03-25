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
#ifndef X86_64_CR4_HH
#define X86_64_CR4_HH

#include <cassert>
#include <cstdint>

namespace x86_64 {

class cr4 {
public:
	uint64_t value;

	cr4(uint64_t value = 0):
		value(value)
	{
	}

	~cr4()
	{
	}

	static inline cr4 read()
	{
		cr4 x;
		asm volatile ("movq %%cr4, %0"
			: "=r" (x.value));
		return x;
	}

	static inline void write(cr4 x)
	{
		asm volatile ("movq %0, %%cr4"
			:
			: "r" (x.value));
	}

private:
	template<unsigned int i, unsigned int n = 1>
	uint64_t read() const
	{
		return (value >> i) & ((1 << n) - 1);
	}

	template<unsigned int i, unsigned int n = 1>
	cr4 &write(uint64_t x)
	{
		assert((x & ~((1 << n) - 1)) == 0);

		value &= ~(((1 << n) - 1) << i);
		value |= x << i;
		return *this;
	}

public:
	bool virtual_8086_mode_extensions() const
	{
		return read<0>();
	}

	cr4 &virtual_8086_mode_extensions(bool x)
	{
		return write<0>(x);
	}

	bool protected_mode_virtual_interrupts() const
	{
		return read<1>();
	}

	cr4 &protected_mode_virtual_interrupts(bool x)
	{
		return write<1>(x);
	}

	bool time_stamp_disable() const
	{
		return read<2>();
	}

	cr4 &time_stamp_disable(bool x)
	{
		return write<2>(x);
	}

	bool debugging_extensions() const
	{
		return read<3>();
	}

	cr4 &debugging_extensions(bool x)
	{
		return write<3>(x);
	}

	bool page_size_extensions() const
	{
		return read<4>();
	}

	cr4 &page_size_extensions(bool x)
	{
		return write<4>(x);
	}

	bool physical_address_extension() const
	{
		return read<5>();
	}

	cr4 &physical_address_extension(bool x)
	{
		return write<5>(x);
	}

	bool machine_check_enable() const
	{
		return read<6>();
	}

	cr4 &machine_check_enable(bool x)
	{
		return write<6>(x);
	}

	bool page_global_enable() const
	{
		return read<7>();
	}

	cr4 &page_global_enable(bool x)
	{
		return write<7>(x);
	}

	bool performance_monitoring_counter_enable() const
	{
		return read<8>();
	}

	cr4 &performance_monitoring_counter_enable(bool x)
	{
		return write<8>(x);
	}

	bool osfxsr() const
	{
		return read<9>();
	}

	cr4 &osfxsr(bool x)
	{
		return write<9>(x);
	}

	bool osxmmexcpt() const
	{
		return read<10>();
	}

	cr4 &osxmmexcpt(bool x)
	{
		return write<10>(x);
	}

	bool vmx_enable() const
	{
		return read<13>();
	}

	cr4 &vmx_enable(bool x)
	{
		return write<13>(x);
	}

	bool smx_enable() const
	{
		return read<14>();
	}

	cr4 &smx_enable(bool x)
	{
		return write<14>(x);
	}

	bool fsgsbase_enable() const
	{
		return read<16>();
	}

	cr4 &fsgsbase_enable(bool x)
	{
		return write<16>(x);
	}

	bool pcid_enable() const
	{
		return read<17>();
	}

	cr4 &pcid_enable(bool x)
	{
		return write<17>(x);
	}

	bool osxsave() const
	{
		return read<18>();
	}

	cr4 &osxsave(bool x)
	{
		return write<18>(x);
	}

	bool smep_enable() const
	{
		return read<20>();
	}

	cr4 &smep_enable(bool x)
	{
		return write<20>(x);
	}
};

}

#endif
