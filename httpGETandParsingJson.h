#ifndef VERYLASSSY_HTTPGETANDPARSINGJSON_H
#define VERYLASSSY_HTTPGETANDPARSINGJSON_H

#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <chrono>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>


// return local time
std::string getLocalTime();

//get request and parsing json
int getCurrencyValue(const std::string &currency, const std::string &key, const std::string &date);

//return vector with dates, from range between 2 different dates.
void dateTOdate(const std::string &dateDate, std::vector<std::string> &datesBetween);

#endif
