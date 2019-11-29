#pragma once
#include "IT.h"
#include"LT.h"
#include"In.h"
#include <vector>
#include "Lex_Analyzer.h"

namespace SA 
{
	struct Flags
	{
		bool flagDecFunction = false;   // обнаруженно объявление функции
		bool flagCallFunction = false;  // обнаружен вызов функции
		bool flagParametres = false;    // считывание параметров функции
		bool flagInFunction = false;    // вошли в блок функции
	};

	struct Function
	{
		IT::Entry function;
		std::vector<IT::IDDATATYPE> parameters;
	};

	void SemAnalysis(LA::Tables tables);

	void GetFlags(char lexema, SA::Flags& flags);

	int CheckInFunctions(std::vector<SA::Function> functions, char* id);
}
