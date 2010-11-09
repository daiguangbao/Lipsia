/***************************************************************************
 *   Copyright (C) 2005 by Hannes Niederhausen                             *
 *   niederhausen@cbs.mpg.de                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef VLAIM_H
#define VLAIM_H

/**
Diese Klasse zeichnet das Zielkreut eines vlGLWidgets

@author Hannes Niederhausen
	Thomas Pr�ger
*/
class vlAim{
private:
	float m_posX;
	float m_posY;

public:
    vlAim(float x=0, float y=0);

    ~vlAim();

	void draw();

	void setPos(float x, float y);

	float X() {return m_posX;};
	float Y() {return m_posY;};

	void setX(float x) {m_posX=x;};
	void setY(float y) {m_posY=-y;};

};

#endif
