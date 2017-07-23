/*
 * World.cpp
 *
 *  Created on: 18 февр. 2017 г.
 *      Author: Алексей
 */
#include "World.h"
#include <iostream>
#include "Entity.h"
int num=0;

World::World()
{
	sizeX=100;
	sizeY=100;
	ents.reserve(10);
}


World::World(double sizeX, double sizeY)
{
	this->sizeX=sizeX;
	this->sizeY=sizeY;
	ents.reserve(10);
}
World::~World()
{
	std::cout << "... The End." << std::endl;
}

void World::Tick()
{
	for(auto i=ents.begin();i!=ents.end();i++)
	{
		if((*i!=nullptr))
		{
			if((*i)->isAlive())
				(*i)->tick();
		}
	}
	/*for(int i=0;i<maxEnts;i++)
	{
		if(ents[i]!=nullptr)
		{
			if(ents[i]->isAlive())
			{
				ents[i]->tick();
			}
		}
	}*/
}
void World::addEntity()
{
	std::shared_ptr<Entity> e(new Entity());
	e->setAlive();
	e->setY(sizeY/2);
	ents.push_back(e);
}










