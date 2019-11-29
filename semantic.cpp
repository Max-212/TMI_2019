#include "semantic.h"
#include "PolishNotation.h"
#include "IT.h"
#include"LT.h"
#include"In.h"
#include <vector>

void SA::GetFlags(char lexema, SA::Flags& flags)
{
	if (lexema == 'f') flags.flagDecFunction = true;
	else if (lexema == '(' && flags.flagDecFunction)  flags.flagParametres = true;
	else if (lexema == '(' && flags.flagCallFunction) flags.flagParametres = true;
	else if (lexema == ')' && flags.flagCallFunction)
	{
		flags.flagCallFunction = false;
		flags.flagParametres = false;
	}
	else if (lexema == '{' && flags.flagDecFunction)
	{
		flags.flagDecFunction = false;
		flags.flagParametres = false;
		flags.flagInFunction = true;
	}
}

int SA::CheckInFunctions(std::vector<SA::Function> functions, char* id)
{
	for (int i = 0; i < functions.size(); i++)
	{
		if (strcmp(functions[i].function.id, id) == 0) 
			return i;
	}
	return -1;
}

void SA::SemAnalysis(LA::Tables tables) 
{
	SA::Flags flags;
	std::vector<SA::Function> functions;
	int indID;
	  
	for (int i = 0; i < tables.LexTable.size; i++)
	{
		indID = tables.LexTable.table[i].indID;
		SA::GetFlags(tables.LexTable.table[i].lexema, flags);
		if (indID != TI_NULLIDX)
		{
			if (tables.idTable.table[indID].idtype == IT::F && flags.flagDecFunction) // записываем функцию в vector при объ€влении
			{
				functions.push_back({ tables.idTable.table[indID] });
			}
			else if (flags.flagParametres ) // записываем типы параметров в vector или провер€ем параметры при вызове
			{
				if(flags.flagDecFunction) // запись параметров функции
					functions[functions.size()-1].parameters.push_back(tables.idTable.table[indID].iddatatype);
				else if (flags.flagCallFunction) // проверка параметров
				{

				}
			}
			else if (CheckInFunctions(functions, tables.idTable.table[indID].id) != -1) // попали на вызов функции
			{
				flags.flagCallFunction = true;
			}
		}
	}
}