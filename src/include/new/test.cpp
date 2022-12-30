#include "typedef.h"
#include "nodes.h"
#include <memory>

struct Node {
  std::shared_ptr<void> ptr;

  template<typename T> T get_as() {return static_cast<T>(ptr.get());}
};



int main() {

  double ff = 10;
  printf("address of ff is %p \n",static_cast<void*>(&ff));
  printf("value of f is %lf \n", ff);
  printf("\n");

  std::shared_ptr<double> f = std::make_shared<double>(5);  
  printf("address of pointer f %p \n",static_cast<void*>(&f));
  printf("address of shared stuff %p \n",static_cast<void*>(f.get()));
  printf("value of pointer f %lf \n",*f);
  printf("\n");

  auto f2 = f;
  printf("address of pointer f %p \n",static_cast<void*>(&f2));
  printf("address of shared stuff %p \n",static_cast<void*>(f2.get()));
  printf("value of pointer f %lf \n",*f2);
  printf("\n");

  void* p = static_cast<void*>(&ff);
  printf("address of pointer f %p \n",static_cast<void*>(&p));
//  printf("value of pointer f %lf \n",static_cast<double&>(p));
  printf("value of pointer f %lf \n",*((double*)(p)));
  printf("value of pointer f %lf \n",*(static_cast<double*>(p)));
  printf("\n");

  Node D {static_cast<std::shared_ptr<void>>(f2)};
  printf("address of pointer f %p \n",static_cast<void*>(&D.ptr));
  printf("address of shared stuff %p \n",D.get_as<void*>());
//  printf("address of shared stuff %p \n",static_cast<void*>(D.ptr.get()));
  printf("value of pointer f %lf \n",*(static_cast<double*>(D.ptr.get())));
  printf("value of pointer f %lf \n",*(D.get_as<double*>()));
  printf("\n");

  printf("new shit \n");

  
  //auto HEAD = CCC::make_data_node("E",{_CCC_DUM_});
  //printf("test head is... %s \n",HEAD.printf_string().c_str());
  CCC::Data_Node HEAD = {"E",{_CCC_DUM_}};
  CCC::Node FF(HEAD); 

  printf("HEAD is ... \n %s \n",HEAD.printf_string().c_str());
  printf("FF is ... \n %s \n",FF.printf_string().c_str());


  return 0;
}
