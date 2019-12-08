
#pragma once
#include "IT.h"
#include"LT.h"
#include"In.h"
#include <vector>
#include "Lex_Analyzer.h"
#include "Log.h"
#include "semantic.h"
#include <string>
namespace GEN
{

	struct AsmCode
	{
		
		std::string Const = ".CONST\n";
		std::string Stack = ".STACK 4096\n";
		std::string Code = ".CODE\nmain PROC\nSTART:\n";
		std::string Data = ".DATA\n";
		std::string Struct = ".586P\n.MODEL FLAT, STDCALL\nincludelib kernel32.lib";
		std::string Proto = "\n\n";

	};

	void GetProto(std::vector<SA::Function> funcs, AsmCode &code);

	void Generation(wchar_t * file, LA::Tables, std::vector<SA::Function>);


}