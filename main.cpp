#include <iostream>
#include <vector>
  
using namespace std; 

    int convertRomanToInt(std::string romanNumberToConvert) {
        int convertedValue = 0;
        /**
         * Hier die Gegenüberstellung Römische Ziffer mit Arabischen Lettern.
         * Wichtig: Die Sonderformen, CM, CD, XC, XL, IX, IV mit betrachtet.
         * Wichtig2: Die Reihenfolge ist wichtig damit die höchsten, wie M, 
         * zuerst aus dem String genommen werden.
         */
        vector<pair<std::string, int>> romanLettersAndIntRepresenation( {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}        
        });

        while (romanNumberToConvert.size() > 0) { //Only when greater zero
            for (auto i = romanLettersAndIntRepresenation.begin(); i != romanLettersAndIntRepresenation.end(); ++ i) { //Iterator from Start to the End of romanLettersAndIntRepresenation
                auto find = romanNumberToConvert.find(i->first); //Search if the 
                if (find == 0) {
                    convertedValue += i->second;
                    romanNumberToConvert = romanNumberToConvert.substr(find + i->first.size()); // Reduziere die römische Zahl um die eben schon gefundene.
                }
            }
        }
        return convertedValue;
    }

// Lösung durch die find() langsam, geht schneller. Aber sind drei Guinness.

int main() {  
    const std::string romanNumber = "MMCMXCIX";
	std::cout << "Wert als römische Zahl " << romanNumber << " : Als Integer " << convertRomanToInt( romanNumber ) << std::endl;
    return 0;  
}
