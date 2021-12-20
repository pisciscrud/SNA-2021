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
		ERROR_ENTRY_NODEF10(210),
		
		 ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		  ERROR_ENTRY(300, "Semantic Analysis Error: There is not a closed string literal"),
		ERROR_ENTRY(301, "Semantic Analysis Error: There is more than one entry point in EKLER"),
		ERROR_ENTRY(302, "Semantic Analysis Error: There is no entry point to EKLER"),
		ERROR_ENTRY(303, "Semantic Analysis Error: The size of the string literal is exceeded"),
		ERROR_ENTRY(304, "Semantic Analysis Error: Variable declaration without the create keyword"),
		ERROR_ENTRY(305, "Semantic Analysis Error: Undeclared identifier"),									// -
		ERROR_ENTRY(306, "Semantic analysis error: Declaring a variable without specifying the type"),						// -
		ERROR_ENTRY(307, "Semantic analysis error: An attempt to implement an existing function"),						// +
		ERROR_ENTRY(308, "Semantic analysis error: Function declaration without type indication"),							// -
		ERROR_ENTRY(309, "Semantic analysis error: Mismatch of types of passed function parameters"),			// -
		ERROR_ENTRY(310, "Semantic analysis error: Mismatch of arithmetic operators"),						// -
		ERROR_ENTRY(311, "Semantic analysis error: Division by zero is not possible"),									// -
		ERROR_ENTRY(312, "Semantic Analysis Error: Data type mismatch"),									// +
		ERROR_ENTRY(313, "Semantic analysis error: Mismatch of open and closed brackets in an expression"),			// -
		ERROR_ENTRY(314, "Semantic analysis error: The function returns an invalid data type"),						// +
		ERROR_ENTRY(315, "Semantic analysis error: Num value overflow"),						// +
		ERROR_ENTRY_NODEF(316), ERROR_ENTRY_NODEF(317),
		ERROR_ENTRY_NODEF(318), ERROR_ENTRY_NODEF(319),
		ERROR_ENTRY_NODEF10(320), ERROR_ENTRY_NODEF10(330), ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350), ERROR_ENTRY_NODEF10(360),
		ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400),
		ERROR_ENTRY_NODEF10(500), ERROR_ENTRY_NODEF10(510), ERROR_ENTRY_NODEF10(520), ERROR_ENTRY_NODEF10(530), ERROR_ENTRY_NODEF10(540),
		ERROR_ENTRY_NODEF10(550), ERROR_ENTRY_NODEF10(560), ERROR_ENTRY_NODEF10(570), ERROR_ENTRY_NODEF10(580), ERROR_ENTRY_NODEF10(590),
		ERROR_ENTRY(600, "Îøèáêà ñèíòàêñè÷åñêîãî àíàëèçà: Íåïğàâèëüíàÿ ñòğóêòóğà ïğîãğàììû"),
		ERROR_ENTRY(601, "Îøèáêà ñèíòàêñè÷åñêîãî àíàëèçà: Îòñóòñòâóåò ñïèñîê ïàğàìåòğîâ ôóíêöèè"),
		ERROR_ENTRY(602, "[ SYNTAX ] Îøèáêà â ïàğàìåòğàõ ôóíêöèè"),
		ERROR_ENTRY(603, "[ SYNTAX ] Îòñóòñòâóåò òåëî ôóíêöèè"),
		ERROR_ENTRY(604, "[ SYNTAX ] Íåäîïóñòèìîå âûğàæåíèå"),
		ERROR_ENTRY(605, "[ SYNTAX ] Îòñóòñòâóåò òåëî óñëîâèÿ èëè öèêëà"),
		ERROR_ENTRY(606, "[ SYNTAX ] Íåâåğíàÿ êîíñòğóêöèÿ â òåëå ôóíêöèè"),
		ERROR_ENTRY(607, "[ SYNTAX ] Îøèáêà â óñëîâíîì âûğàæåíèè"),
		ERROR_ENTRY(608, "[ SYNTAX ] Îøèáêà â âûçîâå ôóíêöèè"),
		ERROR_ENTRY(609, "[ SYNTAX ] Îøèáêà â àğèôìåòè÷åñêîì âûğàæåíèè"),
		ERROR_ENTRY(610, "[ SYNTAX ] Îøèáêà â ñïèñêå ïàğàìåòğîâ ïğè âûçîâå ôóíêöèè"),
		ERROR_ENTRY(611, "[ SYNTAX ] Îøèáêà â àğèôìåòè÷åñêîì âûğàæåíèè"),
		ERROR_ENTRY(612, "[ SYNTAX ] Íåâåğíàÿ êîíñòğóêöèÿ â òåëå öèêëà èëè óñëîâèÿ"),
		ERROR_ENTRY_NODEF(614), ERROR_ENTRY_NODEF(615), ERROR_ENTRY_NODEF(616), ERROR_ENTRY_NODEF(617), ERROR_ENTRY_NODEF(618), ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800)
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