/*
 * World.h
 *
 *  Created on: 18 февр. 2017 г.
 *      Author: Алексей
 */
#include "Entity.h"
class World
{
private:
	double sizeX, sizeY;
public:
	int maxEnts;
	Entity **ents;

public:
	World(double,double);
	World();
	~World();
	void addEntity();
	void Tick();
};
