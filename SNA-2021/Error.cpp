#include"Error.h"
namespace Error {
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "Íåäîïóñòèìûé êîä îøèáêè"),
		ERROR_ENTRY(1, "Ñèñòåìíûé ñáîé"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "The -in parameter must be set"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "The length of the input parameter is exceeded"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Error opening the source code file (-in)"),
		ERROR_ENTRY(111, "Forbidden character in the source file (-in)"),
		ERROR_ENTRY(112, "Error creating the protocol file (-log)"),
		ERROR_ENTRY_NODEF(113), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "Lexical analysis error: Invalid character in the source file (-in)"),
		ERROR_ENTRY(201, "Lexical analysis error: The size of the lexeme table is exceeded"),
		ERROR_ENTRY(202, "Lexical analysis error: Overflow of the lexeme table"),
		ERROR_ENTRY(203, "Lexical analysis error: The size of the identifier table is exceeded"),
		ERROR_ENTRY(204, "Lexical analysis error: Overflow of the identifier table"),
		ERROR_ENTRY(205, "Lexical analysis error: Unknown character sequence"),
		ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Semantic analysis error : There is not a closed string literal"),							
		ERROR_ENTRY(301, "Semantic analysis error: There is more than one entry point in EKLER(main)"),						// +
		ERROR_ENTRY(302, "Semantic analysis error: There is no entry point to main"),									// +
		ERROR_ENTRY(303, "Semantic analysis error: The size of the string literal is exceeded"),							// -
		ERROR_ENTRY(304, "Semantic analysis error: Variable declaration without the create keyword"),					// -
		ERROR_ENTRY(305, "Semantic Analysis Error: Undeclared identifier"),									// -
		ERROR_ENTRY(306, "Semantic analysis error: Declaring a variable without specifying the type"),						// -
		ERROR_ENTRY(307, "Semantic analysis error: An attempt to implement an existing function"),						// +
		ERROR_ENTRY(308, "Semantic analysis error: Function declaration without type indication"),							// -
		ERROR_ENTRY(309, "Semantic analysis error: Mismatch of types of passed function parameters"),			// -
		ERROR_ENTRY(310, "Semantic analysis error: Mismatch of arithmetic operators"),						// -
		ERROR_ENTRY(311, "Semantic analysis error: Division by zero is not possible"),									// -
		ERROR_ENTRY(312, "Semantic Analysis Error: Data type Mismatch"),									// +
		ERROR_ENTRY(313, "Semantic analysis error: Mismatch of open and closed brackets in an expression"),			// -
		ERROR_ENTRY(314, "Semantic analysis error: The function returns an invalid data type"),						// +
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};
	ERROR geterror(int id) {
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			return errors[id];
		}
		else {
			return errors[0];
		}
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
		else {
			return errors[0];
		}
	}
}