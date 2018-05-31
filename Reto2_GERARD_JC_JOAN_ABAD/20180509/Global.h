#pragma once
#include <string>
#define MAX_ITEMS 10

struct Punto
{
	int x;
	int y;
};

struct Mapa
{
	int celdasX = 960;
	int celdasY = 960;
};

struct Enemigo
{
	Punto posicion;
	std::string tipo;
	int daño;
	int defensa;
	int x;
	int y;
};

struct Obstaculo
{
	Punto posicion;
	std::string tipo;
	std::string x;
	std::string y;
	int cantidadObstaculos;

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
	int x;
	int y;
};
