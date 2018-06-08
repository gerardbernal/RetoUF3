#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"
#include <string>
#include <vector>
#include "Juego.h"

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
	int posicionJugadorX = 321;
	int posicionJugadorY = 321;
	int posicionPuertaX;
	int posicionPuertaY;
	bool objetoCogido = false;
	WorldDungeonFixed();
	~WorldDungeonFixed();
	void Jugar();
	void LoadMap(pugi::char_t *_path);
	void Draw(sf::RenderWindow &window);
	void ShowInput(sf::RenderWindow &window, sf::RectangleShape &rectangle);
	void ComprovarPosicionJugador(int &posicionPuertaX, int &posicionPuertaY);
	int Oro = 2;
	std::vector<std::string> Inventario;
	std::string sword = "sword";
	


};

