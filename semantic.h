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
		bool flagDecFunction = false;   // ����������� ���������� �������
		bool flagCallFunction = false;  // ��������� ����� �������
		bool flagParametres = false;    // ���������� ���������� �������
		bool flagInFunction = false;    // ����� � ���� �������
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
