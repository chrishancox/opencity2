/***************************************************************************
                      ATestRunner.cpp  -  description
							-------------------
	begin                : November 29th, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: ATestRunner.cpp 441 2010-04-22 17:22:28Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

// Framework headers
#include "ATestRunner.h"			// UnitTesting::TestRunner abstract class
#include "ATestClass.h"				// UnitTesting::TestClass class
#include "System/CConsole.h"		// System::Console class
#include "System/Collections/Generic/CList.h"	// System::Collections::Generic::List


using namespace System::Collections::Generic;

SPF_NAMESPACE_BEGIN(UnitTesting)


   /*=====================================================================*/
TestRunner::TestRunner() {}


TestRunner::~TestRunner() {}


   /*=====================================================================*/
const List<TestClass>& TestRunner::GetTestClasses() const
{
	return this->mcTestClasses;
}


   /*=====================================================================*/
void TestRunner::Add(const TestClass& testClass)
{
	mcTestClasses.Add(testClass);
}


void TestRunner::Run()
{
	int count = mcTestClasses.GetCount();
	for (int i = 0; i < count; i++) {
		TestClass& testClass = mcTestClasses[i];

		// TODO: catch exception here
		testClass.Run();
	} // for
}


   /*=====================================================================*/
System::String TestRunner::ToString() const
{
	return System::String("UnitTesting::TestRunner");
}


SPF_NAMESPACE_END
