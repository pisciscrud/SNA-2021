#include "SemAnalysis.h"

namespace Semantic {
	bool CheckValueOverflow(int value) {
		if (value > MAX_NUM_VALUE || value < MIN_NUM_VALUE) {
			return false;
		}
		else
			return true;
	}

	bool Analyze(Lex::LEX lex, Log::LOG log) {

		bool is_analysis_ok = true;
		bool are_all_identifiers_declared = true;
		int j = 0;

		std::vector<std::string> functions_id;


		for (int i = 0; i < lex.lextable.size; i++) {

			switch (lex.lextable.table[i].lexema) {

			//case LEX_ID:
			//	if (lex.lextable.table[i + 1].lexema == LEX_LEFTTHESIS) {
			//		Log::WriteError(log, Error::geterrorin(314, lex.lextable.table[i].line, -1)); // ньхайс мсфмсч днаюбхрэ
			//		is_analysis_ok = false;
			//	}
			//	continue;

			case LEX_EQUAL:
				if (lex.idtable.table[lex.lextable.table[i - 1].idxTI].iddatatype == IT::NO) {
					Log::WriteError(log, Error::geterrorin(305, lex.lextable.table[i - 1].line, -1));
					is_analysis_ok = false;
					are_all_identifiers_declared = false;
				}
				j = i + 1;
				for (j; lex.lextable.table[j].lexema != LEX_SEMICOLON; j++) {
					switch (lex.lextable.table[j].lexema) {
					case LEX_ID:
					case LEX_LITERAL:
						if (are_all_identifiers_declared == true
							&&
							lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype == IT::NO)
						{
							Log::WriteError(log, Error::geterrorin(305, lex.lextable.table[j].line, -1));
							is_analysis_ok = false;
							are_all_identifiers_declared = false;
						}
						else
							if (are_all_identifiers_declared == true
								&&
								lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != lex.idtable.table[lex.lextable.table[i - 1].idxTI].iddatatype)
							{
								Log::WriteError(log, Error::geterrorin(312, lex.lextable.table[j].line, -1));
								is_analysis_ok = false;
							}

						if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype == IT::NUM &&
							CheckValueOverflow(lex.idtable.table[lex.lextable.table[j].idxTI].value.vint) == false) {
							Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].line, -1));
							is_analysis_ok = false;
						}

						continue;

					case LEX_LEFTTHESIS:
						if (lex.lextable.table[j - 1].lexema == 'f') {
							do {
								j++;
							} while (lex.lextable.table[j].lexema != LEX_RIGHTTHESIS);
						}
						continue;
					}
				}
				are_all_identifiers_declared = true;
				continue;
			case LEX_FUNC:
				if (std::count(functions_id.begin(), functions_id.end(), lex.idtable.table[lex.lextable.table[i + 1].idxTI].id)) {
					Log::WriteError(log, Error::geterrorin(307, lex.lextable.table[i + 1].line, -1));
					is_analysis_ok = false;
				}
				functions_id.push_back(lex.idtable.table[lex.lextable.table[i + 1].idxTI].id);

				j = i + 1;
				int type = lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype;
				do {

					j++;
					

				} while ((lex.lextable.table[j].lexema != LEX_BACK));
				if (lex.idtable.table[lex.lextable.table[j + 1].idxTI].iddatatype != type) {
					Log::WriteError(log, Error::geterrorin(314, lex.lextable.table[j].line, -1));
					is_analysis_ok = false;
				}

			}
		}

		return is_analysis_ok;
	}
}