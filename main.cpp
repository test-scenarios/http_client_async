#include <cstdlib>
#include <vector>
#include <thread>
#include "session.hpp"


int main(int argc, char** argv)
{
  // Check command line arguments.
  if(argc != 4 && argc != 5)
    {
      std::cerr <<
	"Usage: http-client-async <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
	"Example:\n" <<
	"    http-client-async www.example.com 80 /\n" <<
	"    http-client-async www.example.com 80 / 1.0\n";
      return EXIT_FAILURE;
    }
  auto const host = argv[1];
  auto const port = argv[2];
  auto const target = argv[3];
  int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;
  
  // The io_context is required for all I/O
  net::io_context ioc;
  
  // Launch the asynchronous operation
  for (int n=0; n<10; ++n)
    {
      std::ostringstream os;
      os << target
	 << "test"
	 << n+1
	 << "_20M.csv";
      std::make_shared<session>(ioc)->run(host, port, os.str().c_str(), version);
    }
  
  // Run the I/O service. The call will return when
  // the get operation is complete.
  std::vector<std::thread> tvec;
  for (int t=0; t<4; ++t)
    {
      tvec.emplace_back([&ioc] { ioc.run(); });
    }
  //ioc.run();
  
  for (auto & thr : tvec)
    {
      thr.join();
    }
  
  return EXIT_SUCCESS;
}
