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

void FixID(LA::Tables& tables)
{
	int nLiteral = 1;
	char* buffer = new char[256];
	char* L = new char[256];
	L[0] = 'L';
	L[1] = '\0';

	for (int i = 0; i < tables.idTable.size; i++)
	{
		if (tables.idTable.table[i].idtype == IT::L)
		{
			itoa(nLiteral, buffer, 10);
			strcat(L, buffer);
			tables.idTable.table[i].id = L;
			L = NULL;
			buffer = NULL;
			L = new char(256);
			L[0] = 'L';
			L[1] = '\0';
			buffer = new char(256);
			nLiteral++;
		}
	}
	L = NULL;
	delete[]L;
	buffer = NULL;
	delete[]buffer;
}

void GEN::GetData(std::string &data, LA::Tables tables)
{

	for (int i = 0; i < tables.LexTable.size; i++)
	{
		if (tables.LexTable.table[i].lexema == 'v')
		{
			data += "\n\t";
			data += tables.idTable.table[tables.LexTable.table[i + 2].indID].id;
			if (tables.idTable.table[tables.LexTable.table[i + 2].indID].iddatatype == IT::BOOL)
				data += " DB ?";
			else if (tables.idTable.table[tables.LexTable.table[i + 2].indID].iddatatype == IT::INT)
				data += " DD ?";
			else if (tables.idTable.table[tables.LexTable.table[i + 2].indID].iddatatype == IT::STR)
				data += " DB ?";
		}
	}
	data += "\n\n";
}

void GEN::GetConst(std::string &code, LA::Tables tables)
{
	std::string value = "";
	for (int i = 0; i < tables.idTable.size; i++)
	{
		if (tables.idTable.table[i].idtype == IT::L)
		{	
			code += "\t";
			code += tables.idTable.table[i].id;
			if (tables.idTable.table[i].iddatatype == IT::INT)
			{
				code += " dd ";
				value = std::to_string(tables.idTable.table[i].value.vint);
				code += value;
			}
			else if (tables.idTable.table[i].iddatatype == IT::BOOL)
			{
				code += " db ";
				if (tables.idTable.table[i].value.vbool) value = "1";
				else value = "0";
				code += value;
			}
			else if (tables.idTable.table[i].iddatatype == IT::STR)
			{
				code += " db ";
				code += tables.idTable.table[i].value.vstr.str;
				code += " , 0";
			}
			code += "\n";
		}
	}
	code += "\n";
}

void GEN::GetCode(std::string &code, LA::Tables tables)
{
	GEN::Inf inf;
	for (int i = 0; i < tables.LexTable.size; i++)
	{
		if (tables.LexTable.table[i].lexema == 'f') // объявление функции
		{
			inf.inFunc = true;
			inf.indFun = tables.LexTable.table[i + 1].indID;
			i += 2;
			code += tables.idTable.table[inf.indFun].id;
			code += " PROC ";
			while (tables.LexTable.table[i].lexema != ')')
			{
				if (tables.LexTable.table[i].lexema == 'i')
				{
					inf.indI = tables.LexTable.table[i].indID;
					if (tables.idTable.table[inf.indI].iddatatype == IT::INT)
					{
						code += tables.idTable.table[inf.indI].id;
						code += " : dd ";
						if (tables.LexTable.table[i + 1].lexema != ')') code += ", ";
					}
					else if (tables.idTable.table[inf.indI].iddatatype == IT::BOOL)
					{
						code += tables.idTable.table[inf.indI].id;
						code += " : db ";
						if (tables.LexTable.table[i + 1].lexema != ')') code += ", ";
					}
					else if (tables.idTable.table[inf.indI].iddatatype == IT::STR)
					{
						code += tables.idTable.table[inf.indI].id;
						code += " : dd ";
						if (tables.LexTable.table[i + 1].lexema != ')') code += ", ";
					}
				}
				i++; 
			}
			code += "\n\n";
		}

		else if (tables.LexTable.table[i].lexema == '}') // конец функции или конец main
		{
			if (inf.inFunc)
			{
				code += tables.idTable.table[inf.indFun].id;
				code += " ENDP\n\n";
				inf.inFunc = false;
			}
			else if (inf.inStart)
			{
				code += "push 0\ncall ExitProcess\nmain ENDP\nend main";
			}
		}

		else if (tables.LexTable.table[i].lexema == 's') // main
		{
			code += "\nmain PROC\nSTART:\n\n";
			inf.inStart = true;
		}

		else if (tables.LexTable.table[i].lexema == 'r') // return
		{
			if (tables.idTable.table[inf.indFun].iddatatype == IT::STR)
			{
				code += "mov eax, offset ";
				code += tables.idTable.table[tables.LexTable.table[i + 1].indID].id;
				code += "\nret\n";
			}
			else
			{
				code += "mov eax, ";
				code += tables.idTable.table[tables.LexTable.table[i + 1].indID].id;
				code += "\nret\n";
			}
		}

		else if(tables.LexTable.table[i].lexema == 'w') // вывод в консоль
		{
			inf.indI = tables.LexTable.table[i + 2].indID;
			inf.id = tables.idTable.table[inf.indI].id;

			if (tables.idTable.table[inf.indI].iddatatype == IT::STR)
			{
				code += "push offset ";
				code += tables.idTable.table[inf.indI].id;
				code += "\ncall ConsoleStr\n\n";
			}
			else if (tables.idTable.table[inf.indI].iddatatype == IT::INT)
			{
				code += "push ";
				code += tables.idTable.table[inf.indI].id;
				code += "\ncall ConsoleInt\n\n";

			}
			else if (tables.idTable.table[inf.indI].iddatatype == IT::BOOL)
			{
				
				code += "push ";
				code += tables.idTable.table[inf.indI].id;
				code += "\ncall ConsoleBool\n\n";

			}

		}


	}
}

void GEN::Generation(wchar_t * file, LA::Tables tables, std::vector<SA::Function> funcs)
{
	GEN::AsmCode AsmCode;
	std::ofstream out(file);
	FixID(tables);
	GetData(AsmCode.Data, tables);
	GetConst(AsmCode.Const, tables);
	GetCode(AsmCode.Code, tables);
	
	out << AsmCode.Head;
	out << AsmCode.Stack;
	out << AsmCode.Const;
	out << AsmCode.Data;
	out << AsmCode.Code;
	
}