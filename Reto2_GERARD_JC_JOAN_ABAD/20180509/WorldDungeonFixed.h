#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"
#include <string>
#include <vector>
#include <map>
class WorldDungeonFixed
{
private:

	std::map<int, Sala> mapa;
	

public:


	bool objetoCogido = false;
	WorldDungeonFixed();
	~WorldDungeonFixed();
	void LoadMap(std::string _path);
	void Draw(sf::RenderWindow &window);
	void ShowInput(sf::RenderWindow &window, sf::RectangleShape &rectangle);
	void Colisiones();
	int Oro = 2;
	std::vector<std::string> Inventario;
	std::string sword = "sword";
	


};

