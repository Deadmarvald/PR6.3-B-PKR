#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR6.3B/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT63B
{
	TEST_CLASS(UT63B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;

			int first_ = 1, end_ = 3;
			Info a = 3;

			while (first_ <= end_)
			{
				Elem* tmp = new Elem;
				tmp->info = a;
				tmp->next = NULL;
				if (last != NULL)
					last->next = tmp;
				tmp->prev = last;
				last = tmp;
				if (first == NULL)
					first = tmp;
				first_++;
			}

			Assert::AreEqual(first->info, last->info);
		}
	};
}