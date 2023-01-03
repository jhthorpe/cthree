#include "typedef.h"
#include "nodes.h"
#include <memory>
#include <functional>

int main() {
  CCC::Node A(CCC::Data_Node{"A",{_CCC_GEN_,_CCC_GEN_}});
  CCC::Node B(CCC::Data_Node{"B",{_CCC_GEN_,_CCC_GEN_}});
  CCC::Node C(CCC::Data_Node{"C",{_CCC_GEN_,_CCC_GEN_}});
  CCC::Node D(CCC::Data_Node{"D",{_CCC_GEN_,_CCC_GEN_}});

  //CCC::Operation_Index t1({std::get<CCC::Data_Node>(A.N),0}); 
  CCC::Operation_Index t1({A.data(),0}); 
  CCC::Operation_Index t2({B.data(),0});
  CCC::Index_Map m1({{t1,t2}});

  CCC::Index_Map m2({ {CCC::Operation_Index{A.data(),0}, CCC::Operation_Index{B.data(),0}}
                    }); 

  /*CCC::Node O1(CCC::Operation_Node{"A=B+C",
                                   m2
                                  });*/

  CCC::Node O1(CCC::Operation_Node{
                 "A=B+C",
                  CCC::Index_Map{{
                    {CCC::Operation_Index{A.data(),0},CCC::Operation_Index{B.data(),0}},
                    {CCC::Operation_Index{A.data(),1},CCC::Operation_Index{B.data(),1}},
                    {CCC::Operation_Index{A.data(),0},CCC::Operation_Index{C.data(),0}},
                    {CCC::Operation_Index{A.data(),1},CCC::Operation_Index{C.data(),1}},
                    {CCC::Operation_Index{B.data(),0},CCC::Operation_Index{C.data(),0}},
                    {CCC::Operation_Index{B.data(),1},CCC::Operation_Index{C.data(),1}},
                  }} 
               });

  printf("%s \n",A.printf_string().c_str());
  printf("%s \n",B.printf_string().c_str());
  printf("%s \n",C.printf_string().c_str());
  printf("%s \n",D.printf_string().c_str());

  printf("\n%s \n",O1.printf_string().c_str());


  return 0;
}
