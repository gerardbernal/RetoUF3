#pragma once
#include <string>
#define MAX_ITEMS 10

struct Punto
{
	int x;
	int y;
};

struct Player
{
	std::string name;
	Punto posicion;
};

struct Enemigo
{
	Punto posicion;
	std::string tipo;
};

struct Obstaculo
{
	Punto posicion;
	std::string tipo;
};

struct Objeto
{
	Punto posicion;
	std::string tipo;
};

struct Tesoro
{
	Punto posicion;
	int numMonedas;
};

struct Puerta
{
	Punto posicion;
	int idPuerta;
};
struct Sala
{
	int numCeldasX;
	int numCeldasY;


	Punto posicionInicial;
	Player aPersonaje;
	Enemigo aEnimigos[MAX_ITEMS];
	Obstaculo aObstaculos[MAX_ITEMS];
	Objeto aObjetos[MAX_ITEMS];
	Tesoro tesoro[MAX_ITEMS];
	Puerta aPuerta[MAX_ITEMS];
};