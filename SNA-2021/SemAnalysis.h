#pragma once
#include "stdafx.h"
#include "Log.h"
#include "LexAnalisys.h"

#define MAX_NUM_VALUE 127
#define MIN_NUM_VALUE -128

namespace Semantic {
	bool Analyze(Lex::LEX lex, Log::LOG log);
	bool CheckValueOverflow(int value);
}