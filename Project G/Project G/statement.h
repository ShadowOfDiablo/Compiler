#ifndef __STATEMENT_H
#define __STATEMENT_H
#include<string>
#include<vector>
#include<iostream>
class StatementBlock : public Statement {
	std::vector <Statement*> statements;
public:
	StatementBlock(std::vector<Statement*>& statements) {
		this->statements = statements;
	}
	~StatementBlock() {
		for (Statement* stmnt : statements) {
			delete statement;
		}
		statements.clear();
	}
	void Execute() override {
		for (Statement* statement : statements) {
			statement->Execute();
		}
	}

};
class StatementWrite : public Statement {
	std::string text;
public:
	StatementWrite(const std::string& text) {
		this->text = text;
	}
	~StatementWrite() {
	}
	void Execute() override {
		std::cout << text;
	}
};

class StatementAssign : public Statement {
	LocationValue* lvalue;
	ArithmeticExpression* expression;
public:
	StatementAssign(LocationValue* lvalue,ArithmeticExpression* expression) {
		this->lvalue = lvalue;
		this->expression = expression;
	}
	~StatementAssign() {
		delete expression;
		delete lvalue;
	}
	void Execute() override {
		int temp = expression->Evaluate();
		lvalue->Set(temp);
	}
};

class StatementWriteInt : public Statement {
	ArithmeticExpression* expression;
public:
	StatementWriteInt(ArithmeticExpression* expression) {
		this->expression = expression;
	}
	~StatementWriteInt() {
		delete expression;
	}
	void Execute() override {
		std::cout << (expression->Evaluate());
	}
};

class StatementReadInt : public Statement {
	LocationValue* lvalue;
public:
	StatementReadInt(LocationValue* lvalue) {
		this->lvalue = lvalue;
	}
	~StatementReadInt() {
		delete lvalue;
	}
	void Execute() override {
		int temp;
		std::cin >> temp;
		lvalue->Set(temp);
	}
};

class StatementWhile : public Statement {
	BooleanExpression* condition; //if the condition is true
	Statement* statement;// do whatever is this pointer pointing at
public:
	StatementWhile(BooleanExpression* condition,Statement* statement) {
		this->condition = condition;
		this->statement = statement;
	}
	~StatementWhile() {
		delete condition;
		delete statement;
	}
	void Execute() override {
		while (condition->Evaluate()) {
			statement->Execute();
		}
	}
};
class StatementIfThenElse : public Statement {
	BooleanExpression* condition; //if the condition is true
	Statement* statement;// do whatever is this pointer pointing at
	Statement* statement;// do this otherwise
public:
	StatementIfThenElse(BooleanExpression* condition, Statement* thencase,Statement* elsecase=nullptr) {
		this->condition = condition;
		this->thencase = thencase;
		this->elsecase = elsecase;
	}
	~StatementIfThenElse() {
		delete condition;
		delete thencase;
		delete elsecase;
	}
	void Execute() override {
		if(condition->Evaluate()) {
			if (thencase) {
				statement->Execute();
			}
			else {
				if (elsecase) {
					elsecase->Execute();
				}
			}
		}
	}
};

#endif // !_STATEMENT_H
