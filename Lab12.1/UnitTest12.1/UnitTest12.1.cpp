#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest121
{
	TEST_CLASS(UnitTest121)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
		Elem* p = new Elem;				// 2
		p->info = 1;						// 3
		p->link1 = new Elem;				// 4
		p->link1->info = 2;					// 5
		p->link1->link2 = new Elem;			// 6
		p->link1->link2->info = 3;			// 7
		p->link1->link2->link1 = p->link1;	// 8
		p->link2 = new Elem;				// 9
		p->link2->info = 4;					// 10
		p->link2->link1 = NULL;				// 11
		p->link1->link1 = p->link2->link1;	// 12
		p->link2->link2 = p;				// 13

		delete p->link2;					// 14
		delete p->link1->link2;				// 15
		delete p->link1;					// 16
		delete p;							// 17

		Assert::IsTrue(true); // Test passes if there is no crash or error message during execution
			
		};
	};
}
