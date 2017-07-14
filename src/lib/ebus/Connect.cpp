/*
 * Copyright (C) Roland Jax 2012-2017 <roland.jax@liwest.at>
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

#include "Connect.h"
#include "Idle.h"
#include "Listen.h"

#include <sstream>

using std::ostringstream;

libebus::Connect libebus::Connect::m_connect;

int libebus::Connect::run(EbusFSM* fsm)
{
	int result = DEV_OK;
	unsigned char byte = 0;

	if (fsm->m_ebusDevice->isOpen() == false)
	{
		result = fsm->m_ebusDevice->open();

		if (fsm->m_ebusDevice->isOpen() == false || result != DEV_OK)
		{
			m_reopenTime++;
			if (m_reopenTime > fsm->m_reopenTime) fsm->changeState(Idle::getIdle());

			return (result);
		}
	}

	fsm->logInfo(stateMessage(STATE_INF_EBUS_ON));

	do
	{
		int result = read(fsm, byte, 1, 0);
		if (result != DEV_OK) return (result);
	} while (byte != SYN);

	reset(fsm);

	fsm->logInfo(stateMessage(STATE_INF_DEV_FLUSH));

	fsm->changeState(Listen::getListen());
	return (result);
}

const string libebus::Connect::toString() const
{
	return ("Connect");
}
