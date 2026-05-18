#include "WebLink.h"
#include <iostream>
#include <cstring>
using namespace std;

WebLink::WebLink(const char* linkUrl, const char* linkDesc) {
    size_t lenUrl = strlen(linkUrl);
    url = new char[lenUrl + 1];
    strcpy_s(url, lenUrl + 1, linkUrl);

    size_t lenDesc = strlen(linkDesc);
    description = new char[lenDesc + 1];
    strcpy_s(description, lenDesc + 1, linkDesc);
}

WebLink::~WebLink() {
    delete[] url;
    delete[] description;
}

void WebLink::print() {
    cout << "Описание: " << description << endl;
    cout << "URL: " << url << endl;
}