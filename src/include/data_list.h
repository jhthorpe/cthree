/* data_list.h
	JHT, September 22 : 2022 

  Header for the data list struct. This contains information about all
  the different data types that have been added to ccc. 

  It is important to note that find/cfind, which re

  It has the following member functions:

  Element Access
  ----------------
  operator[]		: returns reference for I'th element, no bounds check
  front()		: returns reference to first element
  back()		: returns reference to last element

  Iterators
  ----------------
  begin/cbegin		: returns iterator to start of list (cost if cbegin)
  end/cend		: returns iterator to end of list (const if cend) 

  Utility
  -----------------
  printf_string		: returns a std::string for printf or cout
  find/cfind		: returns reference to data element. If not found, returns  
			    reference to data element one beyond length of Data vector. 
                            IMPORTANT: this reference should not be taken as thread-safe!
                                       It is not guarenteed that the data will not move 
                                       in the background. In most cases, exists should be
                                       prefered
  exists		: returns a boolean true if data exists in list, false if not
  add_if_unique		: Adds a Data struct to the Data_List if that struct is not already in it
  is_within_bounds	: returns a boolean true if reference is within range, but does NOT
                            check for validity or correctness of this reference 

  is_within_upper_bound	: returns boolean true if reference is within upper bound of list, 
                            but does NOT cehck for validity or correctness of this reference

  Capacity
  ----------------
  size			: returns number of elements in list
  max_size		: returns max number of elements in list
  capacity		: returns capacity of list
  reserve		: reserves capacity of list
  empty			: erases the list
  
*/

#ifndef _CCC_DATA_LIST_H_
#define _CCC_DATA_LIST_H_

#include <vector>
#include <algorithm>

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


  //generate_unique_name

  /* Acess Operators */
  Data& operator[](const _CCC_SIZE_T_ I) {return list[I];}
  const Data& operator[](const _CCC_SIZE_T_ I) const {return list[I];}
  Data& front() { return list.front(); }
  const Data& front() const { return list.front(); }
  Data& back() { return list.back(); }
  const Data& back() const { return list.back(); }

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
  const Data& cfind(const Data& IN) const; 
  Data& find(const Data& IN); 
  bool exists(const Data& IN) const;
  void add_if_unique(const Data& IN); 
  bool is_within_bounds(const Data& IN) const;
  bool is_within_upper_bound(const Data& IN) const;
  
  
};//end Data_List struct

/* printf_string 
   returns a std::string which can be printed */
std::string Data_List::printf_string() const {
  std::string STR;
  for (auto const& data : list ) {
    STR.append(data.printf_string());   
    STR.push_back('\n');
  }
  return STR;
};

/* constant reference find */
const Data& Data_List::cfind(const Data& IN) const {
  return *(std::find(list.cbegin(),list.cend(),IN)); 
}

/* nonconst reference find */
Data& Data_List::find(const Data& IN) {
  return *(std::find(list.begin(),list.end(),IN)); 
}

/* is_within_bounds */
bool Data_List::is_within_bounds(const Data& IN) const {
  return (&IN < &(*cend()) && &IN >= &(*cbegin())) ? true : false; 
}

/* is_within_upper_bound */
bool Data_List::is_within_upper_bound(const Data& IN) const {
  return (&IN < &(*cend())) ? true : false; 
}

/* exists */
bool Data_List::exists(const Data& IN) const {
  auto const& REF = cfind(IN);
  return is_within_upper_bound(REF); 
}

/* add_if_unique */
void Data_List::add_if_unique(const Data& IN) {
  const Data& REF = cfind(IN); 
  if (!is_within_upper_bound(REF)) {
    list.push_back(IN);
  }
}


}; //end ccc namespace

#endif
