#include <memory>

namespace CCC {

struct Node {
  std::shared_ptr<void> ptr; 

  template<typename T> T get_as() {return static_cast<T>(ptr.get());}
};

}; //end namespace CCC
