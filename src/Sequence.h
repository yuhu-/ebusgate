/*
 * Copyright (C) Roland Jax 2012-2019 <roland.jax@liwest.at>
 *
 * This file is part of ebus.
 *
 * ebus is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ebus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ebus. If not, see http://www.gnu.org/licenses/.
 */

#ifndef EBUS_SEQUENCE_H
#define EBUS_SEQUENCE_H

#include <cstddef>
#include <string>
#include <vector>

namespace ebus
{

static const std::byte seq_zero = std::byte(0x00);     // zero byte

static const std::byte seq_syn = std::byte(0xaa);      // synchronization byte
static const std::byte seq_exp = std::byte(0xa9);      // expand byte
static const std::byte seq_synexp = std::byte(0x01);   // expanded synchronization byte
static const std::byte seq_expexp = std::byte(0x00);   // expanded expand byte

class Sequence
{

public:
	static const size_t npos = -1;

	Sequence() = default;
	Sequence(const Sequence &seq, const size_t index, size_t len = 0);

	void assign(const std::vector<std::byte> &vec, const bool extended = true);

	void push_back(const std::byte byte, const bool extended = true);

	const std::byte& operator[](const size_t index) const;
	const std::vector<std::byte> range(const size_t index, const size_t len);

	size_t size() const;

	void clear();

	std::byte crc();

	void extend();
	void reduce();

	const std::string to_string() const;
	const std::vector<std::byte> get_sequence() const;

	static const std::vector<std::byte> range(const std::vector<std::byte> &seq, const size_t index, const size_t len);

private:
	std::vector<std::byte> m_seq;

	bool m_extended = false;

	std::byte calc_crc(const std::byte byte, const std::byte init);
};

} // namespace ebus

#endif // EBUS_SEQUENCE_H

