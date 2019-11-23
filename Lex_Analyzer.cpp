#include <iostream>
#include "FST.h"
#include "Lex_Analyzer.h"
#include "In.h"
#include "Parm.h"
#include "Log.h"
#include <stack>
#include <string>
#include <vector>

bool LA::CheckInVector(std::vector<const char*> vector, const char* word)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (strcmp(word, vector[i]) == 0) return true;
	}
	return false;
}

void LA::InTables(LA::Tables& tables, int posword, int line, char* word, LA::Inf& inf)
{
	LA::Machines machines[N_GRAPHS] = {
		{LEX_INTEGER   , FST::FST GRAPH_integer				},
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
		{LEX_LITERAL   , FST::FST GRAPH_integerx8_literal	},
		{LEX_LITERAL   , FST::FST GRAPH_integer_literal		},
		{LEX_LITERAL   , FST::FST GRAPH_string_literal		},
		{LEX_ID		   , FST::FST GRAPH_id					},
	};
	
	char lexema = (char)"";
	int indexIT = -1; 
	bool executeFlag = 0;
	bool IdFlag = 0;

	for (int i = 0; i < N_GRAPHS; i++)
	{
		if (FST::execute(machines[i].machine, word))
		{
			if (machines[i].lexema == 'i' || machines[i].lexema == 'l')
			{
				if (i == N_GRAPHS - 4)
				{
					inf.iddatatype = IT::IDDATATYPE::INT8;
					inf.idtype = IT::IDTYPE::L;
				}
				else if (i == N_GRAPHS - 3)
				{
					inf.iddatatype = IT::IDDATATYPE::INT;
					inf.idtype = IT::IDTYPE::L;
				}
				else if (i == N_GRAPHS - 2)
				{
					inf.iddatatype = IT::IDDATATYPE::STR;
					inf.idtype = IT::IDTYPE::L;
				}	
				IdFlag = true;
			}
			executeFlag = true;
			lexema = machines[i].lexema;
			break;
		}
	}
	if (executeFlag)
	{	
		if (IdFlag)
		{
			if (CheckInVector(inf.functions, (const char*)word));
			else if (inf.flagInFunc)
			{
				strcat(word, "_");
				strcat(word, inf.prefix);
			}
			indexIT = IT::IsId(tables.idTable, word);
			if(indexIT != TI_NULLIDX && inf.iddatatype != IT::IDDATATYPE::NODEF) throw Error::geterrorin(123, line, posword); // повторная инициализация
			if (indexIT == TI_NULLIDX) // добавляем в таблицу индентификаторов
			{
				if(inf.iddatatype == IT::IDDATATYPE::NODEF) throw Error::geterrorin(122, line, posword); // использование без объявления
				indexIT = tables.idTable.size;
				IT::Add(tables.idTable, { tables.LexTable.size, word, inf.iddatatype, inf.idtype , 0});
				inf.iddatatype = IT::IDDATATYPE::NODEF;
				inf.idtype = IT::IDTYPE::V;
			}
		} 
		LT::Add(tables.LexTable, {lexema, line, tables.LexTable.size, indexIT, word[0]});
		//word = NULL;
	}
	else throw Error::geterrorin(113, line, posword);
}

void LA::GetInf(LA::Inf& inf, char *word)
{
	if (strcmp(word, "int") == 0) inf.iddatatype = IT::IDDATATYPE::INT;
	else if (strcmp(word, "string") == 0) inf.iddatatype = IT::IDDATATYPE::STR;
	else if (strcmp(word, "bool") == 0) inf.iddatatype = IT::IDDATATYPE::BOOL;
	else if (strcmp(word, "Func") == 0)
	{
		inf.idtype = IT::IDTYPE::F;
		inf.flagFunc = true;
	}
	else if (strcmp(word, "(") == 0 && inf.flagFunc) 
	{
		inf.flagParam = true;
		inf.flagInFunc = true;
	}
	else if (strcmp(word, ")") == 0 && inf.flagFunc)
	{
		inf.flagParam = false;
		inf.flagFunc = false;
	}
	else if (inf.idtype == IT::IDTYPE::F || strcmp(word, "start") == 0)
	{
		for (int i = 0; i <= strlen(word); i++) inf.prefix[i] = word[i];
		if(strcmp(word,"start") != 0) inf.functions.push_back((const char*)word);
	}
	else if (strcmp(word, "{") == 0) inf.flagInFunc = true;
	else if (strcmp(word, "}") == 0) 
	{
		inf.prefix = NULL;
		inf.prefix = new char(256);
		inf.flagInFunc = false;
	}
}

LA::Tables LA::Lex_analyz(In::IN in) {

	LA::Tables tables;
	tables.LexTable = LT::Create();
	tables.idTable	= IT::Create();
	LA::Inf inf;
	inf.functions.push_back("strlen");

	int i = 0; // индекс по in.text
	int wordIndex = 0;
	int posWord = 0; // позиция слова в строке
	int line = 1; // текущая строка
	char* word = new char[256];

	if (in.text == (unsigned char*)' ') i++;
	while (i < in.size)
	{
		if (in.text[i] == '\'')
		{
			while (true)
			{
				word[wordIndex++] = in.text[i++];
				posWord++;
				if (in.text[i] == '\n')
				{
					line++;
					posWord = 0;
				}
				if (in.text[i] == '\'' || in.text[i] == '\0') break;
			}
			word[wordIndex++] = in.text[i++];
			word[wordIndex] = '\0';
			GetInf(inf, word);
			InTables(tables, posWord, line, word, inf);
			word = NULL;
			word = new char[256];
			wordIndex = 0;
		}
		else if (in.code[in.text[i]] == in.T) 
		{
			while (in.code[in.text[i]] == in.T) 
			{
				word[wordIndex++] = in.text[i++];
				posWord++;
			}
			if (in.code[in.text[i]] == in.S || in.code[in.text[i]] == in.P || in.code[in.text[i]] == in.Q)
			{
				word[wordIndex] = '\0';
				wordIndex = 0;
				GetInf(inf, word);
				InTables(tables, posWord, line, word, inf);
				word = NULL;
				word = new char[256];
			}
		}
		else if (in.code[in.text[i]] == in.S) 
		{
			word[wordIndex++] = in.text[i++];
			word[wordIndex] = '\0';
			GetInf(inf, word);
			InTables(tables, posWord, line, word, inf);
			posWord++;
			wordIndex = 0;
			word = NULL;
			word = new char[256];
		}
		else if (in.code[in.text[i]] == in.P) 
		{
			if (in.text[i] == IN_CODE_ENDL) 
			{
				line++;
				posWord = 0;	
			}
			wordIndex = 0;
			i++;
		}
	}
	return tables;
}