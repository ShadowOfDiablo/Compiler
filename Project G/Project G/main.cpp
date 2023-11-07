
#include "base.h"
#include "booleanExpression.h"
#include "arithmeticexpression.h"
#include "lvalue.h"
#include "relationalexpression.h"
#include "statement.h"
int main(int argc,char**argv) {
	std::vector<Statement*> block;
	block.push_back(new StatementWrite("Hello, World!\n"));
	Statement* program = new StatementBlock(block);
	program->Execute();
	delete program;
	return 0;
}