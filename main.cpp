#include <iostream>
#include <fstream>
#include "httpGETandParsingJson.h"

// arguments -> --Vname= --Vnom= --FileName= --DateDate= --Date=

int main(int argc, char *argv[]) {

    int amount = 1;
    std::string date = getLocalTime();
    std::string currency;
    std::string dateDate = "0";
    std::string fileName = "0";
    std::string key = "cur_live_moQtYE12BpEHgXd65yprT9fom08eqGZAjQ6bBYzN";
    bool controlData = true; // if date in request = false


//    request processing
    for (int i = 0; i < argc; ++i) {
        std::string argument = argv[i];
        if (argument.substr(2, argument.find('=') - 1) == "Vname=") {
            currency = argument.substr(argument.find('=') + 1, argument.size() - 1);
        } else if (argument.substr(2, argument.find('=') - 1) == "Vnom=") {
            amount = std::stoi(argument.substr(argument.find('=') + 1, argument.size() - 1));
        } else if (argument.substr(2, argument.find('=') - 1) == "Date=") {
            date = argument.substr(argument.find('=') + 1, argument.size() - 1);
            controlData = false;
        } else if (argument.substr(2, argument.find('=') - 1) == "DateDate=") {
            if (controlData) {
                dateDate = argument.substr(argument.find('=') + 1, argument.size() - 1);
            }
        } else if (argument.substr(2, argument.find('=') - 1) == "FileName=") {
            fileName = argument.substr(argument.find('=') + 1, argument.size() - 1);
        } else {
            continue;
        }
    }

//    output
    if (fileName == "0") {
        if (dateDate == "0") {
            std::cout << currency + ' ' + date + ' ' << getCurrencyValue(currency, key, date) * amount;
        } else {
            std::vector<std::string> datesBetween;
            dateTOdate(dateDate, datesBetween);
            for (int i = 0; i < datesBetween.size(); ++i) {
                std::cout << currency + ' ' + datesBetween[i] + ' '
                          << getCurrencyValue(currency, key, datesBetween[i]) * amount << '\n';
            }
        }
    } else {
        if (dateDate == "0") {
            std::ofstream fout;
            fout.open(fileName);

            fout << currency + ' ' + date + ' ' << getCurrencyValue(currency, key, date) * amount;

            fout.close();
        } else {
            std::ofstream fout;
            fout.open(fileName);
            std::vector<std::string> datesBetween;
            dateTOdate(dateDate, datesBetween);
            for (int i = 0; i < datesBetween.size(); ++i) {
                fout << currency + ' ' + datesBetween[i] + ' '
                     << getCurrencyValue(currency, key, datesBetween[i]) * amount << '\n';
            }
            fout.close();
        }
    }
    return 0;
}
