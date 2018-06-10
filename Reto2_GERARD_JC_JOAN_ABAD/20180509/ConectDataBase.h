#pragma once
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>
#include <cppconn\statement.h>
#include <cppconn\resultset.h>
#include <iostream> 
#include <string>
#include <vector>

#define HOST "tcp://192.168.123.7:3306"
#define USER "root"
#define PASSWORD "enti"
struct Personaje
{
	std::string nameRace;
	int gold;
	int lvl;
	std::string caracteristica;
};

class ConectDataBase
{
public:
	ConectDataBase();
	~ConectDataBase();
	void Login();
	void CrearUsuario();
	void CrearPersonaje();
	void MostrarRazas();
	void Menu();
	void MostrarPJ();
	void MostrarNombreRaza(int idraza);
	void MostrarCaracteristica(int idraza);
	void RecuperarPJ(int id, std::vector<std::string> aNames);
	
private:
	//sql::ResultSet *resultSet;
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *resultSet;

	std::string user1;
	std::string password1;
	std::string password2;
	std::string email;
	std::string characterName;
	std::string user_id_string;	

	Personaje Character;

	int idRace;
	int character_id;
	int user_id;
	bool logueado;
	bool cuentaCreada = false;


	
};

