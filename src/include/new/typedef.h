/* typedef.h
	JHT, Septeber 19, 2022 : created

  header file for cthree typedefs
*/
#ifndef _CCC_TYPEDEF_H_
#define _CCC_TYPEDEF_H_

#include <cstddef>
#include <string>

//REPLACE THESE WITH AUTOMAKE
//Basic type defitions
#define _CCC_INT_T_ int
#define _CCC_LONG_T_ long
#define _CCC_SIZE_T_ size_t
#define _CCC_FLOAT_T_ double

//Occupied,virtual, general types
// These are labeled with a single-letter abreviation
#define _CCC_INDEX_T_ char
#define _CCC_GEN_ 'g'
#define _CCC_OCC_ 'o'
#define _CCC_VRT_ 'v'
#define _CCC_FRZ_ 'f'
#define _CCC_DUM_ 'd'


#endif 
