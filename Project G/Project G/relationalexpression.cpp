#ifndef _RELATIONALEXPRESSION_H
#define _RELATIONALEXPRESSION_H

BINARYOP(RelationalExpressionLessThan, RelationalExpression, ArithmeticExpression, bool, <)
BINARYOP(RelationalExpressionGreaterThan, RelationalExpression, ArithmeticExpression, bool, >)
BINARYOP(RelationalExpressionGreaterThanOrEqualTo, RelationalExpression, ArithmeticExpression, bool, >=)
BINARYOP(RelationalExpressionLessThanOrEqualTo, RelationalExpression, ArithmeticExpression, bool, <=)
BINARYOP(RelationalExpressionUnequal, RelationalExpression, ArithmeticExpression, bool, !=)
BINARYOP(RelationalExpressionEqual, RelationalExpression, ArithmeticExpression, bool, ==)


#endif // !_RELATIONALEXPRESSION_H
