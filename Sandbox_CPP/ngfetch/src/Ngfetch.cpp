/*
    Internet.cpp
    The module represents my demo functions that interacts with internet.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <curl/curl.h>
#include <json/json.h>
#include <sstream>
#include <stdexcept>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include <sysexits.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

#include "Ngfetch.hpp"
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

int get_local_ip_info() {
    struct ifaddrs* ptr_ifaddrs = nullptr;

    auto result = getifaddrs(&ptr_ifaddrs);
    if( result != 0 ){
        cout << "`getifaddrs()` failed: " << strerror(errno) << endl;

        return EX_OSERR;
    }

    for(
            struct ifaddrs* ptr_entry = ptr_ifaddrs;
            ptr_entry != nullptr;
            ptr_entry = ptr_entry->ifa_next
            ){
        string ipaddress_human_readable_form;
        string netmask_human_readable_form;

        string interface_name = string(ptr_entry->ifa_name);
        sa_family_t address_family = ptr_entry->ifa_addr->sa_family;
        if( address_family == AF_INET ){
            // IPv4

            // Be aware that the `ifa_addr`, `ifa_netmask` and `ifa_data` fields might contain nullptr.
            // Dereferencing nullptr causes "Undefined behavior" problems.
            // So it is need to check these fields before dereferencing.
            if( ptr_entry->ifa_addr != nullptr ){
                char buffer[INET_ADDRSTRLEN] = {0, };
                inet_ntop(
                        address_family,
                        &((struct sockaddr_in*)(ptr_entry->ifa_addr))->sin_addr,
                        buffer,
                        INET_ADDRSTRLEN
                );

                ipaddress_human_readable_form = string(buffer);
            }

            if( ptr_entry->ifa_netmask != nullptr ){
                char buffer[INET_ADDRSTRLEN] = {0, };
                inet_ntop(
                        address_family,
                        &((struct sockaddr_in*)(ptr_entry->ifa_netmask))->sin_addr,
                        buffer,
                        INET_ADDRSTRLEN
                );

                netmask_human_readable_form = string(buffer);
            }

            cout << interface_name << ": IP address = " << ipaddress_human_readable_form << ", netmask = " << netmask_human_readable_form << endl;
        }
        else if( address_family == AF_INET6 ){
            // IPv6
            uint32_t scope_id = 0;
            if( ptr_entry->ifa_addr != nullptr ){
                char buffer[INET6_ADDRSTRLEN] = {0, };
                inet_ntop(
                        address_family,
                        &((struct sockaddr_in6*)(ptr_entry->ifa_addr))->sin6_addr,
                        buffer,
                        INET6_ADDRSTRLEN
                );

                ipaddress_human_readable_form = string(buffer);
                scope_id = ((struct sockaddr_in6*)(ptr_entry->ifa_addr))->sin6_scope_id;
            }

            if( ptr_entry->ifa_netmask != nullptr ){
                char buffer[INET6_ADDRSTRLEN] = {0, };
                inet_ntop(
                        address_family,
                        &((struct sockaddr_in6*)(ptr_entry->ifa_netmask))->sin6_addr,
                        buffer,
                        INET6_ADDRSTRLEN
                );

                netmask_human_readable_form = string(buffer);
            }

            cout << interface_name << ": IP address = " << ipaddress_human_readable_form << ", netmask = " << netmask_human_readable_form << ", Scope-ID = " << scope_id << endl;
        }
        else {
            // AF_UNIX, AF_UNSPEC, AF_PACKET etc.
            // If ignored, delete this section.
        }
    }

    freeifaddrs(ptr_ifaddrs);
    return 0;
}

int get_public_ip_info()
{
    const string url("http://ip-api.com/json");

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
        //cout << "\nGot successful response from " << url << endl;

        // Response looks good - done using Curl now.  Try to parse the results
        // and print them out.
        Value jsonData;
        Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            cout << "Successfully parsed JSON data" << endl;
            //cout << "\nJSON data received:" << endl;
            //cout << jsonData.toStyledString() << endl;

            const string PUBLIC_IP(jsonData["query"].asString());
            const string ISP(jsonData["isp"].asString());
            const string TIMEZONE(jsonData["timezone"].asString());
            const string COUNTRY(jsonData["country"].asString());
            const string REGION(jsonData["regionName"].asString());
            const string CITY(jsonData["timezone"].asString());
            const string ZIP(jsonData["zip"].asString());
            //const size_t unixTimeMs(jsonData["milliseconds_since_epoch"].asUInt64());
            //const string timeString(jsonData["time"].asString());

            //cout << "Natively parsed:" << endl;
            cout << "\tPublic IP address: " << PUBLIC_IP << endl;
            cout << "\tISP: " << ISP << endl;
            cout << "\tTimezone: " << TIMEZONE << endl;
            cout << "\tCountry: " << COUNTRY << endl;
            cout << "\tRegion: " << REGION << endl;
            cout << "\tCity: " << CITY << endl;
            cout << "\tZIP: " << ZIP << endl;
            //cout << "\tUnix timeMs: " << unixTimeMs << endl;
            //cout << "\tTime string: " << timeString << endl;

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





