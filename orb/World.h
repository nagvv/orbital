/*
 * World.h
 *
 *  Created on: 18 ����. 2017 �.
 *      Author: �������
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
