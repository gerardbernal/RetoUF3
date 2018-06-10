#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"
#include <string>
#include <vector>
#include "Juego.h"
#include <map>
#include <vector>

class WorldDungeonFixed
{
private:

	std::map<int, Sala> mapa;

public:

	int posicionJugadorX = 321;
	int posicionJugadorY = 321;
	int posicionPuertaX;
	int posicionPuertaY;
	bool objetoCogido = false;
	WorldDungeonFixed();
	~WorldDungeonFixed();
	void Jugar();
	void LoadMap(/*pugi::char_t *_path*/);
	void Draw(sf::RenderWindow &window);
	void ShowInput(sf::RenderWindow &window, sf::RectangleShape &rectangle);
	void ComprovarPosicionJugador(int &posicionPuertaX, int &posicionPuertaY);
	int Oro = 2;
	std::vector<std::string> Inventario;
	std::string sword = "sword";
	


};

