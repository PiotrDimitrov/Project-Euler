/*
   In the card game poker, a hand consists of five cards and are ranked, from
   lowest to highest, in the following way:

     •High Card: Highest value card.
     •One Pair: Two cards of the same value.
     •Two Pairs: Two different pairs.
     •Three of a Kind: Three cards of the same value.
     •Straight: All cards are consecutive chars.
     •Flush: All cards of the same suit.
     •Full House: Three of a kind and a pair.
     •Four of a Kind: Four cards of the same value.
     •Straight Flush: All cards are consecutive chars of same suit.
     •Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

   The cards are valued in the order:
   2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

   If two players have the same ranked hands then the rank made up of the
   highest value wins; for example, a pair of eights beats a pair of fives
   (see example 1 below). But if two ranks tie, for example, both players
   have a pair of queens, then highest cards in each hand are compared (see
   example 4 below); if the highest cards tie then the next highest cards are
   compared, and so on.

   Consider the following five hands dealt to two players:

           Hand  Player 1           Player 2             Winner
           1     5H 5C 6S 7S KD     2C 3S 8S 8D TD       Player 2
                  Pair of Fives       Pair of Eights
           2     5D 8C 9S JS AC     2C 5C 7D 8S QH       Player 1
                  Highest card Ace    Highest card Queen
           3     2D 9C AS AH AC     3D 6D 7D TD QD       Player 2
                  Three Aces          Flush with Diamonds
                  4D 6S 9H QH QC      3D 6D 7H QD QS
           4     Pair of Queens     Pair of Queens       Player 1
                  Highest card Nine   Highest card Seven
                  2H 2D 4C 4D 4S      3C 3D 3S 9S 9D
           5     Full House         Full House           Player 1
                  With Three Fours    with Three Threes

   The file, [1]poker.txt, contains one-thousand random hands dealt to two
   players. Each line of the file contains ten cards (separated by a single
   space): the first five are Player 1's cards and the last five are Player
   2's cards. You can assume that all hands are valid (no invalid characters
   or repeated cards), each player's hand is in no specific order, and in
   each hand there is a clear winner.

   How many hands does Player 1 win?
 */
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace pr54 {
    char chars[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char chars2[4] = {'D', 'H', 'S', 'C'};
    //enum cards {onePair = 10, twoPairs = 20, three = 30, street = 40, flush = 50, fullHouse = 60};

    std::string p1(std::string str){
        std::string res = "";
        for (int i = 0; i < 14; i++){
            res = res + str[i];
        }
        return res;
    }

    std::string p2(std::string str){
        std::string res = "";
        for (int i = 15; i < str.size(); i++){
            res = res + str[i];
        }
        return res;
    }

    std::vector<int> getValues(std::string str){
        //int value[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        std::vector<int> value (13, 0);
        for (int i = 0; i < 13; i+=3){
            for(int j = 0; j < 13; j++){
                if (chars[j] == str[i]){value[j]++; break;}
            }
        }
        return value;
    };

    std::vector<int> getSuits(std::string str){
        std::vector<int> suits (4, 0);
        for (int i = 1; i <= 13; i+=3){
            for(int j = 0; j < 4; j++){
                if (chars2[j] == str[i]){suits[j]++; break;}
            }
        }
        return suits;
    }

    int flushRoyal(std::string str, std::vector<int> val, std::vector<int> sts){
        for (int e : sts){
            if (e != 0 && e != 5){return -1;}
        }
        for (int i = 12; i >= 8; i--){
            if (val[i] != 1) {return -1;}
        }
        return 1000;
    }

    int straightFlush(std::string str, std::vector<int> val, std::vector<int> sts){
        for (int e : sts){
            if (e != 0 && e != 5){return -1;}
        }
        int start = -1;
        for (int i = 0; i < 13; i++){
            if (val[i] > 1) {return -1;}
            if (start < 0 && val[i] == 1){start = i;}
        }
        for (int i = 0; i < 5; i++){
            if (val[i+start] != 1){return -1;}
        }
        return 160 + start;
    }

    int fourKind(std::string str, std::vector<int> val, std::vector<int> sts){
        int value[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (int i = 0; i < 13; i+=3){
            for(int j = 0; j < 13; j++){
                if (chars[j] == str[i]){value[j]++; break;}
            }
        }
        for (int i = 0 ; i < 13; i++){
            if (value[i] == 4){return 140 + i;}
        }
        return -1;
    }

    int fullHouse(std::string str, std::vector<int> val, std::vector<int> sts){
        int value[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (int i = 0; i < 13; i+=3){
            for(int j = 0; j < 13; j++){
                if (chars[j] == str[i]){value[j]++; break;}
            }
        }
        bool flag1 = false, flag2 = false; int add = -1;
        for (int i = 0; i < 13; i++){
            if (value[i] > 0 && add < i) {add = i;}
            if (value[i] == 2) {flag1 = true;}
            if (value[i] == 3) {flag2 = true;}
        }
        if (flag1 && flag2) {return 120 + add;}
        else {return -1;}
    }

    int flush(std::string str, std::vector<int> val, std::vector<int> sts){
        for (int i = 4; i <= 13; i+=3){
            if (str[i] != str[i-3]){return -1;}
        }
        int value[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (int i = 0; i < 13; i+=3){
            for(int j = 0; j < 13; j++){
                if (chars[j] == str[i]){value[j]++; break;}
            }
        }
        int add = -1;
        for (int i = 0; i < 13; i++){
            if (value[i] > 0 && add < i) {add = i;}
        }
        return 100 + add;
    }

    int straight(std::string str, std::vector<int> val, std::vector<int> sts){
        int value[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (int i = 0; i < 13; i+=3){
            for(int j = 0; j < 13; j++){
                if (chars[j] == str[i]){value[j]++; break;}
            }
        }
        int start = -1;
        for (int i = 0; i < 13; i++){
            if (value[i] > 1) {return -1;}
            if (start < 0 && value[i] == 1){start = i;}
        }
        for (int i = 0; i < 5; i++){
            if (value[i+start] != 1){return -1;}
        }
        return 80 + start;
    }

    int three(std::string str, std::vector<int> val, std::vector<int> sts){

    }

    int twoPairs(std::string str, std::vector<int> val, std::vector<int> sts){

    }

    int onePair(std::string str, std::vector<int> val, std::vector<int> sts){

    }
}

int problem54() {
    std::fstream fs;
    fs.open("../files/problem52.txt", std::fstream::in);
    if (!fs.is_open()){
        return -1;
    }
    std::string msg;
    while (!fs.eof()){
        fs >> msg;
        std::string str1 = pr54::p1(msg);
        std::string str2 = pr54::p2(msg);
        std::vector<int> values1 = pr54::getValues(str1);
        std::vector<int> values2 = pr54::getValues(str2);
        std::vector<int> suits1 = pr54::getSuits(str1);
        std::vector<int> suits2 = pr54::getSuits(str2);

        msg = "";
    }


//    std::string msg = "8C TS KC 9H 4S 7D 2S 5D 3S AC";
//        std::string str1 = pr54::p1(msg);
//        std::string str2 = pr54::p2(msg);
//        std::vector<int> values1 = pr54::getValues(str1);
//        std::vector<int> values2 = pr54::getValues(str2);
//        std::vector<int> suits1 = pr54::getSuits(str1);
//        std::vector<int> suits2 = pr54::getSuits(str2);
//
//        std::cout << msg << std::endl;
//
//        for (int i = 0; i < 4; i++){
//            std::cout << suits1[i] << ' ';
//        }
//        std::cout << std::endl;
//        for (int i = 0; i < 4; i++){
//            std::cout << suits2[i] << ' ';
//        }
//        std::cout << std::endl;
//        for (int i = 0; i < 13; i++){
//            std::cout << values1[i] << ' ';
//        }
//    std::cout << std::endl;
//    for (int i = 0; i < 13; i++){
//        std::cout << values2[i] << ' ';
//    }
//    return -1;
}