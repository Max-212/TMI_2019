#pragma once
#include "FST.h"
#include "Log.h"
#include "IT.h"
#include"LT.h"
#include"In.h"
#include <vector>

#define N_GRAPHS 22
#define LIBFUNCTIONS 2

#define GRAPH_string  (7,   \
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('t', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE(1, FST::RELATION('i', 4)), \
FST::NODE(1, FST::RELATION('n', 5)), \
FST::NODE(1, FST::RELATION('g', 6)), \
FST::NODE())

#define GRAPH_integer (4,	\
FST::NODE(1, FST::RELATION('i', 1)),\
FST::NODE(1, FST::RELATION('n', 2)),\
FST::NODE(1, FST::RELATION('t', 3)),\
FST::NODE())

#define GRAPH_bool  (5,   \
FST::NODE(1, FST::RELATION('b', 1)), \
FST::NODE(1, FST::RELATION('o', 2)), \
FST::NODE(1, FST::RELATION('o', 3)), \
FST::NODE(1, FST::RELATION('l', 4)), \
FST::NODE())

#define GRAPH_print (6,\
FST::NODE(1, FST::RELATION('w', 1)),\
FST::NODE(1, FST::RELATION('r', 2)),\
FST::NODE(1, FST::RELATION('i', 3)),\
FST::NODE(1, FST::RELATION('t', 4)),\
FST::NODE(1, FST::RELATION('e', 5)),\
FST::NODE())

#define GRAPH_if  (3,   \
FST::NODE(1, FST::RELATION('i', 1)), \
FST::NODE(1, FST::RELATION('f', 2)), \
FST::NODE())

#define GRAPH_function (5,\
FST::NODE(1, FST::RELATION('F', 1)),\
FST::NODE(1, FST::RELATION('u', 2)),\
FST::NODE(1, FST::RELATION('n', 3)),\
FST::NODE(1, FST::RELATION('c', 4)),\
FST::NODE())

#define GRAPH_start ( 6,\
FST::NODE(1, FST::RELATION('s', 1)),\
FST::NODE(1, FST::RELATION('t', 2)),\
FST::NODE(1, FST::RELATION('a', 3)),\
FST::NODE(1, FST::RELATION('r', 4)),\
FST::NODE(1, FST::RELATION('t', 5)),\
FST::NODE())

#define GRAPH_var (4,\
FST::NODE(1, FST::RELATION('v', 1)),\
FST::NODE(1, FST::RELATION('a', 2)),\
FST::NODE(1, FST::RELATION('r', 3)),\
FST::NODE()) 

#define GRAPH_return (7,\
FST::NODE(1, FST::RELATION('r', 1)),\
FST::NODE(1, FST::RELATION('e', 2)),\
FST::NODE(1, FST::RELATION('t', 3)),\
FST::NODE(1, FST::RELATION('u', 4)),\
FST::NODE(1, FST::RELATION('r', 5)),\
FST::NODE(1, FST::RELATION('n', 6)),\
FST::NODE())

#define GRAPH_integer_literal (3,\
FST::NODE(20, FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
	FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
	FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2)),\
\
FST::NODE(20, FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
	FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
	FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2)),\
FST::NODE())


#define GRAPH_integerx8_literal (4,\
FST::NODE(16, FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('0', 1),\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
	FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
	FST::RELATION('7', 2), FST::RELATION('0', 2)),\
\
FST::NODE(16, FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('0', 1),\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
	FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
	FST::RELATION('7', 2), FST::RELATION('0', 2)),\
FST::NODE(1, FST::RELATION('o', 3)),\
FST::NODE())

#define GRAPH_id (3, FST::NODE(72, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
	FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
	FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
	FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
	FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
	FST::RELATION('y', 1), FST::RELATION('z', 1),\
	FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), \
	FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), \
	FST::RELATION('9', 1), FST::RELATION('0', 1),\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), \
	FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
	FST::RELATION('9', 2), FST::RELATION('0', 2),\
	FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), \
	FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2), \
	FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
	FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), \
	FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2), \
	FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
	FST::RELATION('y', 2), FST::RELATION('z', 2)), \
FST::NODE(72, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
	FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
	FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
	FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
	FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
	FST::RELATION('y', 1), FST::RELATION('z', 1), \
	FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
	FST::RELATION('8', 1), FST::RELATION('9', 1), \
	FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), \
	FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2), \
	FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
	FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), \
	FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2), \
	FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
	FST::RELATION('y', 2), FST::RELATION('z', 2), \
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), \
	FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
	FST::RELATION('9', 2), FST::RELATION('0', 2)), \
FST::NODE())


#define GRAPH_string_literal (3, FST::NODE(1, FST::RELATION('\'', 1)), \
FST::NODE(153, \
	FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
	FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
	FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
	FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
	FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
	FST::RELATION('y', 1), FST::RELATION('z', 1), \
	FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), \
	FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), \
	FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1), \
	FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), \
	FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1), \
	FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), \
	FST::RELATION('Y', 1), FST::RELATION('Z', 1), \
	FST::RELATION('À', 1), FST::RELATION('Á', 1), FST::RELATION('Â', 1), FST::RELATION('Ã', 1), \
	FST::RELATION('Ä', 1), FST::RELATION('Å', 1), FST::RELATION('¨', 1), FST::RELATION('Æ', 1), \
	FST::RELATION('Ç', 1), FST::RELATION('È', 1), FST::RELATION('É', 1), FST::RELATION('Ë', 1), \
	FST::RELATION('Ì', 1), FST::RELATION('Í', 1), FST::RELATION('Î', 1), FST::RELATION('Ï', 1), \
	FST::RELATION('Ð', 1), FST::RELATION('Ñ', 1), FST::RELATION('Ò', 1), FST::RELATION('Ó', 1), \
	FST::RELATION('Ô', 1), FST::RELATION('Õ', 1), FST::RELATION('Ö', 1), FST::RELATION('×', 1), \
	FST::RELATION('Ø', 1), FST::RELATION('Ù', 1), FST::RELATION('Ú', 1), FST::RELATION('Û', 1), \
	FST::RELATION('Ü', 1),\
	FST::RELATION('Ý', 1), FST::RELATION('Þ', 1), FST::RELATION('ß', 1), \
	FST::RELATION('Ê', 1), \
	FST::RELATION('à', 1), FST::RELATION('á', 1), FST::RELATION('â', 1), FST::RELATION('ã', 1), \
	FST::RELATION('ä', 1), FST::RELATION('å', 1), FST::RELATION('¸', 1), FST::RELATION('æ', 1), \
	FST::RELATION('ç', 1), FST::RELATION('è', 1), FST::RELATION('é', 1), FST::RELATION('ë', 1), \
	FST::RELATION('ì', 1), FST::RELATION('í', 1), FST::RELATION('î', 1), FST::RELATION('ï', 1), \
	FST::RELATION('ð', 1), FST::RELATION('ñ', 1), FST::RELATION('ò', 1), FST::RELATION('ó', 1), \
	FST::RELATION('ô', 1), FST::RELATION('÷', 1), FST::RELATION('ö', 1), FST::RELATION('÷', 1), \
	FST::RELATION('ø', 1), FST::RELATION('ù', 1), FST::RELATION('ú', 1), FST::RELATION('û', 1), \
	FST::RELATION('ü', 1), FST::RELATION('ý', 1), FST::RELATION('þ', 1), FST::RELATION('ÿ', 1), \
	FST::RELATION('ê', 1), \
	FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
	FST::RELATION('8', 1), FST::RELATION('9', 1), \
	FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1), \
	FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1), \
	FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1), \
	FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1), \
	FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('#', 1), FST::RELATION('&', 1), \
	FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1), \
	FST::RELATION('\'', 2)), \
FST::NODE())

#define GRAPH_SEMICOLON (2,FST::NODE(1, FST::RELATION(';', 1)),\
	FST::NODE())

#define GRAPH_COMMA (2,FST::NODE(1, FST::RELATION(',', 1)),\
	FST::NODE())

#define GRAPH_LEFTBRCE (2,FST::NODE(1, FST::RELATION('{', 1)),\
	FST::NODE())

#define GRAPH_BRACELET (2,FST::NODE(1, FST::RELATION(' }', 1)),\
	FST::NODE())

#define GRAPH_LEFTHESIS (2,FST::NODE(1, FST::RELATION('(', 1)),\
	FST::NODE())

#define GRAPH_RIGHTHESIS (2,FST::NODE(1, FST::RELATION(')', 1)),\
	FST::NODE())

#define GRAPH_PLUS (2,FST::NODE(1, FST::RELATION('+', 1)),\
	FST::NODE())

#define GRAPH_MINUS (2,FST::NODE(1, FST::RELATION('-', 1)),\
	FST::NODE())

#define GRAPH_START (2,FST::NODE(1, FST::RELATION('*', 1)),\
	FST::NODE())

#define GRAPH_percent (2,FST::NODE(1, FST::RELATION('%', 1)),\
	FST::NODE())



#define GRAPH_DIRSLASH (2,FST::NODE(1, FST::RELATION('/', 1)),\
	FST::NODE())

#define GRAPH_EQUAL (2,FST::NODE(1, FST::RELATION('=', 1)),\
	FST::NODE())

#define GRAPH_equality (3,\
FST::NODE(1, FST::RELATION('=', 1)),\
FST::NODE(1, FST::RELATION('=', 2)),\
FST::NODE())



namespace LA {
	
	struct Machines
	{
		char lexema;
		FST::FST machine;
	};
	
	struct Tables 
	{
		LT::LexTable LexTable;
		IT::IdTable  idTable;
	};

	struct Inf 
	{
		IT::IDDATATYPE iddatatype = IT::IDDATATYPE::NODEF;
		IT::IDTYPE idtype = IT::IDTYPE::V;
		char* prefix = new char(256);
		bool flagInFunc = false;
		bool flagParam = false;
		bool flagFunc = false;
		std::vector<const char*> functions;
	};

	void InTables(LA::Tables& tables, int posword, int line, char* word, LA::Inf& inf);

	Tables Lex_analyz(In::IN in);	

	void GetInf(LA::Inf& inf, char *word);

	bool CheckInVector(std::vector<const char*> vector, const char* word);
}