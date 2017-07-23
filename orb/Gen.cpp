/*
 * Gen.cpp
 *
 *  Created on: 11 февр. 2017 г.
 *      Author: Алексей
 */

#include <iostream>
#include <thread>
#include "World.h"
#include "unistd.h"
#include <SFML/Graphics.hpp>
#include <chrono>

//using namespace std;
bool isRunning;//выполняемся ли мы
int wsize=1000,center=wsize/2, multitick=10;
double speed=0.04;//множитель скорости игры


void ticker(World& world, sf::RenderWindow* win)
{
	while(isRunning)
	{
		//время до тика
		auto t1 = std::chrono::high_resolution_clock::now();
		//отрисовка
		win->clear(sf::Color::White);
		for(unsigned int i=0;i<world.ents.size();i++)
		{
			if(world.ents[i]!=nullptr)
			{
				std::cout << i << " " << world.ents[i]->getY() << std::endl;
				if(world.ents[i]->isAlive())
				{
					sf::CircleShape shape(10);
					shape.setFillColor(sf::Color::Red);
					shape.setPosition(center-shape.getRadius()+(int)((world.ents[i]->getX())*5),center-shape.getRadius()+(int)((world.ents[i]->getY())*5));
					win->draw(shape);
				}
			}
		}
		sf::CircleShape shape(40);
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineThickness(1);
		shape.setOutlineColor(sf::Color::Green);
		shape.setPosition(center-shape.getRadius(),center-shape.getRadius());
		win->draw(shape);
		win->display();
		//тик multitick раз
		for(int i=0;i<multitick;++i)
			world.Tick();
		//время после тика
		auto t2 = std::chrono::high_resolution_clock::now();
		//сплю необходимое время(10000)
		usleep(10000-std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count());
	}
}


int main(int argc, char** argv)
{
	//std::cout << "started..." <<std::endl;
	isRunning=true;

	//создание окна
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow win(sf::VideoMode(wsize,wsize),"Study",sf::Style::Titlebar | sf::Style::Close,settings);

	//создание мира
	World world = World();


	world.addEntity();
	win.setActive(false);

	//создаю второй поток для обновления мира и отрисовки
	std::thread thr(ticker, std::ref(world), &win);//мир передаю по ссылке, указатель на обьект окна

	//основной поток обработки инпута
	while (win.isOpen())
	{
		// проверка всех событий окна, произошедших с последней итерации цикла
		sf::Event event;
		while (win.pollEvent(event))
		{
			// пользователь попытался закрыть окно: мы закрываем окно
			if (event.type == sf::Event::Closed)
				win.close();
			else if(event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					world.ents[0]->addXSpeed(-0.1*speed);
					std::cout << "left" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					world.ents[0]->addXSpeed(0.1*speed);
					std::cout << "right" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					world.ents[0]->addYSpeed(-0.1*speed);
					std::cout << "up" << std::endl;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					world.ents[0]->addYSpeed(0.1*speed);
					std::cout << "down" << std::endl;
				}
			}
		}
	   /* win.clear(sf::Color::White);

		for(int i=0;i<world.maxEnts;i++)
			{
				if(world.ents[i]!=nullptr)
				{
					if(world.ents[i]->isAlive())
					{
						sf::CircleShape shape(10);
						shape.setFillColor(sf::Color::Red);
						shape.setPosition(center-shape.getRadius()+(int)((world.ents[i]->getX())*5),center-shape.getRadius()+(int)((world.ents[i]->getY())*5));
						win.draw(shape);
					}
				}
			}
		win.display();*/


	}
	isRunning=false;//обозначаюсь как остановленный
	thr.join();//жду завершения потока

	return 0;
}

