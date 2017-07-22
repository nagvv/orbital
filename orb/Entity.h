/*
 * Entity.h
 *
 *  Created on: 18 февр. 2017 г.
 *      Author: Алексей
 */
#ifndef ENTITY_H
#define ENTITY_H
class Entity
{
	double x,y;
	double xSpeed, ySpeed;
	bool alive;
public:
	double getX();
	double getY();
	double getXSpeed();
	double getYSpeed();
	void setX(double);
	void setXSpeed(double);
	void setY(double);
	void setYSpeed(double);

	void addXSpeed(double);
	void addYSpeed(double);
	void tick();
	bool isAlive();
	Entity();
	Entity(double,double,double,double);
	void setAlive();
};
#endif
