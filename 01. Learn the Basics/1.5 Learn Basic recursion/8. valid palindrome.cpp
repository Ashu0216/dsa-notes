#include<bits/stdc++.h>
using namespace std;

class Solution {

    int getLength (string s){
        int i = 0;

        while ( s[i] != '\0'){
            i++;
        }

        return i;
    }

    bool checkValid ( char c){

        if( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            return true;
        }
        return false;
    }

    char toLower(char c){
        if( c>='A' && c<='Z'){
            return c-'A'+'a';
        }
        return c;
    }
public:
    bool isPalindrome(string s) {
        int length = getLength(s);
        string temp;

        for(int i = 0; i< length; i++){
            if(checkValid(s[i])){
                temp.push_back( toLower(s[i]));
            }
        }
        

        // checking palindrom
        int st = 0 ; int e = temp.length() - 1;

        while (st < e){
            if(temp[st] != temp[e])
            return false;

            st++; e--;
        }

        return true;
    }
};

// Link: https://leetcode.com/problems/valid-palindrome/description/