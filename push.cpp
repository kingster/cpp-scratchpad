#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Easy.hpp>
#include <sstream>

using namespace std;

int main()
{

    cout << "Hello, world!\n";

    // RAII cleanup
    curlpp::Cleanup myCleanup;

    curlpp::Easy request;
    request.setOpt(new curlpp::options::Url(string("http://10.84.178.131:28000/v1/registration/push/android/ConnektSampleApp/8b742d1c870d5ba53ccce8ea318226d6")));
    request.setOpt(new curlpp::options::FollowLocation("true"));
    // request.setOpt(new curlpp::options::Verbose(true));

    list<std::string> header;
    header.push_back("x-api-key: sandbox-key-01");
    header.push_back("Content-Type: application/json");
    request.setOpt(new curlpp::options::HttpHeader(header));

    request.setOpt(new curlpp::options::PostFields(string("{\"token\": \"token\", \"osVersion\": \"7.0\", \"appVersion\": \"720600\", \"brand\": \"Huawei\", \"model\": \"Nexus 6P\"}")));
    request.setOpt(new curlpp::options::CustomRequest("PUT"));

    request.perform();

    std::ostringstream os;
    os << request;

    string httpBody = os.str();

    cout << httpBody << "\n" ;
}
