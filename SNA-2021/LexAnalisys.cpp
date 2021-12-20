#include "stdafx.h"
#include "LexAnalisys.h"
#include "Div.h"
#include "FST.h"
#include "Graphs.h"
#define DIV			'|'
#define SPACE		' '
#define PLUS		'+'
#define MINUS		'-'
#define STAR		'*'
#define DIRSLASH	'/'
#define MOD			'%'
#define MORE		'>'
#define LESS		'<'
#define EQU			'?'
#define NEQU		'!'
#define EQUAL		'='
#define EQUALORMORE	'>='
#define EQUALORLESS '<='

using namespace std;

namespace Lex {
	LEX LexAnaliz(Log::LOG log, In::IN in) {
#pragma region До цикла
		LEX lex;
		LT::LexTable lextable = LT::Create(LT_MAXSIZE);
		IT::IdTable idtable = IT::Create(TI_MAXSIZE);

		Cleaning(in.text, in.size, log);

		char** word = new char* [max_word];
		for (int i = 0; i < max_word; i++)
			word[i] = new char[size_word] {NULL};

		do {
			word = SeparateText(in.text, in.size);
		} while (word == NULL);

		for (int i = 0; word[i]; i++) {
			cout << word[i];
		}
		cout << endl;

		int indexLex = 0;
		int literalCounter = 1;
		int line = 1;
		int position = 0;
		bool findEkler = false;
		int EklerCounter = 0;
		bool findDeclaration = false;
		bool findType = false;
		bool findProc = false;
		int is_cycle = 0;

		std::stack<std::string> functions;
		char* bufprefix = new char[10]{ "" };
		char* L = new char[2]{ "L" };
		char* bufL = new char[TI_STR_MAXSIZE];
		char* nameLiteral = new char[10]{ "" };
		char* charclit = new char[10]{ "" };

		bool findFunc = false;
		bool findParm = false;
		IT::Entry entryIT;
#pragma endregion

		for (int i = 0; word[i] != NULL; i++, indexLex++) {
			//УДАЛИТЬ ВЫВОД
			cout << word[i] << endl;
			bool findSameID = false;
			position += strlen(word[i]);

#pragma region Ключевые слова

			if (FST::execute(FST::FST(word[i], FST_CREATE))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_CREATE, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findDeclaration = true;
			}
			else if (FST::execute(FST::FST(word[i], FST_NUM))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_NUM, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findType = true;
				entryIT.iddatatype = IT::NUM;
			}
			/*else if (FST::execute(FST::FST(word[i], FST_BOOL))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BOOL, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findType = true;
				entryIT.iddatatype = IT::BOOL;
			}*/
			else if (FST::execute(FST::FST(word[i], FST_STRING))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_STRING, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findType = true;
				entryIT.iddatatype = IT::STR;
				strcpy(entryIT.value.vstr.str, "");
			}

			/*else if (FST::execute(FST::FST(word[i], FST_CHAR))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_CHAR, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findType = true;
				entryIT.iddatatype = IT::CHAR;
				entryIT.value.vchar = '\u0000';
			}*/
			else if (FST::execute(FST::FST(word[i], FST_FUNC))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_FUNC, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findFunc = true;
			}
			else if (FST::execute(FST::FST(word[i], FST_PROCESS))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_PROCESS, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findFunc = true;
				findProc = true;
			}
			else if (FST::execute(FST::FST(word[i], FST_BACK))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BACK, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_PRINT))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_PRINT, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_PRINTLN))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_PRINTLN, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_EKLER))) {
				strcpy(entryIT.id, word[i]);
				entryIT.idxFirstLE = indexLex;
				entryIT.idtype = IT::F;
				entryIT.iddatatype = IT::NUM;
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_EKLER, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
				functions.push(word[i]);
				findEkler = true;
				EklerCounter++;
			}
			else if (FST::execute(FST::FST(word[i], FST_REPLAY))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_REPLAY, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				is_cycle++;
			}
			else if (FST::execute(FST::FST(word[i], FST_COND))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_COND, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				is_cycle++;
			}
			else if (FST::execute(FST::FST(word[i], FST_OTHER))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_OTHER, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				is_cycle++;
			}
			/*else if (FST::execute(FST::FST(word[i], FST_TRUE)) || FST::execute(FST::FST(word[i], FST_FALSE))) {
				int value;
				if (!strcmp((char*)word[i], "true")) value = 1;
				else value = 0;

				for (int k = 0; k < idtable.size; k++) {
					if (idtable.table[k].value.vint == value && idtable.table[k].idtype == IT::L && idtable.table[k].iddatatype == IT::BOOL) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;

				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::BOOL;
				entryIT.value.vint = value;
				entryIT.idxFirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}*/

			else if (FST::execute(FST::FST(word[i], FST_ABS))) {
				if (int idx = IT::IsId(idtable, word[i]) == TI_NULLIDX) {
					entryIT.idtype = IT::F;
					entryIT.iddatatype = IT::NUM;
					entryIT.idxFirstLE = indexLex;
					strcpy(entryIT.id, word[i]);
					IT::Add(idtable, entryIT);
					entryIT = {};
				}

				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_DEG))) {
				if (int idx = IT::IsId(idtable, word[i]) == TI_NULLIDX) {
					entryIT.idtype = IT::F;
					entryIT.iddatatype = IT::NUM;
					entryIT.idxFirstLE = indexLex;
					strcpy(entryIT.id, word[i]);
					IT::Add(idtable, entryIT);
					entryIT = {};
				}

				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}

#pragma endregion

#pragma region Литералы

			else if (FST::execute(FST::FST(word[i], FST_INTLIT))) {
				char valueWithoutSign[ID_MAXSIZE] = {};

				int j = 0;
				while (true) {
					if (word[i][j] == '_')
						break;
					valueWithoutSign[j] = word[i][j];
					j++;
				}

				int value = atoi(valueWithoutSign);

				if (word[i][j + 1] == 'n')
					value = -value;

				for (int k = 0; k < idtable.size; k++) {
					if (idtable.table[k].value.vint == value && idtable.table[k].idtype == IT::L && idtable.table[k].iddatatype == IT::NUM) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::NUM;
				entryIT.value.vint = value;
				entryIT.idxFirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_INTLITBIN))) {
				char valueWithoutSign[ID_MAXSIZE] = {};

				int j = 0;
				while (true) {
					if (word[i][j] == '_')
						break;
					valueWithoutSign[j] = word[i][j];
					j++;
				}

				int value = strtol(valueWithoutSign, NULL, 2);
				if (word[i][j + 1] == 'n')
					value = -value;

				for (int k = 0; k < idtable.size; k++) {
					if (idtable.table[k].value.vint == value && idtable.table[k].idtype == IT::L && idtable.table[k].iddatatype == IT::NUM) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::NUM;
				entryIT.value.vint = value;
				entryIT.idxFirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_INTLITOCT))) {
				char valueWithoutSign[ID_MAXSIZE] = {};

				int j = 0;
				while (true) {
					if (word[i][j] == 'p' || word[i][j] == 'n')
						break;
					valueWithoutSign[j] = word[i][j];
					j++;
				}

				int value = strtol(valueWithoutSign, NULL, 8);
				if (word[i][j] == 'n')
					value = -value;

				for (int k = 0; k < idtable.size; k++) {
					if (idtable.table[k].value.vint == value && idtable.table[k].idtype == IT::L && idtable.table[k].iddatatype == IT::NUM) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::NUM;
				entryIT.value.vint = value;
				entryIT.idxFirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_STRLIT))) {
				int length = strlen(word[i]);
				for (int k = 0; k < length; k++)
					word[i][k] = word[i][k + 1];
				word[i][length - 2] = 0;

				for (int k = 0; k < idtable.size; k++) {
					if (!(strcmp(idtable.table[k].value.vstr.str, word[i]))) {
						findSameID = true;
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						break;
					}
				}
				if (findSameID) continue;

				strcpy(entryIT.value.vstr.str, word[i]);
				entryIT.value.vstr.len = length - 2;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::STR;
				entryIT.idxFirstLE = indexLex;

				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				nameLiteral = strcat(bufL, (char*)charclit);
				strcpy(entryIT.id, nameLiteral);
				IT::Add(idtable, entryIT);
				entryIT = {};

				int k = 0;
				for (k = 0; k < idtable.size; k++) {
					if (!(strcmp(idtable.table[k].value.vstr.str, word[i])))
						break;
				}
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
				LT::Add(lextable, entryLT);
			}

#pragma endregion

#pragma region ИдентификаторыОператоры

			else if (FST::execute(FST::FST(word[i], FST_ID))) {
				if (findParm)
					entryIT.idtype = IT::P;
				else if (findFunc) {
					if (findProc)
						entryIT.iddatatype = IT::PROC;
					entryIT.idtype = IT::F;
					functions.push(word[i]);
				}
				else {
					entryIT.idtype = IT::V;
					int idx = IT::IsId(idtable, word[i]);
					if (idx != TI_NULLIDX) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, idx, line);
						LT::Add(lextable, entryLT);
						entryIT = { };
						continue;
					}
					if (entryIT.iddatatype == IT::NUM)
						entryIT.value.vint = TI_INT_DEFAULT;
					else if (entryIT.iddatatype == IT::STR) {
						entryIT.value.vstr.len = 0;
						memset(entryIT.value.vstr.str, TI_STR_DEFAULT, sizeof(char));
					}
				}

				entryIT.idxFirstLE = indexLex;
				if (entryIT.idtype != IT::F && !functions.empty()) {
					strcpy(bufprefix, functions.top().c_str());
					word[i] = strcat(bufprefix, word[i]);
				}

				auto type = entryIT.iddatatype;
				strcpy(entryIT.id, word[i]);
				entryIT.iddatatype = type;

				int idx = IT::IsId(idtable, word[i]);
				if (idx == TI_NULLIDX)
					IT::Add(idtable, entryIT);
				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
				entryIT = { };
			}
			else if (FST::execute(FST::FST(word[i], FST_OPERATOR))) {
				strcpy(entryIT.id, word[i]);
				entryIT.idxFirstLE = indexLex;
				entryIT.idtype = IT::OP;
				if (IT::IsId(idtable, word[i]) == TI_NULLIDX)
					IT::Add(idtable, entryIT);
				entryIT = { };

				LT::Entry entryLT = WriteEntry(entryLT, LEX_OPERATOR, IT::IsId(idtable, word[i]), line);

				if ((word[i][0] == '<' || word[i][0] == '>') && word[i][1] == '=') {
					if (word[i][0] == '<') {
						entryLT.priority = 1;
						entryLT.op = LT::operations::OEQUORLESS;
					}
					else {
						entryLT.priority = 1;
						entryLT.op = LT::operations::OEQUORMORE;
					}
				}
				else
					switch (word[i][0]) {
					case MORE:
						entryLT.priority = 1;
						entryLT.op = LT::operations::OMORE;
						break;
					case LESS:
						entryLT.priority = 1;
						entryLT.op = LT::operations::OLESS;
						break;
					case EQU:
						entryLT.priority = 1;
						entryLT.op = LT::operations::OEQU;
						break;
					case NEQU:
						entryLT.priority = 1;
						entryLT.op = LT::operations::ONEQU;
						break;
					case PLUS:
						entryLT.priority = 2;
						entryLT.op = LT::operations::OPLUS;
						break;
					case MINUS:
						entryLT.priority = 2;
						entryLT.op = LT::operations::OMINUS;
						break;
					case DIRSLASH:
						entryLT.priority = 3;
						entryLT.op = LT::operations::ODIV;
						break;
					case STAR:
						entryLT.priority = 3;
						entryLT.op = LT::operations::OMUL;
						break;
					case MOD:
						entryLT.priority = 3;
						entryLT.op = LT::operations::OMOD;
					}

				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_SEMICOLON))) {
				if (findDeclaration && findFunc && findType)
					functions.pop();
				LT::Entry entryLT = WriteEntry(entryLT, LEX_SEMICOLON, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findDeclaration = findFunc = findType = findParm = false;
				entryIT = { };
			}
			else if (FST::execute(FST::FST(word[i], FST_COMMA))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_COMMA, LT_TI_NULLIDX, line);
				entryLT.priority = 1;
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_LEFTBRACE))) {
				findType = findDeclaration = findFunc = findParm = findProc = false;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTBRACE, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_BRACELET))) {
				if (!functions.empty() && is_cycle == 0)
					functions.pop();
				else if (is_cycle != 0) is_cycle--;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BRACELET, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_LEFTTHESIS))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTTHESIS, LT_TI_NULLIDX, line);
				entryLT.priority = 0;
				LT::Add(lextable, entryLT);
				if (findFunc || findProc)
					findParm = true;
			}
			else if (FST::execute(FST::FST(word[i], FST_RIGHTTHESIS))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RIGHTTHESIS, LT_TI_NULLIDX, line);
				entryLT.priority = 0;
				findParm = false;
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_EQUAL))) {
				LT::Entry entryLT = WriteEntry(entryLT, LEX_EQUAL, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (word[i][0] == DIV) {
				line++;
				position = 0;
				indexLex--;
			}
#pragma endregion

			else
				throw ERROR_THROW_IN(205, line, position);
		}

		if (!findEkler) throw ERROR_THROW(302);
		if (EklerCounter > 1) throw ERROR_THROW(301);

		lex.idtable = idtable;
		lex.lextable = lextable;
		return lex;
	}

	void Synchronization(Lex::LEX& lex) {
		bool* is_changed = new bool[lex.idtable.size]{ false };
		for (int i = 0; i < lex.lextable.size; i++) {
			if (lex.lextable.table[i].idxTI != -1 && !is_changed[lex.lextable.table[i].idxTI]) {
				lex.idtable.table[lex.lextable.table[i].idxTI].idxFirstLE = i;
				is_changed[lex.lextable.table[i].idxTI] = true;
			}
		}
		delete[] is_changed;
	}
}