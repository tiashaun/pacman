/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#pragma once

#include <SFML/Graphics.hpp>
#include <boost/shared_ptr.hpp>

#include "Main.h"

using boost::shared_ptr;

class Object
{
public:
    Object(shared_ptr<sf::RenderWindow> buffer, int os )
    :	buf(buffer),
            offset(os),
            paused(true),
            alpha(255)
    {
    }

    virtual ~Object() {}

    void setPaused(bool b) { paused = b; }
    void setAlpha(int a) { alpha = a; }

    virtual void reset( int ix, int iy) = 0;
    virtual void Update(int time) = 0;

    virtual void Draw() = 0;
    virtual void Draw(int ix, int iy, int obj=3, int type=1)=0;
    virtual bool LoadTextures(std::string path)=0;

protected:
    shared_ptr<sf::RenderWindow>
            buf;

    const int
            offset;

    bool
            paused;

    int
            alpha;
};
