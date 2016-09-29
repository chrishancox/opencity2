/***************************************************************************
                        CStringTest.cpp  -  description
							-------------------
	begin                : April 23th, 2010
	copyright            : (C) 2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CStringTest.cpp 444 2010-04-26 21:18:59Z neoneurone $
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
#include "CStringTest.h"			// Test::StringTest class
#include "UnitTesting/AAssert.h"	// UnitTesting::Assert class

SPF_NAMESPACE_BEGIN(Test)


   /*=====================================================================*/
StringTest::StringTest():
TestClass("System::String test suite.\n")
{
	// Static variable test
	System::Delegate stringEmptyTest(*this, (System::MemberPointer0)&StringTest::StringEmptyTest);
	UnitTesting::TestMethod stringEmptyTestMethod(stringEmptyTest, "StringEmptyTest");
	this->Add(stringEmptyTestMethod);

	// Accessor test
	System::Delegate getLengthTest(*this, (System::MemberPointer0)&StringTest::GetLengthTest);
	UnitTesting::TestMethod getLengthTestMethod(getLengthTest, "GetLengthTest");
	this->Add(getLengthTestMethod);

	// Standard operators tests
	System::Delegate equalOperatorTest(*this, (System::MemberPointer0)&StringTest::EqualOperatorTest);
	UnitTesting::TestMethod equalOperatorTestMethod(equalOperatorTest, "EqualOperatorTest");
	this->Add(equalOperatorTestMethod);

	System::Delegate assignmentOperatorTest(*this, (System::MemberPointer0)&StringTest::AssignmentOperatorTest);
	UnitTesting::TestMethod assignmentOperatorTestMethod(assignmentOperatorTest, "AssignmentOperatorTest");
	this->Add(assignmentOperatorTestMethod);

	System::Delegate plusOperatorTest(*this, (System::MemberPointer0)&StringTest::PlusOperatorTest);
	UnitTesting::TestMethod plusOperatorTestMethod(plusOperatorTest, "PlusOperatorTest");
	this->Add(plusOperatorTestMethod);

	System::Delegate plusEqualOperatorTest(*this, (System::MemberPointer0)&StringTest::PlusEqualOperatorTest);
	UnitTesting::TestMethod plusEqualOperatorTestMethod(plusEqualOperatorTest, "PlusEqualOperatorTest");
	this->Add(plusEqualOperatorTestMethod);

	// Output operator tests
	System::Delegate leftShiftOperatorTest(*this, (System::MemberPointer0)&StringTest::LeftShiftOperatorTest);
	UnitTesting::TestMethod leftShiftOperatorTestMethod(leftShiftOperatorTest, "LeftShiftOperatorTest");
	this->Add(leftShiftOperatorTestMethod);
}


StringTest::~StringTest() {}


   /*=====================================================================*/
void StringTest::StringEmptyTest() const
{
	System::String str1 = System::String::Empty;
	System::String str2("");

	bool expected = true;
	bool actual = (str1 == str2);
	UnitTesting::Assert::AreEqual(expected, actual);
}


   /*=====================================================================*/
void StringTest::GetLengthTest() const
{
	System::String str1;
	int expected = 0;
	int actual = str1.GetLength();
	UnitTesting::Assert::AreEqual(expected, actual);

	str1 = "abc";
	expected = 3;
	actual = str1.GetLength();
	UnitTesting::Assert::AreEqual(expected, actual);
}


   /*=====================================================================*/
void StringTest::EqualOperatorTest() const
{
	System::String str1("abc");
	System::String str2("abc");

	bool expected = true;
	bool actual = (str1 == str2);
	UnitTesting::Assert::AreEqual(expected, actual);
}


void StringTest::AssignmentOperatorTest() const
{
	System::String str1("abc");
	System::String str2 = str1;

	bool expected = true;
	bool actual = (str1 == str2);
	UnitTesting::Assert::AreEqual(expected, actual);
}


void StringTest::PlusOperatorTest() const
{
	System::String str1("abc");
	System::String str2("def");
	System::String str3 = str1 + str2;

	bool expected = true;
	bool actual = (str3 == "abcdef");
	UnitTesting::Assert::AreEqual(expected, actual);
}


void StringTest::PlusEqualOperatorTest() const
{
	System::String str1("abc");
	System::String str2("def");
	str1 += str2;

	bool expected = true;
	bool actual = (str1 == "abcdef");
	UnitTesting::Assert::AreEqual(expected, actual);
}


   /*=====================================================================*/
void StringTest::LeftShiftOperatorTest() const
{
	System::String str1;
	unsigned char aChar = 'a';
	str1 << aChar;

	bool expected = true;
	bool actual = (str1 == "a");
	UnitTesting::Assert::AreEqual(expected, actual);

	System::String str2;
	int anInt = 123456;
	str2 << anInt;
	actual = (str2 == "123456");
	UnitTesting::Assert::AreEqual(expected, actual);

	System::String str3;
	const char* aCharPointer = "abc";
	str3 << aCharPointer;
	actual = (str3 == "abc");
	UnitTesting::Assert::AreEqual(expected, actual);
}


   /*=====================================================================*/
System::String StringTest::ToString() const
{
	return System::String("Test::StringTest");
}


SPF_NAMESPACE_END
