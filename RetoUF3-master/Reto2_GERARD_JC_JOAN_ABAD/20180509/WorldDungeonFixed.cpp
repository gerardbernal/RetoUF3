#include "WorldDungeonFixed.h"
#include "pugixml.hpp"
#include "Global.h"
#include <string>
#include <iostream>
#include "Juego.h"

typedef const pugi::char_t* pugiCharArray;



WorldDungeonFixed::WorldDungeonFixed()
{
	
			
}


WorldDungeonFixed::~WorldDungeonFixed()
{
}

void WorldDungeonFixed::LoadMap(std::string &maps)
{
	pugi::xml_document str;

	pugi::xml_parse_result result = str.load_string(maps.c_str());

	pugi::xml_node NodoDungeon = str.child("Dungeon");
	for (pugi::xml_node sala = NodoDungeon.child("sala");sala;sala = sala.next_sibling("sala"))
	{
		 
		Sala s;

		pugiCharArray id = sala.attribute("id").value();
		pugiCharArray celdas_x = sala.attribute("celdas_h").value();
		pugiCharArray celdas_y = sala.attribute("celda_v").value();
		pugiCharArray ini_x = sala.attribute("pos_ini_h").value();
		pugiCharArray ini_y = sala.attribute("pos_ini_v").value();

		s.numCeldasX = stoi(std::string(celdas_x));
		s.numCeldasY = stoi(std::string(celdas_y));
		s.posicionInicial.x = stoi(std::string(ini_x));
		s.posicionInicial.y = stoi(std::string(ini_y));

		pugi::xml_node PJ = sala.child("personaje");
		pugiCharArray PJname = PJ.attribute("name").value();
		pugiCharArray PJx = PJ.attribute("x").value();
		pugiCharArray PJy = PJ.attribute("y").value();

		s.aPersonaje.name = PJname;
		s.aPersonaje.posicion.x = stoi(std::string(PJx));
		s.aPersonaje.posicion.y = stoi(std::string(PJx));

		std::cout << s.aPersonaje.name << "Empieza la partida" << std::endl;

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
			pugiCharArray Pos_x = enemigo.attribute("pos_h").value();
			pugiCharArray Pos_y = enemigo.attribute("pos_v").value();
			pugiCharArray tipo = enemigo.attribute("tipo").value();

			s.aEnimigos[ind].posicion.x = stoi(std::string(Pos_x));
			s.aEnimigos[ind].posicion.y = stoi(std::string(Pos_y));
			s.aEnimigos[ind].tipo = tipo;

			ind++;
		}
		ind = 0;

		pugi::xml_node objetos = sala.child("objetos");
		for (pugi::xml_node objeto = enemigos.child("objeto");
			objeto;
			objeto = objeto.next_sibling("objeto"))
		{
			pugiCharArray Pos_x = objeto.attribute("pos_h").value();
			pugiCharArray Pos_y = objeto.attribute("pos_v").value();
			pugiCharArray tipo = objeto.attribute("tipo").value();

			s.aObjetos[ind].posicion.x = stoi(std::string(Pos_x));
			s.aObjetos[ind].posicion.y = stoi(std::string(Pos_y));
			s.aObjetos[ind].tipo = tipo;

			

			ind++;
		}
		ind = 0;

		pugi::xml_node tesoros = sala.child("tesoros");
		for (pugi::xml_node tesoro = enemigos.child("tesoro");
			tesoro;
			tesoro = tesoro.next_sibling("tesoro"))
		{
			pugiCharArray Pos_x = tesoro.attribute("pos_h").value();
			pugiCharArray Pos_y = tesoro.attribute("pos_v").value();
			pugiCharArray cantidad = tesoro.attribute("cantidad").value();

			s.tesoro[ind].posicion.x = stoi(std::string(Pos_x));
			s.tesoro[ind].posicion.y = stoi(std::string(Pos_y));
			s.tesoro[ind].numMonedas = stoi(std::string(cantidad));

			ind++;
		}
		ind = 0;

		pugi::xml_node puertas = sala.child("puertas");
		for (pugi::xml_node puerta = enemigos.child("puerta");
			puerta;
			puerta = puerta.next_sibling("puerta"))
		{
			pugiCharArray Pos_x = puerta.attribute("pos_h").value();
			pugiCharArray Pos_y = puerta.attribute("pos_v").value();
			pugiCharArray idPuerta = puerta.attribute("id").value();

			s.aPuerta[ind].posicion.x = stoi(std::string(Pos_x));
			s.aPuerta[ind].posicion.y = stoi(std::string(Pos_y));
			s.aPuerta[ind].idPuerta = stoi(std::string(idPuerta));

			ind++;
		}
		ind = 0;
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


	baul.setPosition(sf::Vector2f(mapa[numeroSala].tesoro->posicion.x, mapa[numeroSala].tesoro->posicion.y));
	

	if (!textureSuelo.loadFromFile("Assets/Suelo.png", sf::IntRect(0, 0, 32, 32)))
	{
		std::cout << "Error al cargar la imagen" << std::endl;
	}
	if (!textureAltar.loadFromFile("Assets/altar.png", sf::IntRect(0, 0, 32, 32)))
	{
		std::cout << "Error al cargar la imagen" << std::endl;
	}	
	
	for (int i = 0; i <= mapa[numeroSala].numCeldasX; i+=32)
	{
			for (int j = 0; j <= mapa[numeroSala].numCeldasY; j +=32)
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
			mapa[1].aPersonaje.posicion.x+=32;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			std::cout << "TeclaPresionada-> Right" << std::endl;
			rectangle.move(sf::Vector2f(32, 0));
			mapa[1].aPersonaje.posicion.x += 32;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			std::cout << "TeclaPresionada-> Up" << std::endl;
			rectangle.move(sf::Vector2f(0, -32));

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			std::cout << "TeclaPresionada-> Down" << std::endl;
			rectangle.move(sf::Vector2f(0, 32));
			mapa[1].aPersonaje.posicion.y += 32;
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
			/*std::cout << "Oro: " << Oro << std::endl;
			std::cout << "Inventario: " << std::endl;
			std::cout << "Tienes " << Inventario.size() << " espadas!";*/
			std::cout << mapa[1].aPersonaje.posicion.x << std::endl;
			std::cout << mapa[1].aPersonaje.posicion.y << std::endl;
			std::cout << mapa[0].numCeldasX << std::endl;
			std::cout << mapa[0].numCeldasY << std::endl;
			
			//std::cout << Inventario.size();

			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			std::cout << "PosicionX = " << posicionJugadorX << "." << std::endl;
			std::cout << "PosicionY = " << posicionJugadorY << "." << std::endl;
		}
		
	}


	ComprovarPosicionJugador();
}

void WorldDungeonFixed::Jugar()
{

	std::string map = db.MostrarMapas();
	sf::RenderWindow window(sf::VideoMode(960,960), "SFML works!");
	sf::RectangleShape personaje;
	personaje.setSize(sf::Vector2f(32, 32));
	personaje.setPosition(sf::Vector2f(mapa[1].aPersonaje.posicion.x, mapa[1].aPersonaje.posicion.y));
	personaje.setFillColor(sf::Color::Green);
	LoadMap(map);

	
	
	while (window.isOpen())
	{
		ComprovarPosicionJugador();
		ShowInput(window, personaje);
		window.clear();
		Draw(window);
		window.draw(personaje);
		window.display();
	}
}

void WorldDungeonFixed::ComprovarPosicionJugador()
{	
	if (mapa[1].aPersonaje.posicion.x == mapa[1].aPuerta->posicion.x && mapa[1].aPersonaje.posicion.y == mapa[1].aPuerta->posicion.y)
	{
		numeroSala = 1;
	}

	if (mapa[1].aPersonaje.posicion.x == mapa[2].aPuerta[2].posicion.x && mapa[1].aPersonaje.posicion.y == mapa[2].aPuerta->posicion.y)
	{
		numeroSala = 2;
	}
	if (mapa[1].aPersonaje.posicion.x == mapa[0].aPuerta->posicion.x && mapa[1].aPersonaje.posicion.y == mapa[0].aPuerta->posicion.y)
	{
		numeroSala = 0;
	
	}
}



