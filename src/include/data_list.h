/* data_list.h
	JHT, September 22 : 2022 

  Header for the data list struct. This contains information about all
  the different data types that have been added to ccc
*/

#ifndef _CCC_DATA_LIST_H_
#define _CCC_DATA_LIST_H_

#include <vector>

#include "typedef.h"
#include "data.h"

namespace ccc {

/* Data_List struct
   Current implementation is just a vector of different
   Data's. This should probably be seperated into lists of 
   different MBE orders
*/ 
struct Data_List {
  std::vector<Data> list;

  //add_if_unique
  //find_by_string
  //find_by_

  //print types

  //generate_unique_name
  
};

}; //end ccc namespace

#endif
