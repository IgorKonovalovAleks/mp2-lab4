#include <gtest.h>
#include "Expression.h"
#include <iostream>

int main(int argc, char **argv)
{
  //::testing::InitGoogleTest(&argc, argv);
  //return RUN_ALL_TESTS();



	//while (!pf.empty()) {
	//	std::cout << pf.getNext().val <<'\n';
	//}
	Expression a("1.4+.3* (-.2+4.0 )");
	std::cout << a.calculate();
	return 0;

}