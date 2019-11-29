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

using namespace std;


int wmain(int argc, wchar_t* argv[]) {

	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INTLOG;
	try
	{

		
		//Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog((wchar_t *)L"C:\\Лабы\\Курсач\\Тест\\log.log");
		//wcout << "-in:" << parm.in << ", -out" << parm.out << ", -log: " << parm.log << endl;
		In::IN in = In::getin((wchar_t *)L"C:\\Лабы\\Курсач\\Тест\\test1.txt");

		LA::Tables Tables = LA::Lex_analyz(in);
		////bool i = PN::PolishNotation(15, Tables.LexTable, Tables.idTable);
		////bool n = PN::PolishNotation(60, Tables.LexTable, Tables.idTable);


		LA::Inf inf;
		cout << inf.iddatatype;

		cout << "\n----------------------------|\n";
		cout << " № | лексема | номер строки |\n";
		cout << "----------------------------|\n";

		for (int i = 0; i < Tables.LexTable.size; i++) {
			cout << " " << Tables.LexTable.table[i].idxLT << " |    " << Tables.LexTable.table[i].lexema << "    |      " << Tables.LexTable.table[i].sn << "       |\t\t" << Tables.LexTable.table[i].indID << endl;
		}

		//cout << "________________________________\n";

		//char* iddatatype;
		//char* idtype;

		for (int i = 0; i < Tables.idTable.size; i++) 
		{
			cout << i << "|\t" << Tables.idTable.table[i].id << "\t\t\t\t" << Tables.idTable.table[i].idtype << "\t\t\t" << Tables.idTable.table[i].iddatatype << "\t\t" << Tables.idTable.table[i].idxfirstLE << endl;
		}

	

		//}

		MFST_TRACE_START
			MFST::Mfst mfst(Tables, GRB::getGreibach());
		mfst.start();
		mfst.printrules();

		/*Log::WriteLine(log, "Тест:", "без ошибок", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		*/
		Log::WriteIn(log, in);
		Log::Close(log);
	
	}
	catch (Error::ERROR error) {

		cout << "Ошибка " << error.id << ": " << error.message << ", строка " << error.inext.line << ",позиция " << error.inext.col << std::endl;
		Log::WriteError(log, error);
		system("pause");
	}
	system("pause");
}



