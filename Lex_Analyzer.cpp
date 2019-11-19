#include <iostream>
#include "FST.h"
#include "Lex_Analyzer.h"
#include "In.h"
#include "Parm.h"
#include "Log.h"
#include <stack>


LA::Tables LA::Lex_analyz(In::IN in) {

	LA::Tables tables;
	tables.LexTable = LT::Create();
	tables.idTable	= IT::Create();


	int i = 0; // индекс по in.text
	int wordIndex = 0;

	if (in.text == (unsigned char*)' ') i++;
	int posWord = 0; // позиция слова в строке
	int line = 1; // текущая строка
	char* word = new char[256];

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
			std::cout << word << std::endl; //a
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
				std::cout << word << std::endl;
				
			}
		}
		else if (in.code[in.text[i]] == in.S) 
		{
			word[wordIndex++] = in.text[i++];
			word[wordIndex] = '\0';
			std::cout << word << std::endl;
			posWord++;
			wordIndex = 0;
		}
		else if (in.code[in.text[i]] == in.P) 
		{
			if (in.text[i] = IN_CODE_ENDL) 
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
