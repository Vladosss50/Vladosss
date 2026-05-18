#pragma once

class WebLink {
private:
    char* url;
    char* description;

public:
    WebLink(const char* linkUrl, const char* linkDesc);
    ~WebLink();
    void print();
};