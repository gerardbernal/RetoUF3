// 20180507.cpp : Defines the entry point for the console application.
//
#include <mysql_connection.h>
#include <cppconn\statement.h>
#include "ConectDataBase.h"
#include "Juego.h"


int main()
{
	ConectDataBase db;
	db.Menu();
	system("PAUSE");

	return 0;
}