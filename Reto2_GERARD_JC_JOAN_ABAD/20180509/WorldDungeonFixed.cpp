#include "WorldDungeonFixed.h"
#include "pugixml.hpp"
#include "Global.h"
#include <string>
#include <iostream>

typedef const pugi::char_t* pugiCharArray;

WorldDungeonFixed::WorldDungeonFixed()
{
	
			
}


WorldDungeonFixed::~WorldDungeonFixed()
{
}

void WorldDungeonFixed::LoadMap(std::string _path)
{


	pugi::xml_document str;
	pugi::xml_parse_result result = str.load_string(XmlMapa);

	pugi::xml_node NodoDungeon = str.child("Dungeon");
	for (pugi::xml_node sala = NodoDungeon.child("sala");
		sala;
		sala = sala.next_sibling("sala"))
	{
		pugiCharArray id = sala.attribute("id").value;
		pugiCharArray celdas_x = sala.attribute("celdas_h").value();
		pugiCharArray celdas_y = sala.attribute("celda_v").value();
		pugiCharArray ini_x = sala.attribute("pos_ini_h").value();
		pugiCharArray ini_y = sala.attribute("pos_ini_v").value();

		Sala s;
		s.numCeldasX = stoi(std::string(celdas_x));
		s.numCeldasY = stoi(std::string(celdas_y));
		s.posicionInicial.x = stoi(std::string(ini_x));
		s.posicionInicial.y = stoi(std::string(ini_y));
		
		pugi::xml_node PJ = sala.child("personaje");
		pugiCharArray PJname = PJ.attribute("name").value();
		pugiCharArray PJx= PJ.attribute("x").value();
		pugiCharArray PJy= PJ.attribute("y").value();

		s.aPersonaje.name = PJname;
		s.aPersonaje.posicion.x = stoi(std::string(PJx));
		s.aPersonaje.posicion.y = stoi(std::string(PJx));

		std::cout << s.aPersonaje.name << "Empieza la partida"<<std::endl;
		
		pugi::xml_node obstaculos = sala.child("obstculos");

		int ind = 0;
		for (pugi::xml_node obstaculo = obstaculos.child("obstaculo");
			obstaculo;
			obstaculo = obstaculo.next_sibling("obstaculos"))
		{
			pugiCharArray Pos_x = obstaculo.attribute("pos_h").value();
			pugiCharArray Pos_y = obstaculo.attribute("pos_v").value();
			pugiCharArray tipo = obstaculo.attribute("tipo").value();

			s.aObstaculos[ind].posicion.x = stoi(std::string(Pos_x));
			s.aObjetos[ind].posicion.y = stoi(std::string(Pos_y));
			s.aObjetos[ind].tipo = tipo;


			ind++;	
		}
		ind = 0;

		pugi::xml_node enemigos = sala.child("enemigos");
		for (pugi::xml_node enemigo = enemigos.child("enemigo");
			enemigo;
			enemigo = enemigo.next_sibling("enemigo"))
		{
			
		}
		
		mapa[stoi(std::string(id))] = s;
	}

	

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
