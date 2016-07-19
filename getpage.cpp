#include "getpage.h"
/*
#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((string*)userp)->append((char*)contents, size *nmemb);
  return size * nmemb;
}
*/
using namespace std;

string Getpage::request_page(char* destination, string* data)
{
  CURL *curl = curl_easy_init();
  CURLcode res;
  string readBuffer;
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, destination);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data->c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data->length());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    //curl_easy_cleanup(curl);
  }
  return readBuffer;
}

int Getpage::main(int argi, char* url_string[])
{
  string result = "points=2048&timestamp=03122016";
  string ans = request_page(url_string[1], &result);
  std::cout << ans << std::endl;
  return 0;
}
   
