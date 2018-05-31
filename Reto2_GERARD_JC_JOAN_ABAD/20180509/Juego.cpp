#include "Juego.h"



Juego::Juego()
{
}


Juego::~Juego()
{
}

void Juego::Jugar()
{

	WorldDungeonFixed worldFixed;
	Tesoro tesoro;
	worldFixed.LoadMap("simple2.xml");
	sf::RenderWindow window(sf::VideoMode(worldFixed.numCeldasX, worldFixed.numCeldasY), "SFML works!");
	sf::RectangleShape personaje;
	personaje.setSize(sf::Vector2f(32, 32));
	personaje.setPosition(sf::Vector2f(321, 321));
	personaje.setFillColor(sf::Color::Green);





	while (window.isOpen())
	{

		worldFixed.ShowInput(window, personaje);
		window.clear();
		worldFixed.Draw(window);
		window.draw(personaje);
		window.display();
	}
}
