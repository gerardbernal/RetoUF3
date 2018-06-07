#include "ConectDataBase.h"
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>
#include <cppconn\statement.h>
#include <cppconn\resultset.h>
#include <vector>
#include "Juego.h"


ConectDataBase::ConectDataBase()
{
	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);
	stmt = con->createStatement();
	stmt->execute("USE DungeonDB");
}


ConectDataBase::~ConectDataBase()
{

	delete con;
	delete stmt;
	//delete driver;

}

void ConectDataBase::Menu()
{
	int opcion;
	std::cout << "1 : Entrar" << std::endl;
	std::cout << "2 : Registrarse" << std::endl;
	std::cout << "3 : que hago aquí?" << std::endl;
	std::cin >> opcion;

	system("cls");

	switch (opcion)
	{
	case 1:
		Login();
		break;
	case 2:
		CrearUsuario();
		break;
	case 3:
		break;

	}
}

void ConectDataBase::MostrarPJ()
{
	
	if (logueado == true)
	{
		std:
		std::string str;
		int id = 0;
		
		std::vector<std::string> aNames;
		std::cout << "Listado de tus personajes" << std::endl;
		std::string query = "SELECT `character`, id_character FROM `characters` WHERE `users_id_user` ="+ std::to_string(user_id);
		sql::ResultSet* resultSet = stmt->executeQuery(query.c_str());
		while (resultSet->next())
		{
			str = resultSet->getString(1).c_str();
			id++;
			std::cout << id << " - " << str << std::endl;
			aNames.push_back(str);
		}
		printf("\n");
		
		int opcion;
		delete resultSet;
		std::cout << "1- Escojer personaje" << std::endl << "2- Crear Personaje" << std::endl;
		std::cin >> opcion;
		switch (opcion)
		{
		case 1:
			RecuperarPJ(id, aNames);
			break;
		case 2:
			CrearPersonaje();
			break;
		}
		
	}
	else 
	{
		Login();
	}
		
	
}
void ConectDataBase::MostrarNombreRaza(int idraza)
{

	std::string queryMostrarRazaID = "SELECT race FROM races WHERE id_race = " + std::to_string(idraza);
	sql::ResultSet* resultSet = stmt->executeQuery(queryMostrarRazaID.c_str());
	resultSet->next();
	Character.nameRace = resultSet->getString("race").c_str();
	std::cout << "Race - "<< Character.nameRace << std::endl;
	delete resultSet;
}

void ConectDataBase::MostrarCaracteristica(int idraza)
{
	std::string queryMostrarCaracteristica = "SELECT characteristic FROM races WHERE id_race = " + std::to_string(idraza);
	sql::ResultSet* resultSet = stmt->executeQuery(queryMostrarCaracteristica.c_str());
	resultSet->next();
	Character.caracteristica = resultSet->getString("characteristic").c_str();
	std::cout << "Characteristic - " << Character.caracteristica << std::endl;
}

void ConectDataBase::RecuperarPJ(int id, std::vector<std::string> aNames)
{
	std::cout << "Escoja un Personaje, ponga el numero que correseponda con su personaje."<<std::endl;
	std::cin >> id;
	std::string queryMostrarPJ = "SELECT * FROM `characters` WHERE `character` ='" + aNames[id -1] + "'";
	sql::ResultSet* resultSet = stmt->executeQuery(queryMostrarPJ.c_str());

	resultSet->next();

	std::string chName = resultSet->getString("character").c_str();
	std::cout << chName << std::endl;
	

	//Raza
	int raza = resultSet->getInt("races_id_race");
	MostrarNombreRaza(raza);
	//oro
	Character.gold = resultSet->getInt("gold");
	std::cout << "gold - " << Character.gold << std::endl;
	//nivel
	Character.lvl = resultSet->getInt("level");
	std::cout << "lvl - "<<Character.lvl << std::endl;
	//caracteristica
	MostrarCaracteristica(raza);
	//Inventario
	

	delete resultSet;

	MostrarMapas();
	//Juego Jugar;
	//Jugar.Jugar();
}

void ConectDataBase::MostrarMapas()
{
	std::string str;
	int mapaid;

	std::vector<std::string> aMapas;
	std::string query = "SELECT * FROM `maps` WHERE 1";
	sql::ResultSet* resultSet = stmt->executeQuery(query.c_str());
	for (int i = 0; resultSet->next(); i++)
	{
		mapaid = resultSet->getInt("id_map");
		str = resultSet->getString(2).c_str();
		std::cout << mapaid << " - " << str << std::endl;
		aMapas.push_back(str);

	}


	int id;

	std::cout << "Introduce el numero del mapa" << std::endl;
	std::cin >> id;
	//std::to_string(id);
	std::string queryMostrarMapa = "SELECT mapfile FROM `maps` WHERE `id_map` =" + std::to_string (id);
	sql::ResultSet* resultMap = stmt->executeQuery(queryMostrarMapa.c_str());

	resultMap->next();
	str = resultMap->getString(1).c_str();

	//std::string MapaElegido = resultSet->getString("map").c_str();
	
	std::cout << str << std::endl;

	xmlMapa = str;

	delete resultSet;
	delete resultMap;
	Juego Jugar;
	Jugar.Jugar();
}

void ConectDataBase::Login()
{
	std::string user;
	std::string password;
	std::cout << "USERNAME: "; std::cin >> user;
	std::cout << "PASSWORD: "; std::cin >> password;
	system("cls");
	
	std::string query = "SELECT COUNT(*) FROM users WHERE `user`='" + user + "' and `password` ='" + password + "'";
	sql::ResultSet* resultSet = stmt->executeQuery(query.c_str());

	resultSet->next();
	if (int num = resultSet->getInt(1) == 1)
	{
		std::cout << "Has entrado" << std::endl << std::endl;
		std::string query2 = "SELECT `id_user` FROM `users` WHERE `user` ='" + user + "'";
		sql::ResultSet* resultSet = stmt->executeQuery(query2.c_str());
		resultSet->next();
		user_id = resultSet->getInt(1);
		logueado = true;
		delete resultSet;

		MostrarPJ();
	}
	else if (int num = resultSet->getInt(1) == 0)
	{
		std::cout << "Te has equivocado, vuelve a intentar-lo" << std::endl;
		//delete resultSet;
		Login();
		logueado = false;
	}
	else
	{
		std::cout << "Internal database error" << std::endl;
	}
	delete resultSet;
}



void ConectDataBase::CrearUsuario()
{
	logueado = false;
	while (logueado == false)
	{
		std::cout << "Introduzca nuevo nombre de usuario: ";
		std::cin >> user1;
		std::cout << "\nIntroduzca nueva contraseña: ";
		std::cin >> password1;
		std::cout << "\nIntroduzca otra vez la contraseña: ";
		std::cin >> password2;
		std::cout << "\nIntroduzca mail: ";
		std::cin >> email;
		std::cout << std::endl << std::endl << std::endl << std::endl;
		stmt = con->createStatement();



		//resultSet = stmt->executeQuery(QUsuarioExiste.c_str());
		std::string checkIfNameExist = "SELECT `user` FROM `users` WHERE `user` = '" + user1 + "'";
		resultSet = stmt->executeQuery(checkIfNameExist.c_str());

		if (resultSet->next())
		{
			cuentaCreada = false;
		}
		else
		{
			cuentaCreada = true;
		}

		if (cuentaCreada == true && password1 == password2)
		{
			std::string insertUserPasswordQ = "insert into `users`(user,password,email) VALUES('" + user1 + "','" + password1 + "','" + email + "')";
			stmt->execute(insertUserPasswordQ.c_str());
			std::cout << "Te has registrado correctamente!" << std::endl << std::endl;
			cuentaCreada = true;
			logueado = true;
		}
		if (cuentaCreada == false || password1 != password2)
		{
			if (cuentaCreada == false)
			{
				std::cout << "Ya existe un usuario con ese nombre! Intente de nuevo!\n\n";
			}

			if (password1 != password2)
			{
				std::cout << "Las passwords no coinciden! Prueva otra vez!\n\n";
			}
			std::cout << "No the has podido registrar correctamente! Intentalo otra vez!\n\n";
		}

		delete resultSet;

		// GUARDA LA ID DEL USUARIO EN ID_USER CREADO O QUE PREVIEMENTE YA EXISTE
		std::string checkIdUser = "SELECT `id_user` FROM `users` WHERE `user` = '" + user1 + "'";

		resultSet = stmt->executeQuery(checkIdUser.c_str());
		resultSet->next();
		user_id = resultSet->getInt(1);
		//id_user = std::stoi(id_user_string);
		
	}



}

void ConectDataBase::CrearPersonaje()
{

	std::cout << "Creación de Personaje:\n";
	stmt = con->createStatement();

	std::cout << "Razas:\n";

	MostrarRazas();

	std::cout << "Introduce el id de tu raza:\n";

	std::cin >> idRace;
	std::string idRaceString = std::to_string(idRace);

	bool exists = true;
	while (exists == true)
	{
		std::cout << "Introduce nombre del personaje:\n";
		std::cin >> characterName;

		std::string checkIfCharacterExists = "SELECT `character` FROM `characters` WHERE `character` = '" + characterName + "'";
		resultSet = stmt->executeQuery(checkIfCharacterExists.c_str());

		if (resultSet->next())
		{
			std::cout << "Nombre de personaje ya en uso, elige uno nuevo:\n";
		}
		else
		{
			std::cout << "Nombre introducido correctamente\n";
			user_id_string = std::to_string(user_id);
			std::string createCharacter = "insert into characters(`character`, races_id_race, gold, users_id_user, `level`) VALUES('" + characterName + "'," + idRaceString + ", 0," + user_id_string + ", 1)";
			stmt->execute(createCharacter.c_str());
			std::cout << "El Personaje se ha creado correctamente\n";
			exists = false;
		}
	}
}

 void ConectDataBase::MostrarRazas()
{
	std::string str;
	int id = 0;

	std::vector<std::string> aRaces;
	std::string query = "SELECT `race`, id_race FROM `races` WHERE 1";
	sql::ResultSet* resultSet = stmt->executeQuery(query.c_str());

	for (int i = 0; resultSet->next(); i++)
	{

		str = resultSet->getString(1).c_str();
		std::cout << i << " - " << str << std::endl;
		aRaces.push_back(str);

	}
	delete resultSet;

}