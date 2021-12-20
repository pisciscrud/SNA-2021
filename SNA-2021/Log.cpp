#include"Log.h"
#include"LT.h"
#include"IT.h"
using namespace std;

namespace Log {
	LOG getlog(wchar_t logfile[]) {
		LOG log;
		log.stream = new std::ofstream;
		log.stream->open(logfile);
		if (log.stream->fail())
			throw ERROR_THROW(112);

		wcscpy_s(log.logfile, logfile);
		return log;
	}

	void WriteLine(LOG log, const char* c, ...) {
		const char** ptr = &c;
		while (*ptr != "") {
			*log.stream << *ptr;
			ptr++;
		}

		*log.stream << std::endl;
	}

	void WriteLine(LOG log, const wchar_t* c, ...) {
		const wchar_t** ptr = &c;

		char temp[100];

		while (*ptr != L"") {
			wcstombs(temp, *ptr++, sizeof(temp));
			*log.stream << temp;
		}
		*log.stream << std::endl;
	}

	void WriteLog(LOG log) {
		time_t rawtime;
		tm current_time;
		char temp[100];

		time(&rawtime);
		localtime_s(&current_time, &rawtime);

		*log.stream << "\t\t\t\t\t                          ********* REPORT  *********         \t\n";
		strftime(temp, 100, "\t\t\t\t\t                          || Time: %d.%m.%Y, %H:%M:%S||\n", &current_time);
		*log.stream << temp <<
			"                           \n";
	}

	void WriteParm(LOG log, Parm::PARM parm) {
		char in_text[PARM_MAX_SIZE];
		char out_text[PARM_MAX_SIZE];
		char log_text[PARM_MAX_SIZE];

		wcstombs(in_text, parm.in, PARM_MAX_SIZE);
		wcstombs(out_text, parm.out, PARM_MAX_SIZE);
		wcstombs(log_text, parm.log, PARM_MAX_SIZE);

		*log.stream << "\t\t\t\t\t                         ********* PARAMETRS ********  \t\n-in: " << in_text
			<< "\n-out: " << out_text
			<< "\n-log: " << log_text << std::endl;
	}

	void WriteIn(LOG log, In::IN in) {
		*log.stream << "\t\t\t\t\t\t\n                                           ******** INFORMATION ********* "
			<< "\t\n NUMBERS OF SYMBOLS: " << in.size
			<< "\t\n NUMBERS OF LINES: " << in.lines
			<< "\t\n NUMBERS OF MISSING SYMBOLS: " << in.ignor << std::endl;
	}

	void WriteError(LOG log, Error::ERROR error) {
		if (log.stream) {
			*log.stream << "\n ERROR " << error.id
				<< ": " << error.message
				<< "\nERROR STRING " << error.inext.line
				<< " \nERROR POSITION  " << error.inext.col << std::endl;
			//Close(log);
		}
		else {
			std::cout << "\nERROR " << error.id
				<< ": " << error.message
				<< "\nERROR STRING " << error.inext.line
				<< "\nERROR POSITION " << error.inext.col << std::endl;
		}
	}

	void WriteLexTableLog(LT::LexTable& lextable, LOG log) {
		int i;
		*log.stream << "\n\t\t\t\t\t   TABLE OF LEXEMES" << std::endl;
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
		*log.stream << "   #" << " | " << "Lexeme" << std::setfill(' ') << std::setw(20) << ' ' << std::left
			<< " | " << "String" << std::setw(21) << ' ' << std::left << " | " << "Index in TI" << std::endl;
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
		for (i = 0; i < lextable.size; i++) {
			char op[2];
			op[0] = ' ';
			op[1] = ' ';

			switch (lextable.table[i].op) {
			case LT::operations::OPLUS:
				op[0] = '+'; op[1] = ' ';
				break;
			case LT::operations::OMINUS:
				op[0] = '-'; op[1] = ' ';
				break;
			case LT::operations::OMUL:
				op[0] = '*'; op[1] = ' ';
				break;
			case LT::operations::ODIV:
				op[0] = '/'; op[1] = ' ';
				break;
			case LT::operations::OMOD:
				op[0] = '%'; op[1] = ' ';
				break;
			case LT::operations::OEQU:
				op[0] = '?'; op[1] = ' ';
				break;
			case LT::operations::ONEQU:
				op[0] = '!'; op[1] = ' ';
				break;
			case LT::operations::OLESS:
				op[0] = '<'; op[1] = ' ';
				break;
			case LT::operations::OMORE:
				op[0] = '>'; op[1] = ' ';
				break;
			case LT::operations::OEQUORLESS:
				op[0] = '<'; op[1] = '=';
				break;
			case LT::operations::OEQUORMORE:
				op[0] = '>'; op[1] = '=';
				break;
			}
			*log.stream << i << "         " << std::setfill(' ')
				<< lextable.table[i].lexema << " " << op[0] << op[1] << std::setw(28) << std::left << "    " << std::setw(28) << std::left
				<< lextable.table[i].line << "     ";
			if (lextable.table[i].idxTI == LT_TI_NULLIDX)
				*log.stream << "-" << std::endl;
			else
				*log.stream << std::setw(23) << lextable.table[i].idxTI << std::endl;
		}
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
		*log.stream << "\t\t\t\tNUMBERS OF LEXEME: " << i << std::endl;
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
	}

	void WriteIdTableLog(IT::IdTable& idtable, LOG log) {
		int i, j, numberOP = 0;
		*log.stream << "\n";
		*log.stream << setfill('-') << setw(87) << '-' << endl;
		*log.stream << " # " << " | " << "Identifier" << " | " << "Type of data" << " | " << "Type of Identifier"
			<< " | " << "Index in TL" << " | " << " Value " << endl;
		*log.stream << setw(87) << '-' << endl;

		for (i = 0, j = 0; i < idtable.size; i++, j++) {
			*log.stream << j << "  ";
			*log.stream << right << "  ";
			*log.stream << setfill(' ') << setw(13) << left << idtable.table[i].id << "  ";

			if (idtable.table[i].idtype == IT::OP) *log.stream << setw(10) << left << "-" << "  ";
			else {
				switch (idtable.table[i].iddatatype) {
				case IT::IDDATATYPE::NUM:
					*log.stream << setw(10) << left;
					*log.stream << "int" << "  ";
					break;
				case  IT::IDDATATYPE::STR:
					*log.stream << setw(10) << left;
					*log.stream << "string" << "  ";
					break;
				default:
					*log.stream << setw(10) << left << "unknown" << "  ";
					break;
				}
			}

			switch (idtable.table[i].idtype) {
			case 	IT::IDTYPE::V: *log.stream << setw(18) << left << "Variable" << "  "; break;
			case 	IT::IDTYPE::F: *log.stream << setw(18) << left << "Function" << "  "; break;
			case 	IT::IDTYPE::P: *log.stream << setw(18) << left << "Parameter" << "  "; break;
			case 	IT::IDTYPE::L: *log.stream << setw(18) << left << "Literal" << "  "; break;
			case 	IT::IDTYPE::OP:
				*log.stream << setw(18) << left << "Operator" << "  ";
				numberOP++;
				break;
			default: *log.stream << setw(18) << left << "unknown" << "  "; break;
			}
			*log.stream << setw(11) << left << idtable.table[i].idxFirstLE << " ";

			if (idtable.table[i].iddatatype == IT::IDDATATYPE::NUM && (idtable.table[i].idtype == IT::IDTYPE::V || idtable.table[i].idtype == IT::IDTYPE::L))
				*log.stream << setw(18) << left << idtable.table[i].value.vint;
			else if (idtable.table[i].iddatatype == IT::IDDATATYPE::STR && (idtable.table[i].idtype == IT::IDTYPE::V || idtable.table[i].idtype == IT::IDTYPE::L))
				*log.stream << "[" << idtable.table[i].value.vstr.len << "]\"" << idtable.table[i].value.vstr.str << "\"";

			else *log.stream << "-";
			*log.stream << endl;
		}

		*log.stream << setfill('-') << setw(87) << "-" << endl;
		*log.stream << "NUMBERS OF IDENTIFIER: " << i << endl;
		*log.stream << setw(87) << "-" << endl;
	}

	void Close(LOG log) {
		log.stream->close();
		delete log.stream;
	}
}