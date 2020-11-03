#include<iostream>
namespace org {
namespace kpit {
  int hmax=75;
namespace kivi {
class Sensor {};
void poll();
int tmax = 30;
namespace comm {
  class Server  {

  }
}
// Access Sensor, poll, tmax directly
} // namespace kivi
} // namespace kpit
} // namespace org
/*using org::kpit::kivi::poll;
using org::kpit::kivi::Sensor;
using org::kpit::kivi::tmax;*/

using namespace org::kpit;       //only direct symbols are accessible
using namespace org::kpit::kivi;
using namespace org::kpit::kivi::comm;

int main() {
  org::kpit::kivi::Sensor s1;
  org::kpit::kivi::poll();
  std::cout << org::kpit::kivi::tmax << "\n";
  return 0;
}
