/*
    Internet.cpp
    The module represents my demo functions that interacts with internet.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <sstream>
#include <stdexcept>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include "Internet.hpp"
using namespace std;
using namespace Json;

size_t callback(void* contents, size_t size, size_t nmemb, void* user)
{
    auto chunk = reinterpret_cast<char*>(contents);
    auto buffer = reinterpret_cast<vector<char>*>(user);

    size_t priorSize = buffer->size();
    size_t sizeIncrease = size * nmemb;

    buffer->resize(priorSize + sizeIncrease);
    copy(chunk, chunk + sizeIncrease, buffer->data() + priorSize);

    return sizeIncrease;
}

vector<char> download(string url, long* responseCode)
{
    vector<char> data;

    curl_global_init(CURL_GLOBAL_ALL);
    CURL* handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    CURLcode result = curl_easy_perform(handle);
    if (responseCode != nullptr)
        curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, responseCode);
    curl_easy_cleanup(handle);
    curl_global_cleanup();

    if (result != CURLE_OK)
    {
        stringstream err;
        err << "Error downloading from URL \"" << url << "\": " << curl_easy_strerror(result);
        throw runtime_error(err.str());
    }
    for (auto i: data)
        cout<< i;
    return data;
}

int jsonRequest()
{
    const string url("http://api.openweathermap.org/data/2.5/weather?lat=52&lon=86&appid=542ffd081e67f4512b705f89d2a611b2");

    CURL* curl = curl_easy_init();

    // Set remote URL.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Don't bother trying IPv6, which would increase DNS resolution time.
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

    // Don't wait forever, time out after 10 seconds.
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Follow HTTP redirects if necessary.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Response information.
    long httpCode(0);
    unique_ptr<string> httpData(new string());

    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callBack);

    // Hook up data container (will be passed as the last parameter to the
    // callback handling function).  Can be any pointer type, since it will
    // internally be passed as a void pointer.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200)
    {
        cout << "\nGot successful response from " << url << endl;

        // Response looks good - done using Curl now.  Try to parse the results
        // and print them out.
        Value jsonData;
        Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            cout << "Successfully parsed JSON data" << endl;
            cout << "\nJSON data received:" << endl;
            cout << jsonData.toStyledString() << endl;

            const string dateString(jsonData["date"].asString());
            const size_t unixTimeMs(
                    jsonData["milliseconds_since_epoch"].asUInt64());
            const string timeString(jsonData["time"].asString());

            cout << "Natively parsed:" << std::endl;
            cout << "\tDate string: " << dateString << endl;
            cout << "\tUnix timeMs: " << unixTimeMs << endl;
            cout << "\tTime string: " << timeString << endl;
            cout << endl;
            return 0;
        }
        else
        {
            cout << "Could not parse HTTP data as JSON" << endl;
            cout << "HTTP data was:\n" << *httpData.get() << endl;
            return 1;
        }
    }
    else
    {
        cout << "Couldn't GET from " << url << " - exiting" << endl;
        return 1;
    }
}





