#include "semantic.h"
#include "PolishNotation.h"
#include "IT.h"
#include"LT.h"
#include"In.h"
#include <vector>

void SA::GetInf(char lexema, SA::Flags& flags) 
{
	if (lexema == 'f') flags.flagFunction = true;

}

void SA::SemAnalysis(LA::Tables tables) 
{
	SA::Flags flags;


	for (int i = 0; i < tables.LexTable.size; i++)
	{
		
	}
}