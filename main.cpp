#include <cwchar>
#include <iostream>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"
#include "LT.h"
#include "Lex_Analyzer.h"
#include <stack>
#include "PolishNotation.h"
#include "GRB.h"
#include "MFST.h"
#include "semantic.h"
#include "Generation.h"
#include <fstream>

using namespace std;


int wmain(int argc, wchar_t* argv[]) {

	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INTLOG;
	
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog((parm.log));
		//log = Log::getlog((wchar_t *)L"C:\\Лабы\\Курсач\\Тест\\log.log");
		//wcout << "-in:" << parm.in << ", -out" << parm.out << ", -log: " << parm.log << endl;
		In::IN in = In::getin(parm.in);
		//In::IN in = In::getin((wchar_t *)L"C:\\Лабы\\Курсач\\Тест\\MainTest.txt");

		LA::Tables Tables = LA::Lex_analyz(in);
		
		LA::Inf inf;
		cout << inf.iddatatype;

		cout << "\n----------------------------|\n";
		cout << " № | лексема | номер строки |\n";
		cout << "----------------------------|\n";

		for (int i = 0; i < Tables.LexTable.size; i++) {
			cout << " " << Tables.LexTable.table[i].idxLT << " |    " << Tables.LexTable.table[i].lexema << "    |      " << Tables.LexTable.table[i].sn << "       |\t\t" << Tables.LexTable.table[i].indID << endl;
		}


		for (int i = 0; i < Tables.idTable.size; i++) 
		{
			cout << i << "|\t" << Tables.idTable.table[i].id << "\t\t\t\t" << Tables.idTable.table[i].idtype << "\t\t\t" << Tables.idTable.table[i].iddatatype << "\t\t" << Tables.idTable.table[i].idxfirstLE << "\t\t" << Tables.idTable.table[i].value.vint <<  endl;
		}


		MFST_TRACE_START
			MFST::Mfst mfst(Tables, GRB::getGreibach());
		mfst.start();
		mfst.printrules();

		std::vector<SA::Function> functions = SA::SemAnalysis(Tables);

		cout << "\n----------------------------|\n";
		cout << " № | лексема | номер строки |\n";
		cout << "----------------------------|\n";

		for (int i = 0; i < Tables.LexTable.size; i++) {
			cout << " " << Tables.LexTable.table[i].idxLT << " |    " << Tables.LexTable.table[i].lexema << "    |      " << Tables.LexTable.table[i].sn << "       |\t\t" << Tables.LexTable.table[i].indID << "\t\t" << Tables.LexTable.table[i].operatorValue << endl;
		}
		GEN::Generation(parm.out, Tables, functions);
		//GEN::Generation((wchar_t *)L"C:\\Лабы\\Курсач\\Тест\\out.asm", Tables, functions);

		for (int i = 0; i < Tables.idTable.size; i++)
		{
			cout << i << "|\t" << Tables.idTable.table[i].id << "\t\t\t\t" << Tables.idTable.table[i].idtype << "\t\t\t" << Tables.idTable.table[i].iddatatype << "\t\t" << Tables.idTable.table[i].idxfirstLE << "\t\t" << Tables.idTable.table[i].value.vint << endl;
		}

		Log::WriteLine(log, "Тест:", "без ошибок", "");
		Log::WriteLog(log);
		Log::WriteIn(log, in);
		Log::WriteLine(log, "\n\n", "");

		char* iddatatype;
		char* idtype;
		char* indLT;
		char* value = (char*)"";

		for (int i = 0; i < Tables.idTable.size; i++)
		{
			switch (Tables.idTable.table[i].idtype)
			{
			case 1:idtype = (char*)"VARIABLE"; break;
			case 2:idtype = (char*)"FUNCTION"; break;
			case 3:idtype = (char*)"PARAMETR"; break;
			case 4: idtype = (char*)"LITERAL"; break;
			default:break;
			}
			switch (Tables.idTable.table[i].iddatatype)
			{
			case 1:
				iddatatype = (char*)"INT"; 
				/*itoa(Tables.idTable.table[i].value.vint, value, 10);*/
				//value = (char*)"0";
				break;
			case 2:
				iddatatype = (char*)"STR"; 
				//value = Tables.idTable.table[i].value.vstr.str;
				break;
			case 3:
				iddatatype = (char*)"BOOL"; 
				if (Tables.idTable.table[i].value.vbool) value = (char*)"true";
				else value = (char*)"false";
				break;
			default:break;
			}
			
			Log::WriteLine(log, iddatatype, "\t\t", idtype, "\t\t", value, "\t\t", Tables.idTable.table[i].id, "\n", ""); /*"\t\t", indLT,  "\n", "");*/
		}

		Log::WriteLine(log, "\n\n", "");
		
		Log::Close(log);
	
	}
	catch (Error::ERROR error) {

		cout << "Ошибка " << error.id << ": " << error.message << ", строка " << error.inext.line << ",позиция " << error.inext.col << std::endl;
		Log::WriteError(log, error);
		system("pause");
	}
	system("pause");
}



