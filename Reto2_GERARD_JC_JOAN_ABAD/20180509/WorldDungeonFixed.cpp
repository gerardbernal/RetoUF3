#include "WorldDungeonFixed.h"
#include "pugixml.hpp"
#include "Global.h"
#include <string>
#include <iostream>

typedef const pugi::char_t* pugiCharArray;
Mapa mapa;


WorldDungeonFixed::WorldDungeonFixed()
{
	
			
}


WorldDungeonFixed::~WorldDungeonFixed()
{
}

void WorldDungeonFixed::LoadMap(std::string _path)
{


	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("simple2.xml");

	pugi::xml_node nodoMapeade = doc.child("mapa");

	pugi::xml_node nodoMapa = nodoMapeade.child("numCeldas");

	for (pugi::xml_node nodoCoordenadas = nodoMapa.child("celda"); nodoCoordenadas; nodoCoordenadas = nodoCoordenadas.next_sibling("celda"))
	{
		pugiCharArray pugiX = nodoCoordenadas.attribute("x").value();
		pugiCharArray pugiY = nodoCoordenadas.attribute("y").value();

		mapa.celdasX = stoi(std::string(pugiX));
		mapa.celdasY = stoi(std::string(pugiY));

	}

	pugi::xml_node nodoTesoros = doc.child("tesoro");

	for (pugi::xml_node nodoTesoro = nodoTesoros.child("obstaculo"); nodoTesoros; nodoTesoros = nodoTesoros.next_sibling("oro"))
	{
		pugiCharArray pugiCantidad = nodoTesoro.attribute("tipo").value();
		pugiCharArray pugiX = nodoTesoro.attribute("x").value();
		pugiCharArray pugiY = nodoTesoro.attribute("y").value();


		Tesoro tesoro;
		tesoro.numMonedas = stoi(std::string(pugiCantidad));
		tesoro.x = stoi(std::string(pugiX));
		tesoro.y = stoi(std::string(pugiY));
		
	}
	
	//OBSTACULOS

	pugi::xml_node nodoSala = doc.child("obstaculos");

	for (pugi::xml_node nodoObstaculo = doc.child("obstaculo"); nodoObstaculo; nodoObstaculo = nodoObstaculo.next_sibling("obstaculo"))
	{
		pugiCharArray pugiTipo = nodoObstaculo.attribute("tipo").value();
		pugiCharArray pugiX = nodoObstaculo.attribute("x").value();
		pugiCharArray pugiY = nodoObstaculo.attribute("y").value();

		Enemigo enemigo;
		enemigo.tipo = stoi(std::string(pugiTipo));
		enemigo.x = stoi(std::string(pugiX));
		enemigo.y = stoi(std::string(pugiY));


	}

	//ENEMIGO

	pugi::xml_node nodoEnemigos = doc.child("enemigos");

	for (pugi::xml_node nodoEnemigo = nodoEnemigos.child("enemigo"); nodoEnemigo; nodoEnemigo = nodoEnemigo.next_sibling("enemigo"))
	{
		pugiCharArray pugiTipo = nodoEnemigo.attribute("tipo").value();
		pugiCharArray pugiDaño = nodoEnemigo.attribute("daño").value();
		pugiCharArray pugiDefensa = nodoEnemigo.attribute("defensa").value();
		pugiCharArray pugiX = nodoEnemigo.attribute("x").value();
		pugiCharArray pugiY = nodoEnemigo.attribute("y").value();

		Enemigo enemigo;
		enemigo.tipo = stoi(std::string(pugiTipo));
		enemigo.daño = stoi(std::string(pugiDaño));
		enemigo.defensa = stoi(std::string(pugiDefensa));
		enemigo.x = stoi(std::string(pugiX));
		enemigo.y = stoi(std::string(pugiY));
	    
	}

	//Tesoros
}

void WorldDungeonFixed::Draw(sf::RenderWindow &window)
{
	sf::Texture textureSuelo;
	sf::Texture textureBaul;
	sf::Texture textureAltar;
	sf::Texture textureFlecha;

	bool entradaBucle = true;
	sf::RectangleShape suelo(sf::Vector2f(32, 32));
	sf::RectangleShape altar(sf::Vector2f(32, 32));
	sf::RectangleShape flecha(sf::Vector2f(32, 32));


	textureSuelo.loadFromFile("Assets/Suelo.png");
	textureAltar.loadFromFile("Assets/altar.png");
	textureFlecha.loadFromFile("Assets/zelda-sprites-items.png");

	suelo.setTexture(&textureSuelo);
	flecha.setTexture(&textureFlecha);

	
	sf::RectangleShape baul(sf::Vector2f(32, 32));

	if (objetoCogido == false)
	{
	textureBaul.loadFromFile("Assets/Chest.png");
	baul.setTexture(&textureBaul);

	if (!textureBaul.loadFromFile("Assets/Chest.png", sf::IntRect(0, 0, 32, 32)))
	{
		std::cout << "Error al cargar la imagen" << std::endl;
	}

	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			objetoCogido = true;
			std::cout << "TeclaPresionada-> R" << std::endl;
			baul.setFillColor(sf::Color::Transparent);
	}
	
		

	altar.setTexture(&textureAltar);


	baul.setPosition(sf::Vector2f(tesoro->x, tesoro->y));
	altar.setPosition(sf::Vector2f(641, 641));
	flecha.setPosition(sf::Vector2f(720, 720));

	if (!textureSuelo.loadFromFile("Assets/Suelo.png", sf::IntRect(0, 0, 32, 32)))
	{
		std::cout << "Error al cargar la imagen" << std::endl;
	}
	if (!textureAltar.loadFromFile("Assets/altar.png", sf::IntRect(0, 0, 32, 32)))
	{
		std::cout << "Error al cargar la imagen" << std::endl;
	}	
	
	for (int i = 0; i <= mapa.celdasX; i+=32)
	{
			for (int j = 0; j <= mapa.celdasY; j +=32)
			{
				suelo.setPosition(sf::Vector2f(i , j));
				window.draw(suelo);
			}	
	}

	window.draw(flecha);
	window.draw(suelo);
	window.draw(baul);
	window.draw(altar);
}

void WorldDungeonFixed::ShowInput(sf::RenderWindow &window, sf::RectangleShape &rectangle)
{

	sf::Event event;
	pugi::xml_document doc;


	while (window.pollEvent(event))
	{


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			std::cout << "TeclaPresionada-> LEFT" << std::endl;
			rectangle.move(sf::Vector2f(-32, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			std::cout << "TeclaPresionada-> Right" << std::endl;
			rectangle.move(sf::Vector2f(32, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			std::cout << "TeclaPresionada-> Up" << std::endl;
			rectangle.move(sf::Vector2f(0, -32));

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			std::cout << "TeclaPresionada-> Down" << std::endl;
			rectangle.move(sf::Vector2f(0, 32));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			std::cout << "TeclaPresionada-> R" << std::endl;

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			std::cout << "Guardando..." << std::endl;
			pugi::xml_parse_result result = doc.load_file("simple2.xml");
			doc.save_file("SaveGame1.xml");
			std::cout << "Guardado" << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			std::cout << "Oro: " << Oro << std::endl;
			std::cout << "Inventario: " << std::endl;
			Inventario.push_back(sword);

			std::cout << "Tienes " << Inventario.size() << " espadas!";

			//std::cout << Inventario.size();

			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}


	}
}
