/*
 * Entity.cpp
 *
 *  Created on: 18 февр. 2017 г.
 *      Author: Алексей
 */


#include "Entity.h"
#include <cmath>
//#include <iostream>

extern double speed;

double Entity::getX()
{
	return x;
}
double Entity::getY()
{
	return y;
}
double Entity::getXSpeed()
{
	return xSpeed;
}
double Entity::getYSpeed()
{
	return ySpeed;
}

void Entity::setX(double x)
{
	this->x = x;
}
void Entity::setXSpeed(double speed)
{
	xSpeed = speed;
}
void Entity::setY(double y)
{
	this->y = y;
}
void Entity::setYSpeed(double speed)
{
	ySpeed = speed;
}

void Entity::addXSpeed(double xs)
{
	xSpeed+=xs;
}
void Entity::addYSpeed(double ys)
{
	ySpeed+=ys;
}

Entity::Entity()
{
	x=0;
	y=0;
	xSpeed=0;
	ySpeed=0;
	alive=false;
}
Entity::Entity(double x,double y,double xSpeed,double ySpeed)
{
	this->x=0;
	this->y=0;
	this->xSpeed=xSpeed;
	this->ySpeed=ySpeed;
	alive=false;
}

bool Entity::isAlive()
{
	return alive;
}
void Entity::setAlive()
{
	alive=true;
}
void Entity::tick()
{
	if(x*x+y*y>64)
	{
		xSpeed-=((speed/(x*x+y*y))*(x/std::sqrt(x*x+y*y)));
		ySpeed-=((speed/(x*x+y*y))*(y/std::sqrt(x*x+y*y)));
	}
	x+=xSpeed;
	y+=ySpeed;
	//std::cout.width(10);
	//std::cout.precision(8);
	//std::cout.setf(std::ios::fixed);
	//std::cout << x << " " << y << " : " << xSpeed <<" "<<ySpeed<< " | "<< ((10/(x*x+y*y))*(x/std::sqrt(x*x+y*y)))/10 <<"  "<<((10/(x*x+y*y))*(y/std::sqrt(x*x+y*y)))/10<<std::endl;
}


