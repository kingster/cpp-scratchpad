#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Easy.hpp>
#include <sstream>

using namespace std;


int main()
{

  std::cout << "Hello, world!\n";

  // RAII cleanup
  curlpp::Cleanup myCleanup;

  // Send request and get a result.
  // Here I use a shortcut to get it in a string stream ...

  std::ostringstream os;
  os << curlpp::options::Url(std::string("https://raw.githubusercontent.com/Flipkart/espion/master/README.md"));

  std::string asAskedInQuestion = os.str();

  std::cout << asAskedInQuestion << "\n" ;
}
