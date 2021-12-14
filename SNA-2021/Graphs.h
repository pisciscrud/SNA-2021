#pragma once
#include "FST.h"

#pragma region �������������

#define FST_CREATE 7,	\
	FST::NODE(1, FST::RELATION('c', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('e', 3)),\
	FST::NODE(1, FST::RELATION('a', 4)),\
	FST::NODE(1, FST::RELATION('t', 5)),\
	FST::NODE(1, FST::RELATION('e', 6)),\
	FST::NODE()

#define FST_NUM 4,	\
	FST::NODE(1, FST::RELATION('n', 1)),\
	FST::NODE(1, FST::RELATION('u', 2)),\
	FST::NODE(1, FST::RELATION('m', 3)),\
	FST::NODE()
//del
#define FST_BOOL 5,	\
	FST::NODE(1, FST::RELATION('b', 1)),\
	FST::NODE(1, FST::RELATION('o', 2)),\
	FST::NODE(1, FST::RELATION('o', 3)),\
	FST::NODE(1, FST::RELATION('l', 4)),\
	FST::NODE()

#define FST_STRING 7,	\
	FST::NODE(1, FST::RELATION('s', 1)),\
	FST::NODE(1, FST::RELATION('t', 2)),\
	FST::NODE(1, FST::RELATION('r', 3)),\
	FST::NODE(1, FST::RELATION('i', 4)),\
	FST::NODE(1, FST::RELATION('n', 5)),\
	FST::NODE(1, FST::RELATION('g', 6)),\
	FST::NODE()
//del
#define FST_CHAR 5,	\
	FST::NODE(1, FST::RELATION('c', 1)),\
	FST::NODE(1, FST::RELATION('h', 2)),\
	FST::NODE(1, FST::RELATION('a', 3)),\
	FST::NODE(1, FST::RELATION('r', 4)),\
	FST::NODE()

#define FST_FUNC 5,	\
	FST::NODE(1, FST::RELATION('f', 1)),\
	FST::NODE(1, FST::RELATION('u', 2)),\
	FST::NODE(1, FST::RELATION('n', 3)),\
	FST::NODE(1, FST::RELATION('c', 4)),\
	FST::NODE()

#define FST_BACK 5,	\
	FST::NODE(1, FST::RELATION('b', 1)),\
	FST::NODE(1, FST::RELATION('a', 2)),\
	FST::NODE(1, FST::RELATION('c', 3)),\
	FST::NODE(1, FST::RELATION('k', 4)),\
	FST::NODE()

#define FST_PROCESS 8,	\
	FST::NODE(1, FST::RELATION('p', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('o', 3)),\
	FST::NODE(1, FST::RELATION('c', 4)),\
	FST::NODE(1, FST::RELATION('e', 5)),\
	FST::NODE(1, FST::RELATION('s', 6)),\
	FST::NODE(1, FST::RELATION('s', 7)),\
	FST::NODE()
//�������
#define FST_COND 5,	\
	FST::NODE(1, FST::RELATION('c', 1)),\
	FST::NODE(1, FST::RELATION('o', 2)),\
	FST::NODE(1, FST::RELATION('n', 3)),\
	FST::NODE(1, FST::RELATION('d', 4)),\
	FST::NODE()
//else
#define FST_OTHER 6,	\
	FST::NODE(1, FST::RELATION('o', 1)),\
	FST::NODE(1, FST::RELATION('t', 2)),\
	FST::NODE(1, FST::RELATION('h', 3)),\
	FST::NODE(1, FST::RELATION('e', 4)),\
	FST::NODE(1, FST::RELATION('r', 5)),\
	FST::NODE()
//main
#define FST_EKLER 6,	\
	FST::NODE(1, FST::RELATION('E', 1)),\
	FST::NODE(1, FST::RELATION('K', 2)),\
	FST::NODE(1, FST::RELATION('L', 3)),\
	FST::NODE(1, FST::RELATION('E', 4)),\
	FST::NODE(1, FST::RELATION('R', 5)),\
	FST::NODE()

#define FST_REPLAY 7, \
	FST::NODE(1, FST::RELATION('r', 1)),\
	FST::NODE(1, FST::RELATION('e', 2)),\
	FST::NODE(1, FST::RELATION('p', 3)),\
	FST::NODE(1, FST::RELATION('l', 4)),\
	FST::NODE(1, FST::RELATION('a', 5)),\
	FST::NODE(1, FST::RELATION('y', 6)),\
	FST::NODE()
#pragma endregion
//105_p
#pragma region �������������

#define FST_ID 2,	\
	FST::NODE(62,	\
	FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('c', 0), FST::RELATION('d', 0), FST::RELATION('e', 0), FST::RELATION('f', 0),\
	FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('i', 0), FST::RELATION('j', 0), FST::RELATION('k', 0), FST::RELATION('l', 0),\
	FST::RELATION('m', 0), FST::RELATION('n', 0), FST::RELATION('o', 0), FST::RELATION('p', 0), FST::RELATION('q', 0), FST::RELATION('r', 0),\
	FST::RELATION('s', 0), FST::RELATION('t', 0), FST::RELATION('u', 0), FST::RELATION('v', 0), FST::RELATION('w', 0), FST::RELATION('x', 0),\
	FST::RELATION('y', 0), FST::RELATION('z', 0),\
	\
	FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),\
	FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),\
	FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
	FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1)),\
	FST::NODE()
#pragma endregion

#pragma region ������������� ��������
//06_p
#define FST_INTLIT 5, \
    FST::NODE(19,	\
	FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 2),\
	\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2),\
	FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2)),\
	FST::NODE(20,	\
	FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),\
	\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2),\
	FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2)),\
    FST::NODE(1,FST::RELATION('_', 3)),\
    FST::NODE(2,FST::RELATION('p', 4), FST::RELATION('n', 4)),\
	FST::NODE()

#define FST_INTLITBIN 6,	\
	FST::NODE(4,	\
	FST::RELATION('1', 0),FST::RELATION('0', 0), \
	\
	FST::RELATION('1', 1),FST::RELATION('0', 1)), \
	\
    FST::NODE(1, FST::RELATION('_', 2)),\
    FST::NODE(2,FST::RELATION('p', 3), FST::RELATION('n', 3)),\
    FST::NODE(1, FST::RELATION('X', 4)),\
    FST::NODE(1, FST::RELATION('2', 5)),\
	FST::NODE()

#define FST_INTLITOCT 7,	\
	FST::NODE(15,	\
	FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),FST::RELATION('6', 0),FST::RELATION('7', 1),FST::RELATION('0', 4),FST::RELATION('1', 4),FST::RELATION('2', 4),FST::RELATION('3', 4),FST::RELATION('4', 4),FST::RELATION('5', 4),FST::RELATION('6', 4),FST::RELATION('7', 4)),\
    FST::NODE(16,	\
	FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 3),FST::RELATION('7', 1), FST::RELATION('0', 1),\
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 4),FST::RELATION('7', 2),FST::RELATION('0', 2)),\
	\
      FST::NODE(1, FST::RELATION('_', 3)),\
    FST::NODE(2,FST::RELATION('p', 4), FST::RELATION('n', 4)),\
    FST::NODE(1, FST::RELATION('X', 5)),\
    FST::NODE(1, FST::RELATION('8', 6)),\
	FST::NODE()

#pragma endregion

//���� ����� � ����
#pragma region ���������� ��������

#define FST_TRUE 5,	\
	FST::NODE(1, FST::RELATION('t', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('u', 3)),\
	FST::NODE(1, FST::RELATION('e', 4)),\
	FST::NODE()

#define FST_FALSE 6,	\
	FST::NODE(1, FST::RELATION('f', 1)),\
	FST::NODE(1, FST::RELATION('a', 2)),\
	FST::NODE(1, FST::RELATION('l', 3)),\
	FST::NODE(1, FST::RELATION('s', 4)),\
	FST::NODE(1, FST::RELATION('e', 5)),\
	FST::NODE()
#pragma endregion

#pragma region ��������� �������

#define FST_STRLIT 3,	\
	FST::NODE(1, FST::RELATION('\"', 1)),\
	FST::NODE(153, \
			FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1),\
			FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1),\
			FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
			FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1),\
			FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),\
			FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
			FST::RELATION('y', 1), FST::RELATION('z', 1),\
			FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1),\
			FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1),\
			FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),\
			FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1),\
			FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1),\
			FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),\
			FST::RELATION('Y', 1), FST::RELATION('Z', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1),\
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
			FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),\
			FST::RELATION('8', 1), FST::RELATION('9', 1),\
			FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1),\
			FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1),\
			FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1),\
			FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1),\
			FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('#', 1), FST::RELATION('&', 1),\
			FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1),\
			FST::RELATION('\"', 2)),\
	FST::NODE()
#pragma endregion

#pragma region ���������

#define FST_OPERATOR 3,	\
	FST::NODE(11, FST::RELATION('+', 2), FST::RELATION('-', 2), FST::RELATION('*', 2), FST::RELATION('/', 2), FST::RELATION('%', 2), FST::RELATION('>', 2), FST::RELATION('<', 2), FST::RELATION('?', 2), FST::RELATION('!', 2), FST::RELATION('<', 1),FST::RELATION('>', 1) ),\
    FST::NODE(1, FST::RELATION('=', 2)),\
	FST::NODE()


#pragma endregion

#pragma region �������

#define FST_SEMICOLON 2,	\
	FST::NODE(1, FST::RELATION(';', 1)),\
	FST::NODE()

#define FST_COMMA 2,	\
	FST::NODE(1, FST::RELATION(',', 1)),\
	FST::NODE()

#define FST_LEFTBRACE 2,	\
	FST::NODE(1, FST::RELATION('{', 1)),\
	FST::NODE()

#define FST_BRACELET 2,	\
	FST::NODE(1, FST::RELATION('}', 1)),\
	FST::NODE()

#define FST_LEFTTHESIS 2,	\
	FST::NODE(1, FST::RELATION('(', 1)),\
	FST::NODE()

#define FST_RIGHTTHESIS 2,	\
	FST::NODE(1, FST::RELATION(')', 1)),\
	FST::NODE()

#define FST_EQUAL 2,	\
	FST::NODE(1, FST::RELATION('=', 1)),\
	FST::NODE()

#pragma endregion

// ���� ����� � ���� ������� ������� �� ������������ 
#pragma region ��������� �� ������� ����������

#define FST_ABS 4,	\
	FST::NODE(1, FST::RELATION('A', 1)),\
	FST::NODE(1, FST::RELATION('B', 2)),\
	FST::NODE(1, FST::RELATION('S', 3)),\
	FST::NODE()

#define FST_DEG 4,	\
	FST::NODE(1, FST::RELATION('D', 1)),\
	FST::NODE(1, FST::RELATION('E', 2)),\
	FST::NODE(1, FST::RELATION('G', 3)),\
	FST::NODE()

#define FST_SLEN 5,	\
	FST::NODE(1, FST::RELATION('s', 1)),\
	FST::NODE(1, FST::RELATION('l', 2)),\
	FST::NODE(1, FST::RELATION('e', 3)),\
	FST::NODE(1, FST::RELATION('n', 4)),\
	FST::NODE()

#define FST_SCPY 5,	\
	FST::NODE(1, FST::RELATION('s', 1)),\
	FST::NODE(1, FST::RELATION('c', 2)),\
	FST::NODE(1, FST::RELATION('p', 3)),\
	FST::NODE(1, FST::RELATION('y', 4)),\
	FST::NODE()

#define FST_WRITE 6,	\
	FST::NODE(1, FST::RELATION('w', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('i', 3)),\
	FST::NODE(1, FST::RELATION('t', 4)),\
	FST::NODE(1, FST::RELATION('e', 5)),\
	FST::NODE()

#define FST_WRITELN 8,	\
	FST::NODE(1, FST::RELATION('w', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('i', 3)),\
	FST::NODE(1, FST::RELATION('t', 4)),\
	FST::NODE(1, FST::RELATION('e', 5)),\
	FST::NODE(1, FST::RELATION('l', 6)),\
	FST::NODE(1, FST::RELATION('n', 7)),\
	FST::NODE()

#pragma endregion