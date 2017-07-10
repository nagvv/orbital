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
	maxEnts=500;
	World::sizeX=100;
	this->sizeY=100;
	ents = new Entity*[maxEnts];
	for(int i=0;i<maxEnts;i++)
			ents[i]=nullptr;
}


World::World(double sizeX, double sizeY)
{
	maxEnts=500;
	World::sizeX=sizeX;
	this->sizeY=sizeY;
	ents = new Entity*[maxEnts];
	for(int i=0;i<maxEnts;i++)
		ents[i]=nullptr;
}
World::~World()
{
	for(int i=0;i<maxEnts;i++)
		{
			if(ents[i]!=nullptr)
			{
				delete ents[i];
			}
		}
	delete[] ents;
}

void World::Tick()
{
	for(int i=0;i<maxEnts;i++)
	{
		if(ents[i]!=nullptr)
		{
			if(ents[i]->isAlive())
			{
				ents[i]->tick();
			}
		}
	}
}
void World::addEntity()
{
	ents[num] = new Entity();
	ents[num]->setAlive();
	//ents[num]->setX(sizeX);
	ents[num]->setY(sizeY/2);
	//ents[num]->setXSpeed(-0.15);
	num++;
}










