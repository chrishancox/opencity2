/***************************************************************************
						agentpolice.cpp  -  description
							-------------------
	begin                : nov 29th 2005
	copyright            : (C) 2005-2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com
	author               : Victor STINNER

	$Id: agentpolice.cpp 375 2008-10-28 14:47:15Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

// Useful enumeration
#include "opencity_direction.h"

// MAS headers
#include "agentpolice.h"
#include "kernel.h"
#include "environment.h"
#include "message.h"

// OpenCity header
#include "destination.h"

// Standard header
#include <cstdlib>

// The max square distance for collaboration
#define MAX_DISTANCE 200
#define MAX_PERCEPTION_RANGE 10


   /*=====================================================================*/
AgentPolice::AgentPolice
(
	Kernel& kernel,
	Environment& env,
	int x, int y
):
Agent(kernel, env, x, y, ROLE_POLICE),
m_state( POLICE_LOOK )
{
	m_sleep = 3;
	SetState( POLICE_LOOK );

	this->born();		// Warning: see superclass

// OpenCity's specifics
	this->SetGraphicCode( OC_VEHICLE_POLICE );
}


   /*=====================================================================*/
AgentPolice::~AgentPolice()
{
	if (m_agent_state != AGENT_DIE)
		this->die();		// Warning: see superclass
}


   /*=====================================================================*/
Agent*
AgentPolice::SeeBadGuy( MAS_DIRECTION dir )
{
	Agent* agent = lookForAgent(dir, MAX_PERCEPTION_RANGE);
	if (agent == NULL)
		return agent;
	if (agent->getRole() == ROLE_POLICE)
		return NULL;
	return agent;
}


   /*=====================================================================*/
void AgentPolice::SetState(police_state_t state)
{
	m_index = 0;
	m_path.clear();

	if (state == m_state) return;

	m_state = state;
	switch(m_state)
	{
		case POLICE_COLLABORATE:
			break;
		case POLICE_PURSUE:
			m_pursue = 0;
			break;
		case POLICE_LOST_PURSUE:
			m_lost_pursue = 0;
			break;
		default:
			break;
	}
}


   /*=====================================================================*/
void
AgentPolice::Look()
{
	MAS_DEBUG( "(look)" );

	Agent* agent = FindBadGuy();
	if (agent == NULL) {
		randomMove();
		return;
	}
    MAS_DEBUG( "Look -> Pursue agent " << agent->getId() );

	moveDirection();
	NoticePursue(agent);
	SetState(POLICE_PURSUE);
}


   /*=====================================================================*/
void
AgentPolice::NoticePursue(Agent *agent)
{
// Create a new alert message for other police agents
	MAS_MESSAGE_TYPE msgt = MSG_UNDEFINED;
	switch (agent->getRole()) {
		case ROLE_DEMONSTRATOR:
			msgt = MSG_NEW_DEMONSTRATOR;
			break;

		case ROLE_ROBBER:
			msgt = MSG_NEW_ROBBER;
			break;

		default:					// Keep GCC happy
			break;
	}
	Message msg = Message(msgt, this) << agent->getX() << agent->getY();
	m_kernel.sendMessage( ROLE_POLICE, msg );
}



   /*=====================================================================*/
Agent*
AgentPolice::IsNearBadGuy()
{
	Agent* agent = m_environment.getAgentAt(m_x-1, m_y);

	if (agent != NULL)
		return agent;

	agent = m_environment.getAgentAt(m_x+1, m_y);
	if (agent != NULL)
		return agent;

	agent = m_environment.getAgentAt(m_x, m_y-1);
	if (agent != NULL)
		return agent;

	agent = m_environment.getAgentAt(m_x, m_y+1);
	if (agent != NULL)
		return agent;

	return NULL;
}

   /*=====================================================================*/
void AgentPolice::Pursue()
{
	moveDirection();
	Agent* agent = SeeBadGuy(m_direction);

	if (agent != NULL) {
		MAS_DEBUG( *this << "(is pursuing agent " << agent->getId() << ")" );
		m_lost_pursue = 0;

		// Notice pursue if needed
		m_pursue++;
		if (1<m_pursue and (m_pursue % 5) == 0)
		{
			NoticePursue(agent);
		}
		return;
	}

	agent = FindBadGuy(false);
	if (agent == NULL) {
		MAS_DEBUG( "Pursue -> Lost pursue" );

		SetState(POLICE_LOST_PURSUE);
    }
}


   /*=====================================================================*/
Agent*
AgentPolice::FindBadGuy(bool test_backward)
{
	Agent* agent = SeeBadGuy(m_direction);
	if (agent != NULL)
		return agent;

	MAS_DIRECTION dir;
	unsigned char rotate = randomBool();
	if (rotate)
		dir = rotateLeft(m_direction);
	else
		dir = rotateRight(m_direction);
	agent = SeeBadGuy(dir);

	if (agent != NULL) {
		m_direction = dir;
		return agent;
	}

	if (rotate)
		dir = rotateRight(m_direction);
	else
		dir = rotateLeft(m_direction);
	agent = SeeBadGuy(dir);

	if (agent != NULL) {
		m_direction = dir;
		return agent;
	}

	if (test_backward) {
		dir = rotate180(m_direction);
		agent = SeeBadGuy(dir);
		if (agent != NULL) {
			m_direction = dir;
			return agent;
		}
	}

	return NULL;
}


   /*=====================================================================*/
void AgentPolice::LostPursue()
{
	MAS_DEBUG( "(did lost agent)" );

	Agent* agent = FindBadGuy();
	if (agent != NULL) {
		MAS_DEBUG( "Lost pursue -> Pursue " << agent->getId() );

		moveDirection();
		NoticePursue(agent);
		SetState(POLICE_PURSUE);
		return;
    }

	m_lost_pursue++;
	if (7 < m_lost_pursue) {
		MAS_DEBUG( "Lost pursue -> Look" );

		SetState(POLICE_LOOK);
    }
	randomMove(30);

	agent = FindBadGuy();
	if (agent != NULL) {
		MAS_DEBUG( "Lost pursue -> Pursue (after moving)" << agent->getId() );

		NoticePursue(agent);
		SetState(POLICE_PURSUE);
		return;
    }
}


   /*=====================================================================*/
void
AgentPolice::processMessage()
{
	static Message msg;

// Process all the messages
	while (!m_messages.empty()) {
		msg = m_messages.front();

		switch (msg.getType()) {
		case MSG_NEW_DEMONSTRATOR:
		// IF this is not our own message THEN
			if ((msg.getSender() != this) and (m_state == POLICE_LOST_PURSUE || m_state == POLICE_LOOK)) {
			// Check the square distance of the target
				unsigned int ax = msg[0].getUInt();
				unsigned int ay = msg[1].getUInt();

				if (Environment::toSquareDistance(m_x, m_y, ax, ay) > MAX_DISTANCE)
					break;

				m_environment.findShortestPath(m_x, m_y, ax, ay, m_path);
				if (m_path.size() > 1) {
					MAS_DEBUG( "-> Collaborate (path size=" << m_path.size() << ")" );

				// Avoid the first x, y which are equal to m_x, m_y
					m_index = 1;
					SetState(POLICE_COLLABORATE);
				}
				else {
					m_path.clear();
					m_index = 0;

					Agent* agent = FindBadGuy();
					if (agent == NULL)
						break;

					MAS_DEBUG( "(collaborate) Pursue agent " << agent->getId() );
					NoticePursue(agent);
					SetState(POLICE_PURSUE);
				}
			}
			break;

		case MSG_AGENT_DIE:
			m_agent_state = AGENT_DIE;
			break;

		default:
			MAS_DEBUG( "Received unknown message" );
		}

		m_messages.pop_front();
	} // while
}


   /*=====================================================================*/
void
AgentPolice::born()
{
	Agent::born();
	m_kernel.registerRole(this, ROLE_POLICE);
	m_agent_state = AGENT_LIVE;
}


   /*=====================================================================*/
void
AgentPolice::Collaborate()
{
	Agent* agent = IsNearBadGuy();

	if (agent != NULL) {
//        NoticePursue(agent);
		randomMove(-1);
		SetState(POLICE_PURSUE);
		return;
	}
	MAS_DEBUG( "(collaborate)" );

	followPath();
}


   /*=====================================================================*/
void
AgentPolice::live()
{
	if (m_agent_state != AGENT_LIVE)
		return;

	if (m_sleep != 0 and (m_kernel.getStep() % m_sleep) != 0)
		return;

	processMessage();

	switch (m_state) {
	case POLICE_LOOK:
		Look();
		break;

	case POLICE_PURSUE:
		Pursue();
		break;

	case POLICE_LOST_PURSUE:
		LostPursue();
		break;

	case POLICE_COLLABORATE:
		Collaborate();
		break;
	}
}


   /*=====================================================================*/
void
AgentPolice::die()
{
	processMessage();
	Agent::die();
	m_kernel.unregisterRole(this, this->getRole());
}


   /*=====================================================================*/
void
AgentPolice::output (std::ostream& os) const
{
	os << "AgentPolice " << getId();
}


   /*=====================================================================*/
   /*                        PRIVATE     METHODS                          */
   /*=====================================================================*/
void
AgentPolice::followPath()
{
	int x, y;
	bool ok = false;

   // move to the indicated direction
	if (m_path[m_index]._uiTime) {
		x = m_path[m_index]._uiW;
		y = m_path[m_index]._uiL;
		if (canMove(x, y) and move(x, y)) {
			ok = true;
		}
		else {
			m_index = 0;
			m_path.clear();

			Agent* agent = m_environment.getAgentAt(x,y);
			if (agent != NULL and agent->getRole() != ROLE_POLICE) {
				MAS_DEBUG( "Collaborate -> Pursue (blocked)" << agent->getId() );

				NoticePursue(agent);
				SetState (POLICE_PURSUE);
				return;
			}
			else {
				randomMove();
				MAS_DEBUG( "Collaborate -> Look (abort)" << agent->getId() );

				SetState (POLICE_LOOK);
				return;
			}
		}
	}

	if (--m_path[m_index]._uiTime == 0) {
		if (++m_index >= m_path.size()) {
			Agent* agent = SeeBadGuy(m_direction);
			if (agent != NULL) {
				MAS_DEBUG( "Collaborate -> Pursue (path ended)" << agent->getId() );

				NoticePursue(agent);
				SetState (POLICE_PURSUE);
			}
			else {
				MAS_DEBUG( "Collaborate -> Look (path ended)" << agent->getId() );

				SetState (POLICE_LOOK);
			}
		}
	}
}


   /*=====================================================================*/






























