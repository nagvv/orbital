/*
 * World.cpp
 *
 *  Created on: 18 ����. 2017 �.
 *      Author: �������
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
	ents[num].reset(new Entity());//some troubles there
	ents[num]->setAlive();
	//ents[num]->setX(sizeX);
	ents[num]->setY(sizeY/2);
	//ents[num]->setXSpeed(-0.15);
	num++;
}










