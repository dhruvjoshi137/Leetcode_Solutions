/*You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:

The first ten characters consist of the phone number of passengers.
The next character denotes the gender of the person.
The following two characters are used to indicate the age of the person.
The last two characters determine the seat allotted to that person.
Return the number of passengers who are strictly more than 60 years old.*/

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str[] = {"7868190130M7522","5303914400F9211", "9273338290F4010"};
    int n = sizeof(str)/sizeof(string);
    int cnt=0;
    int i;
    string age= {str[11],str[12]};
    
    for(i=0;i<n;i++){
        if(age>"60"){
            cnt++;
            }
            }
    cout<<cnt<<endl;
    return 0;

}

