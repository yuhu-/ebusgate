/*
 * Copyright (C) Roland Jax 2012-2016 <roland.jax@liwest.at>
 *
 * This file is part of ebuscpp.
 *
 * ebuscpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ebuscpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ebuscpp. If not, see http://www.gnu.org/licenses/.
 */

#ifndef PROCESS_FORWARD_FILTER_H
#define PROCESS_FORWARD_FILTER_H

#include "Sequence.h"

class Filter
{

public:
	explicit Filter(const Sequence& seq);

	int getID() const;
	Sequence getFilter() const;

	bool equal(const Sequence& seq);
	bool match(const Sequence& seq);

	const string toString();

private:
	static int uniqueID;

	int m_id;
	Sequence m_seq;

};

#endif // PROCESS_FORWARD_FILTER_H
