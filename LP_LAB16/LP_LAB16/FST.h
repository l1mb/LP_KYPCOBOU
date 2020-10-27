#pragma once
#include <vector>
#include <iostream>
#include "LT.h"
#include "IT.h"

#pragma region ALL_FST

#pragma region functions
#define FST_MAIN FST(5, LEX_MAIN,\
	NODE(1, RELATION('m', 1)),\
	NODE(1, RELATION('a', 2)),\
	NODE(1, RELATION('i', 3)),\
	NODE(1, RELATION('n', 4)),\
	NODE())

#define FST_PRINT FST(6, LEX_PRINT,\
	NODE(1, RELATION('p', 1)),\
	NODE(1, RELATION('r', 2)),\
	NODE(1, RELATION('i', 3)),\
	NODE(1, RELATION('n', 4)),\
	NODE(1, RELATION('t', 5)),\
	NODE())

#define FST_RETURN FST(7, LEX_RETURN,\
	NODE(1, RELATION('r', 1)),\
	NODE(1, RELATION('e', 2)),\
	NODE(1, RELATION('t', 3)),\
	NODE(1, RELATION('u', 4)),\
	NODE(1, RELATION('r', 5)),\
	NODE(1, RELATION('n', 6)),\
	NODE())

#define FST_DECLARE FST(8, LEX_DECLARE,\
	NODE(1, RELATION('d', 1)),\
	NODE(1, RELATION('e', 2)),\
	NODE(1, RELATION('c', 3)),\
	NODE(1, RELATION('l', 4)),\
	NODE(1, RELATION('a', 5)),\
	NODE(1, RELATION('r', 6)),\
	NODE(1, RELATION('e', 7)),\
	NODE())

#define FST_INTEGER FST(8, LEX_INTEGER,\
	NODE(1, RELATION('i', 1)),\
	NODE(1, RELATION('n', 2)),\
	NODE(1, RELATION('t', 3)),\
	NODE(1, RELATION('e', 4)),\
	NODE(1, RELATION('g', 5)),\
	NODE(1, RELATION('e', 6)),\
	NODE(1, RELATION('r', 7)),\
	NODE())

#define FST_STRING FST(7, LEX_STRING,\
	NODE(1, RELATION('s', 1)),\
	NODE(1, RELATION('t', 2)),\
	NODE(1, RELATION('r', 3)),\
	NODE(1, RELATION('i', 4)),\
	NODE(1, RELATION('n', 5)),\
	NODE(1, RELATION('g', 6)),\
	NODE())

#define FST_FUNCTION FST(9, LEX_FUNCTION,\
	NODE(1, RELATION('f', 1)),\
	NODE(1, RELATION('u', 2)),\
	NODE(1, RELATION('n', 3)),\
	NODE(1, RELATION('c', 4)),\
	NODE(1, RELATION('t', 5)),\
	NODE(1, RELATION('i', 6)),\
	NODE(1, RELATION('o', 7)),\
	NODE(1, RELATION('n', 8)),\
	NODE()\
)
#pragma endregion

#pragma region SYMBOLS
#define FST_LEFT_BRACKET FST(2, LEX_LEFTHESIS,\
	NODE(1, RELATION('(', 1)),\
	NODE()\
)
#define FST_LEFTSQUARE FST(2, LEX_LEFTSQUARE,\
	NODE(1, RELATION('[', 1)),\
	NODE()\
)
#define FST_RIGHTSQUARE FST(2, LEX_RIGHTSQUARE,\
	NODE(1, RELATION(']', 1)),\
	NODE()\
)
#define FST_RIGHT_BRACKET FST(2, LEX_RIGHTHESIS,\
	NODE(1, RELATION(')', 1)),\
	NODE()\
)
#define FST_LEFT_BRACE FST(2, LEX_RIGHTBRACE,\
	NODE(1, RELATION('{', 1)),\
	NODE()\
)
#define FST_RIGHT_BRACE FST(2, LEX_BRACELET,\
	NODE(1, RELATION('}', 1)),\
	NODE()\
)
#define FST_PLUS FST(2, LEX_PLUS,\
	NODE(1, RELATION('+', 1)),\
	NODE()\
)
#define FST_MINUS FST(2, LEX_MINUS,\
	NODE(1, RELATION('-', 1)),\
	NODE()\
)
#define FST_MULTI FST(2, LEX_STAR,\
	NODE(1, RELATION('*', 1)),\
	NODE()\
)
#define FST_DIVISION FST(2, LEX_DIRSLASH,\
	NODE(1, RELATION('/', 1)),\
	NODE()\
)

#define FST_PERCENT FST(2, LEX_PERCENT,\
	NODE(1, RELATION('%', 1)),\
	NODE()\
)

#define FST_COMMA FST(2, ',',\
	NODE(1, RELATION(',', 1)),\
	NODE()\
)
#define FST_SEMICOLON FST(2, ';',\
	NODE(1, RELATION(';', 1)),\
	NODE()\
)
#define FST_EQUALLY FST(2, '=',\
	NODE(1, RELATION('=', 1)),\
	NODE()\
)
#pragma endregion

#pragma region LITERALS
#define FST_NUMBERS FST(1, LEX_LITERAL,\
	NODE(10, RELATION('0', 0), RELATION('1', 0), RELATION('2', 0), RELATION('3', 0), RELATION('4', 0), RELATION('5', 0),\
	RELATION('6', 0), RELATION('7', 0), RELATION('8', 0), RELATION('9', 0)),\
	NODE()\
)

#define FST_ID FST(2, LEX_ID,\
	NODE(52,\
		RELATION('a', 0), RELATION('a', 1),\
		RELATION('b', 0), RELATION('b', 1),\
		RELATION('c', 0), RELATION('c', 1),\
		RELATION('d', 0), RELATION('d', 1),\
		RELATION('e', 0), RELATION('e', 1),\
		RELATION('f', 0), RELATION('f', 1),\
		RELATION('g', 0), RELATION('g', 1),\
		RELATION('h', 0), RELATION('h', 1),\
		RELATION('i', 0), RELATION('i', 1),\
		RELATION('j', 0), RELATION('j', 1),\
		RELATION('k', 0), RELATION('k', 1),\
		RELATION('l', 0), RELATION('l', 1),\
		RELATION('m', 0), RELATION('m', 1),\
		RELATION('n', 0), RELATION('n', 1),\
		RELATION('o', 0), RELATION('o', 1),\
		RELATION('p', 0), RELATION('p', 1),\
		RELATION('q', 0), RELATION('q', 1),\
		RELATION('r', 0), RELATION('r', 1),\
		RELATION('s', 0), RELATION('s', 1),\
		RELATION('t', 0), RELATION('t', 1),\
		RELATION('u', 0), RELATION('u', 1),\
		RELATION('v', 0), RELATION('v', 1),\
		RELATION('w', 0), RELATION('w', 1),\
		RELATION('x', 0), RELATION('x', 1),\
		RELATION('y', 0), RELATION('y', 1),\
		RELATION('z', 0), RELATION('z', 1)),\
	NODE()\
)

#define FST_STRING_LITERAL FST(4, LEX_LITERAL,\
	NODE(2, RELATION('\'', 1), RELATION('\'', 2)),\
	NODE(138,\
		RELATION('a', 1), RELATION('a', 2),\
		RELATION('b', 1), RELATION('b', 2),\
		RELATION('c', 1), RELATION('c', 2),\
		RELATION('d', 1), RELATION('d', 2),\
		RELATION('e', 1), RELATION('e', 2),\
		RELATION('f', 1), RELATION('f', 2),\
		RELATION('g', 1), RELATION('g', 2),\
		RELATION('h', 1), RELATION('h', 2),\
		RELATION('i', 1), RELATION('i', 2),\
		RELATION('j', 1), RELATION('j', 2),\
		RELATION('k', 1), RELATION('k', 2),\
		RELATION('l', 1), RELATION('l', 2),\
		RELATION('m', 1), RELATION('m', 2),\
		RELATION('n', 1), RELATION('n', 2),\
		RELATION('o', 1), RELATION('o', 2),\
		RELATION('p', 1), RELATION('p', 2),\
		RELATION('q', 1), RELATION('q', 2),\
		RELATION('r', 1), RELATION('r', 2),\
		RELATION('s', 1), RELATION('s', 2),\
		RELATION('t', 1), RELATION('t', 2),\
		RELATION('u', 1), RELATION('u', 2),\
		RELATION('v', 1), RELATION('v', 2),\
		RELATION('w', 1), RELATION('w', 2),\
		RELATION('x', 1), RELATION('x', 2),\
		RELATION('y', 1), RELATION('y', 2),\
		RELATION('z', 1), RELATION('z', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('�', 1), RELATION('�', 2),\
		RELATION('0', 1), RELATION('0', 2),\
		RELATION('1', 1), RELATION('1', 2),\
		RELATION('2', 1), RELATION('2', 2),\
		RELATION('3', 1), RELATION('3', 2),\
		RELATION('4', 1), RELATION('4', 2),\
		RELATION('5', 1), RELATION('5', 2),\
		RELATION('6', 1), RELATION('6', 2),\
		RELATION('7', 1), RELATION('7', 2),\
		RELATION('8', 1), RELATION('8', 2),\
		RELATION('9', 1), RELATION('9', 2),\
		RELATION(' ', 1), RELATION(' ', 2)), \
		NODE(1, RELATION('\'', 3)), \
		NODE())
#pragma endregion

#pragma endregion

#pragma region DATA_TYPES
#define INTEGER "integer"
#define STRING "string"
#pragma endregion

namespace FST {
	struct RELATION {			// �����:������ -> ������� ����� ��������� ��
		unsigned char symbol;			// ������ ��������
		short nnode;			// ����� ������� �������

		RELATION(char c = 0x00, short ns = NULL);
	};

	struct NODE {				// ������� ����� ���������
		short n_relation;		// ���������� ����������� �����
		RELATION* relations;	// ����������� �����

		NODE();
		NODE(short n, RELATION rel, ...);
	};

	struct FST {				// ������������������� �������� �������
		short position;		// ������� ������� � �������
		short nstates;			// ���������� ��������� ��������
		char symbol;			// ������ ������
		NODE* nodes;			// ���� ���������: [0] - ��������� ���������, [nstate-1] - ��������
		short* rstates;			// ��������� ��������� �������� �� ������ �������

		FST(short ns, char symbol, NODE n, ...);
		~FST();
	};

	// ��������� ������������� �������
	bool execute(FST& fst, std::string str);

	// ���
	void Recognize(std::vector<std::pair<int, std::string>> lexems, std::ostream* logfile, std::ofstream* outputFile,
		LT::LexTable& lextable, IT::IdTable& idtable);
};