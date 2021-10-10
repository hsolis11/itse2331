#include "phonenumber.h"

ostream& operator<<(ostream& output, const PhoneNumber& number) {
    output << "Phone: "<< number.phone << "\n"
        << "Area code: " << number.areaCode << "\nExchange: "
        << number.exchange << "\nLine: " << number.line << "\n";
    return output;
}

istream& operator>>(istream& input, PhoneNumber& number) {
    char phone[15];
    input.getline(phone, 15);
    bool count_issue = false;
    bool digit_issue = false;

    if(strlen(phone) == 14){

        digit_issue = (phone[1] == '1' || phone[1] == '0' || phone[6] == '1' || phone[6] == '0');

        if(!digit_issue){
            strcpy(number.phone, phone);
            copy(number.phone+1, number.phone+4, number.areaCode);
            number.areaCode[3] = '\0';
            copy(number.phone+6, number.phone+9, number.exchange);
            number.exchange[3] = '\0';
            copy(number.phone+10, number.phone+14, number.line);
            number.line[4] = '\0';
        }

    } else {
        count_issue = true;
    }

    if(count_issue || digit_issue){
        input.setstate(ios::failbit);
    }

    return input;
}