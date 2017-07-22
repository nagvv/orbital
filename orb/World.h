/*
 * World.h
 *
 *  Created on: 18 февр. 2017 г.
 *      Author: Алексей
 */

#include "Entity.h"
#include <vector>
#include <memory>

class World
{
private:
	double sizeX, sizeY;
public:
	std::vector<std::shared_ptr<Entity>> ents;//

public:
	World(double,double);
	World();
	~World();
	void addEntity();
	void Tick();
};
