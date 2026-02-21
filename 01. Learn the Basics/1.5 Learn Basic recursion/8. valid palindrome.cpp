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

//using functions from c++ library
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : Two-pointer traversal                               │
│          No extra string construction                        │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/valid-palindrome/description/