/* data_list.h
	JHT, September 22 : 2022 

  Header for the data list struct. This contains information about all
  the different data types that have been added to ccc. 

  It has the following member functions:
  ccc::Data_List DATA;

  Element Access
  ----------------
  operatior[]

  Iterators
  ----------------
  begin/cbegin
  end/cend 

  Utility
  -----------------
  printf_string

  Capacity
  ----------------
  size
  max_size
  capacity
  reserve
  empty
  
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

  //find

  //generate_unique_name

  /* Acess Operators */
  Data& operator[](const _CCC_SIZE_T_ I) {return list[I];}
  const Data& operator[](const _CCC_SIZE_T_ I) const {return list[I];}

  /* Iterators */
  auto begin() { return list.begin(); }
  auto cbegin() const { return list.cbegin(); }
  auto end() { return list.end();}
  auto cend() const { return list.cend();}

  /* Capacity */
  void reserve(const _CCC_SIZE_T_ RES) { list.reserve(RES); }
  void empty() { list.empty(); }
  _CCC_SIZE_T_ size() const { return list.size(); }
  _CCC_SIZE_T_ max_size() const { return list.max_size(); }
  _CCC_SIZE_T_ capacity() const { return list.capacity(); }

  /* Utility */
  std::string printf_string() const;
  
  
};

/* printf_string 
   returns a std::string which can be printed
*/
std::string Data_List::printf_string() const {
  std::string STR;
  for (auto const& data : list ) {
    STR.append(data.printf_string());   
    STR.push_back('\n');
  }
  return STR;
};


}; //end ccc namespace

#endif
