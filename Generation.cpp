#pragma once
#include "IT.h"
#include"LT.h"
#include"In.h"
#include <vector>
#include "Lex_Analyzer.h"
#include "Log.h"
#include "Generation.h"
#include "semantic.h"
#include <string>



void GEN::GetProto(std::vector<SA::Function> funcs, GEN::AsmCode &code) 
{
	char* datatype;
	for (int i = 0; i < funcs.size(); i++)
	{
		code.Proto += funcs[i].function.id;
		code.Proto += " PROTO: ";
		for (int j = 0; j < funcs[i].parameters.size(); j++)
		{
			if (funcs[i].parameters[j] == IT::INT) datatype = (char*)"DD";
			else if (funcs[i].parameters[j] == IT::BOOL) datatype = (char*)"DB";
			else if (funcs[i].parameters[j] == IT::STR)  datatype = (char*)"DB";

			if (j + 1 != funcs[i].parameters.size())
			{
				code.Proto += datatype;
				code.Proto += ", : ";
			}
			else
			{
				code.Proto += datatype;
				code.Proto += "\n";
			}
		}
	}
	code.Proto += "\n";
}

void GEN::Generation(wchar_t * file, LA::Tables tables, std::vector<SA::Function> funcs)
{
	GEN::AsmCode AsmCode;

	std::ofstream out(file);

	GEN::GetProto(funcs, AsmCode);


	
	out << AsmCode.Struct;
	out << AsmCode.Proto;
	out << AsmCode.Stack;
	out << AsmCode.Const;
	out << AsmCode.Data;
	out << AsmCode.Code;
	
}