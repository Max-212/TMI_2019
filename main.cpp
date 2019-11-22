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

		/*LA::Machines machines[N_GRAPHS] = {

		{LEX_INTEGER   , FST::FST GRAPH_integer				},
		{LEX_INTEGERx8 , FST::FST GRAPH_integerx8_literal	},
		{LEX_STRING    , FST::FST GRAPH_string				},
		{LEX_WRITE     , FST::FST GRAPH_print				},
		{LEX_FUNCTION  , FST::FST GRAPH_function			},
		{LEX_VAR	   , FST::FST GRAPH_var					},
		{LEX_START     , FST::FST GRAPH_start				},
		{LEX_RETURN    , FST::FST GRAPH_return				},
		{LEX_COMMA     , FST::FST GRAPH_COMMA				},
		{LEX_LEFTHESIS , FST::FST GRAPH_LEFTHESIS			},
		{LEX_RIGHTHESIS, FST::FST GRAPH_RIGHTHESIS			},
		{LEX_LEFTBRACE , FST::FST GRAPH_LEFTBRCE			},
		{LEX_BRACELET  , FST::FST GRAPH_BRACELET			},
		{LEX_DIRSLASH  , FST::FST GRAPH_DIRSLASH			},
		{LEX_MINUS     , FST::FST GRAPH_MINUS				},
		{LEX_PLUS      , FST::FST GRAPH_PLUS				},
		{LEX_SEMICOLON , FST::FST GRAPH_SEMICOLON			},
		{LEX_STAR      , FST::FST GRAPH_START				},
		{LEX_EQUAL     , FST::FST GRAPH_EQUAL				},
		{LEX_ID		   , FST::FST GRAPH_id					},
		{LEX_LITERAL   , FST::FST GRAPH_integer_literal		},
		{LEX_LITERAL   , FST::FST GRAPH_string_literal		},
		};

		if (FST::execute(machines[19].machine, (char*)""))
			std::cout << "ХОрошо" << endl;
		else
			cout << "Плохо" << endl;*/
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
			cout <<Tables.idTable.table[i].id << "\t\t" << Tables.idTable.table[i].idtype << "\t\t" << Tables.idTable.table[i].iddatatype << endl;
		}



		//}

		/*MFST_TRACE_START
			MFST::Mfst mfst(Tables, GRB::getGreibach());
		mfst.start();
		mfst.printrules();
*/
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



