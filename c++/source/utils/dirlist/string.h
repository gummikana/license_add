/*************************************************************************** * * Copyright (c) 2010 Petri Purho, Dennis Belfrage * * This software is provided 'as-is', without any express or implied * warranty.  In no event will the authors be held liable for any damages * arising from the use of this software. * Permission is granted to anyone to use this software for any purpose, * including commercial applications, and to alter it and redistribute it * freely, subject to the following restrictions: * 1. The origin of this software must not be misrepresented; you must not *    claim that you wrote the original software. If you use this software *    in a product, an acknowledgment in the product documentation would be *    appreciated but is not required. * 2. Altered source versions must be plainly marked as such, and must not be *    misrepresented as being the original software. * 3. This notice may not be removed or altered from any source distribution. * ***************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// 
// string.h
//
// Writen 10.10.2003
// by Petri Purho ( pete@markkupurho.fi )
//
// You are free to use this as you wish.                              
//
// For example of how to use this function check
// http://koti.mbnet.fi/kumikana/soodaus/cpp/Split/example.cpp    
//
//.............................................................................
//
// 24.08.2006 Pete
//		Fixed some warning that msvc2005 was throwing.
//
// 17.02.2006 Pete
//		Added StringFindFirstOf() function because some of the StringFind()
//		actually needed a StringFindFirstOf() function
//
// 02.10.2005 Pete
//		Fixed a bug in Split() methods. They were using 
//		find_first_of( separator ), instead of find( separator ). This caused
//		problems with multiple character separators which might contain 
//		characters the splittable string contained. Added a unit test to fry 
//		the fuck.
//
// 29.09.2005 Pete
//		Fixed some bugs / extra copying and other nasty crap from 
//		RemoveWhiteSpace function. Also added a unit test for it.
//
// 28.09.2005 Pete
//		Added unit tests for the Split() functions, and re-ordered the unit 
//		tests for strings.
//	
// 30.08.2005 Pete
//		Added	std::string			ConvertNumbersToString( const std::vector< int >& array )
//		and		std::vector< int >	ConvertStringToNumbers( const std::string& str )
//		methods
//		and a unit test for them. I should add a unit test for the rest of the 
//		methods some day.
//
// 08.02.2005 Pete
//		Added the StringReplace() function
//
// 05.08.2004 Pete
//		Renamed this to string.h and moved this in to another place.
//                                                                    
//=============================================================================
#pragma warning ( disable : 4786)

#ifndef INC_STRING_H
#define INC_STRING_H

#pragma warning(disable:4786) // Poistaa ilkeet warningit mit� stl antaa jos k�ytt�� stringi�

#include <vector>
#include <string>

// #include "../../config/cengdef.h"
// __CENG_BEGIN	// NAMESPACE?



//! This thing works the same way as PHP explode it cuts up the _string with 
//! _separator and pushes the peaces into a vector and returns that vector.
/*!
	Description of explode from php.net
	
	Returns an array of strings, each of which is a 
	substring of string formed by splitting it on 
	boundaries formed by the string separator. 
*/
std::vector <std::string> Split( const std::string& _separator, std::string _string, bool include_empty = false );

//! If limit is set, the returned array will contain a maximum of limit 
//! elements with the last element containing the rest of string. 
std::vector <std::string> Split( const std::string& _separator, std::string _string, int _limit );

//! This will perform so called string split, something I came up with. It 
//! doesn't split the stuff that is inside the quetemarks ( " ). Why is this so 
//! usefull well find out for our self... In console this is used in some handy 
//! places
std::vector<std::string> StringSplit( const std::string& _separator, std::string _string );

//! Same thing as StringSplit( separator, string ) but with limit
std::vector<std::string> StringSplit( const std::string& _separator, std::string _string, int _limit );


//! Finds the first of _what in _line, that is not inside the quotemarks ("). 
//! Usefull in various places where string manipulation is used
size_t StringFind( const std::string& _what, const std::string& _line, size_t _begin = 0 );

//! Finds the first character of what in line that is not inside quotemarks
size_t StringFindFirstOf( const std::string& what, const std::string& line, size_t begin = 0 );

//! Replace all occurrences of the search string with the replacement string
/*!
	Works the same way as php's str_replace() function 
*/
std::string StringReplace( const std::string& what, const std::string& with, const std::string& in_here, int limit = -1 );


//! for removing white space
std::string RemoveWhiteSpace( std::string line );

//! returns a string in uppercase
std::string Uppercase( const std::string& _string );
//! returns a string in lowercase
std::string Lowercase( const std::string& _string );

//! for some vector to string conversation
std::string ConvertNumbersToString( const std::vector< int >& array );

//! for some string to vector conversation
std::vector< int > ConvertStringToNumbers( const std::string& str );


#endif


