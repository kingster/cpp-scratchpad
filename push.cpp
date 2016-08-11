#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Easy.hpp>
#include <sstream>
#include "cxxopts.hpp"
#include <fstream>

int main(int argc, char* argv[])
{

    std::string inputFile;
    cxxopts::Options options(argv[0]);
    options.add_options()("f,file", "File", cxxopts::value<std::string>(inputFile), "FILE");
    options.parse(argc, argv);

    if (options.count("f"))
    {
        std::cout << "ReadFile : " << options["f"].as<std::string>() << " inFile " << inputFile
                  << std::endl;

        std::string line;
        std::ifstream infile(inputFile);

        while (infile && std::getline(infile, line))
        {
            std::cout << "Line : " << line << std::endl;
        }

    }

    std::cout << "Hello, world!\n";

    // RAII cleanup
    curlpp::Cleanup myCleanup;

    curlpp::Easy request;
    request.setOpt(new curlpp::options::Url(std::string("http://10.84.178.131:28000/v1/registration/push/android/ConnektSampleApp/8b742d1c870d5ba53ccce8ea318226d6")));
    request.setOpt(new curlpp::options::FollowLocation("true"));
//    request.setOpt(new curlpp::options::Verbose(true));

    std::list<std::string> header;
    header.push_back("x-api-key: sandbox-key-01");
    header.push_back("Content-Type: application/json");
    request.setOpt(new curlpp::options::HttpHeader(header));

    request.setOpt(new curlpp::options::PostFields(std::string("{\"token\": \"token\", \"osVersion\": \"7.0\", \"appVersion\": \"720600\", \"brand\": \"Huawei\", \"model\": \"Nexus 6P\"}")));
    request.setOpt(new curlpp::options::CustomRequest("PUT"));

    request.perform();

    std::ostringstream os;
    os << request;

    std::string httpBody = os.str();

    std::cout << httpBody << "\n" ;
}
