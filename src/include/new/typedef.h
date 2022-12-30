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
#define _CCC_INDEX_T_ int
#define _CCC_OCC_ 0
#define _CCC_VRT_ 1
#define _CCC_GEN_ 2
#define _CCC_FRZ_ 3
#define _CCC_DUM_ 4
//static const char _CCC_LABELS_[6] = "ovgf ";
static const std::string _CCC_LABELS_ = "ovgf ";


#endif 
