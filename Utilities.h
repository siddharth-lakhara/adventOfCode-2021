#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Utilities {
  public:
    static vector<string> ReadAllLinesInFile(const filesystem::path& Path);
    static std::vector<std::string> SplitString(const std::string& String, const std::string& Delimiter);
	  static std::vector<int> ReadCommaSeparatedIntegers(const std::string& String);
    
    static void VerifyElseCrash(bool bAssert);
    static void VerifyNotReached();
};