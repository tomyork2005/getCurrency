#include "httpGETandParsingJson.h"

using json = nlohmann::json;
using namespace std::chrono;

int getCurrencyValue(const std::string &currency, const std::string &key, const std::string &date) {
    std::string makeURL =
            "https://api.currencyapi.com/v3/historical?apikey=" + key + "&currencies=RUB&base_currency=" + currency
            + "&date=" + date;
    cpr::Response getResponse = cpr::Get(
            cpr::Url{makeURL});
    json parseResponse = json::parse(getResponse.text);
    int currencyValue = parseResponse["data"]["RUB"]["value"].get<int>();
    return currencyValue;
}

std::string getLocalTime() {
    time_t seconds = time(nullptr);
    tm *localTime = localtime(&seconds);
    localTime->tm_mday = localTime->tm_mday - 2;

    char dateChar[20];
    strftime(dateChar, 20, "%Y-%m-%d", localTime);
    std::string date = dateChar;

    return date;
}

std::vector<std::string> stringSplit(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

tm createTmStruct(int year, int month, int day) {
    tm time_info;
    time_info.tm_sec = 0;
    time_info.tm_min = 0;
    time_info.tm_hour = 0;
    time_info.tm_mday = day;
    time_info.tm_mon = month - 1;
    time_info.tm_year = year - 1900;
    return time_info;
}

void dateTOdate(const std::string &dateDate, std::vector<std::string> &datesBetween) {
    std::vector<std::string> dates = stringSplit(dateDate, '-');
    std::string startDateStr = dates[0];
    std::string endDateStr = dates[1];

    // Разбиваем начальную и конечную даты на составляющие
    std::vector<std::string> startDateParts = stringSplit(startDateStr, '.');
    std::vector<std::string> endDateParts = stringSplit(endDateStr, '.');

    // Получаем день, месяц и год начальной и конечной дат
    int startDay = stoi(startDateParts[0]);
    int startMonth = stoi(startDateParts[1]);
    int startYear = stoi(startDateParts[2]);

    int endDay = stoi(endDateParts[0]);
    int endMonth = stoi(endDateParts[1]);
    int endYear = stoi(endDateParts[2]);


    tm startTM = createTmStruct(startYear, startMonth, startDay);
    system_clock::time_point start_date = system_clock::from_time_t(mktime(&startTM));

    tm endTM = createTmStruct(endYear, endMonth, endDay);
    system_clock::time_point end_date = system_clock::from_time_t(mktime(&endTM));


    system_clock::time_point current_date = start_date;
    while (current_date <= end_date) {
        time_t current_time = system_clock::to_time_t(current_date);
        tm *current_tm = localtime(&current_time);

        char dateChar[20];
        strftime(dateChar, 20, "%Y-%m-%d", current_tm);
        std::string pushString = dateChar;
        datesBetween.push_back(pushString);

        // Увеличиваем текущую дату на один день
        current_date += hours(24);
    }
}