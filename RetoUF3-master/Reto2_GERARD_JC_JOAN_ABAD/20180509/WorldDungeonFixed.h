#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"
#include <string>
#include <vector>
#include "Juego.h"
#include <map>
#include <vector>
#include "ConectDataBase.h"

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
	int numeroSala;
	void Jugar();
	void LoadMap(std::string &maps);
	void Draw(sf::RenderWindow &window);
	void ShowInput(sf::RenderWindow &window, sf::RectangleShape &rectangle);
	void ComprovarPosicionJugador();
	int Oro = 2;
	std::vector<std::string> Inventario;
	ConectDataBase db;
	std::string mapaDef;



};

