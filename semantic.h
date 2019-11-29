#pragma once
#include "IT.h"
#include"LT.h"
#include"In.h"
#include <vector>
#include "Lex_Analyzer.h"

namespace SA 
{
	struct Flags
	{
		bool flagFunction = false;
	};
	void SemAnalysis(LA::Tables tables);

	void GetInf(char lexema, SA::Flags& flags);

}
