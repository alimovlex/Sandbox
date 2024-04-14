//
// Created by alimovlex
//

//
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<char> download(string url, long* responseCode);
namespace
{
    size_t callBack(
            const char* in,
            size_t size,
            size_t num,
            string* out)
    {
        const size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}

int get_public_ip_info();
int get_local_ip_info();
