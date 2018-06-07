#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"
#include <string>
#include <vector>

class WorldDungeonFixed
{
private:

	Punto posicionInicial;
	Enemigo aEnimigos[MAX_ITEMS];
	Obstaculo aObstaculos[MAX_ITEMS];
	Objeto aObjetos[MAX_ITEMS];
	Tesoro tesoro[MAX_ITEMS];

public:

	int numCeldasX = 960;
	int numCeldasY = 960;
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

