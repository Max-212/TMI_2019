#include <iostream>
#include "FST.h"
#include "Lex_Analyzer.h"
#include "In.h"
#include "Parm.h"
#include "Log.h"
#include <stack>

In::IN LA::del_extra(In::IN in) {

	In::IN newIn;
	newIn = in;
	int size = 0;
	unsigned char* buffText1 = new unsigned char[in.size+1];
	unsigned char* buffText2 = new unsigned char[strlen((const char*)buffText1) + 1];

	// �������� ������ ������ ��������
	int i = 0;
	int j = 0;
	while (i <= strlen((const char*)in.text)) 
	{
		if (in.code[in.text[i]] == in.P && in.text[i] != IN_CODE_ENDL) 
		{
			while (in.code[in.text[i]] == in.P && in.text[i] != IN_CODE_ENDL) i++;
			buffText1[j++] = in.text[i - 1];
		}
		buffText1[j++] = in.text[i++];
	}

	// �������� �������� ����� �����������
	j = 0;
	i = 0;
	while (i <= strlen((const char*)buffText1))
	{
		if (in.code[buffText1[i]] == in.P && in.code[buffText1[i-1]] == in.T && in.code[buffText1[i + 1]] == in.T) buffText2[j++] = buffText1[i++];
		else if(in.code[buffText1[i]] == in.P && buffText1[i] != IN_CODE_ENDL)
		{
			i++;
		}
		else buffText2[j++] = buffText1[i++];
		
	}
	buffText2[j] = '\0';
	
	newIn.text = buffText2;
	newIn.size = j + 1;

	buffText1 = nullptr;
	buffText2 = nullptr;
	delete[] buffText1;
	delete[] buffText2;

	return newIn;
}

LA::Tables LA::Lex_analyz(In::IN in) {

	LA::Tables tables;
	tables.LexTable = LT::Create();
	tables.idTable	= IT::Create();


	int i = 0; // ������ �� in.text
	int wordIndex = 0;

	if (in.text == (unsigned char*)' ') i++;
	int posWord = 0; // ������� ����� � ������
	int line = 1; // ������� ������
	char* word = new char[256];

	while (i < in.size)
	{
		if (in.code[in.text[i]] == in.T) 
		{
			while (in.code[in.text[i]] == in.T) 
			{
				word[wordIndex++] = in.text[i++];
				posWord++;
			}
			if (in.code[in.text[i]] == in.S || in.code[in.text[i]] == in.P)
			{
				word[wordIndex] = '\0';
				wordIndex = 0;
				std::cout << word << std::endl;
				
			}
		}
		if (in.code[in.text[i]] == in.S) 
		{
			word[wordIndex++] = in.text[i++];
			word[wordIndex] = '\0';
			std::cout << word << std::endl;
			posWord++;
			wordIndex = 0;
		}
		if (in.code[in.text[i]] == in.P) 
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
