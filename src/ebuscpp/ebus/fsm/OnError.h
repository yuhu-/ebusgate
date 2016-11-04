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

#ifndef EBUS_FSM_ONERROR_H
#define EBUS_FSM_ONERROR_H

#include "State.h"

class OnError : public State
{

public:
	static OnError* getOnError()
	{
		return (&m_onError);
	}

	int run(EbusFSM* fsm);
	const string toString() const;

private:
	static OnError m_onError;

};

#endif // EBUS_FSM_ONERROR_H