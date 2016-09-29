/***************************************************************************
						context.h  -  description
							-------------------
	begin                : jun 19th, 2007
	copyright            : (C) 2007 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: context.h 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_CONTEXT_H_
#define _OPENCITY_CONTEXT_H_ 1

#include "../map.h"


namespace MapGen
{


//========================================================================
/** Define generic context
*/
class Context {
public:
	Context();
	virtual ~Context();

	virtual float contextualize( const float height, const float context ) const = 0;

private:

};


}

#endif
