#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((string*)userp)->append((char*)contents, size *nmemb);
  return size * nmemb;
}
 
class Getpage {
  
  public: 
    string request_page(const char* destination, string* data);

  private:
//    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    int main(int argi, char* url_string[]);

};
