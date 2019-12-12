
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
		std::string Const = ".CONST\n\n";
		std::string Stack = ".STACK 4096\n";
		std::string Code = ".CODE\n\n";
		std::string Data = ".DATA\n";
		std::string Head = ".586P\n.MODEL FLAT, STDCALL\nincludelib kernel32.lib\nincludelib libucrt.lib\nEXTRN Strcmp: PROC\nEXTRN Strlen: PROC\nEXTRN ConsoleInt: PROC\nEXTRN ConsoleStr: PROC\nEXTRN ConsoleBool: PROC\nExitProcess PROTO : DWORD\n\n";
	};

	struct Inf
	{
		int indFun = -1;
		int indI = -1;
		int indExpr = -1;
		bool inFunc = false;
		bool inStart = false;
		std::string id = "";
		

	};

	void GetData(std::string& code, LA::Tables);
	void GetConst(std::string& code, LA::Tables);
	void GetCode(std::string &code, LA::Tables);
	void Generation(wchar_t * file, LA::Tables, std::vector<SA::Function>);


}