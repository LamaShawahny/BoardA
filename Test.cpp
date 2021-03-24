#include "doctest.h"
#include <string>
#include <experimental/random>
#include <unistd.h>
#include <algorithm>
using namespace doctest;
using namespace std;

#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;
const int RANDOM_BOUNDERY=100, WORD1=1,WORD2=2,WORD3=3, WORD4=4 ,WORD5=5,WORD6=6,WORD7=7,WORD8=8,WORD9=9,WORD10=10,WORD11=11,WORD12=12;

TEST_CASE("assertion a word from 4 latters ") {
    Board Board;
    string word = "Lama";
    Board.post(0, 0, Direction::Horizontal, word);
    CHECK(Board.read(0, 0, Direction::Horizontal, WORD4) == word);
}
TEST_CASE("assertion a word from 4 latters ") {
    Board Board;
    string word= "Sama";
    Board.post(0, 0, Direction::Horizontal, word);
    CHECK(Board.read(0, 0, Direction::Horizontal, WORD4) == word);
}

TEST_CASE("assertion a word from 6 latters ") {
    Board Board;
    string word= "Bassam";
    Board.post(2, 0, Direction::Horizontal, word);
    string neWord= "_"+word.substr(0,1)+"_";

    CHECK(Board.read(0, 0, Direction::Vertical, WORD6) == neWord);
}
TEST_CASE("assertion a word from 6 latters ") {
    Board Board;
    string word= "lalaaa";
    Board.post(2, 0, Direction::Horizontal, word);
    string neWord= "_"+word.substr(0,1)+"_";

    CHECK(Board.read(0, 0, Direction::Vertical, WORD6) == neWord);
}

TEST_CASE("assertion a word from 8 latters "){
    Board Board;
    string word= "Shawahny";
    Board.post(0,2,Direction::Vertical,word);
    string neWord= "_"+word.substr(0,1)+"_";
    CHECK(Board.read(0,0,Direction::Horizontal,WORD8)==neWord);
}

TEST_CASE("assertion a word from 5 latters "){
    Board Board;
    string word= "david";
    Board.post(0,2,Direction::Vertical,word);
    string neWord= "_"+word.substr(0,1)+"_";
    CHECK(Board.read(0,0,Direction::Horizontal,WORD5)==neWord);
}

TEST_CASE("assertion a word from 4 latters "){
    Board Board;
    string word= "saimon";
    Board.post(0,2,Direction::Vertical,word);
    string neWord= "_"+word.substr(0,1)+"_";
    CHECK(Board.read(0,0,Direction::Horizontal,WORD6)==neWord);
}

TEST_CASE("assertion a word from 4 latters "){
    Board Board;
    string word= "sami";
    Board.post(0,2,Direction::Vertical,word);
    string neWord= "_"+word.substr(0,1)+"_";
    CHECK(Board.read(0,0,Direction::Horizontal,WORD4)==neWord);
}

TEST_CASE("assertion a word from 5 latters "){
    Board Board;
    unsigned int row = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
    unsigned int col = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
    CHECK(Board.read(row,col,Direction::Horizontal,WORD5)==string("___"));
    CHECK(Board.read(row,col,Direction::Vertical,WORD5)==string("___"));
}

TEST_CASE("assertion a word from 5 latters verticaly"){
    Board Board;
    string word="Board";
    Board.post(0,0,Direction::Vertical,word);
    CHECK(Board.read(0,0,Direction::Vertical,WORD5)==word);
    }
TEST_CASE("assertion horizontayl"){
    Board Board;
    string word= "hithere";
    Board.post(0,0,Direction::Horizontal,word);
    word= "hithere";
    Board.post(0,0,Direction::Horizontal,word);
    CHECK(Board.read(0,0,Direction::Horizontal,WORD7)==word);
    }
TEST_CASE("assertion verticaly"){
    Board Board;
    string word= "lamosh";
    Board.post(0,0,Direction::Vertical,word);
    word= "lamosh";
    Board.post(0,0,Direction::Vertical,word);
    CHECK(Board.read(0,0,Direction::Vertical,WORD6)==word);
    }
TEST_CASE("assertion verticaly"){
    Board Board;
    string word= "sh";
    Board.post(0,0,Direction::Vertical,word);
    word= "la ";
    Board.post(0,0,Direction::Vertical,word);
    CHECK(Board.read(0,0,Direction::Vertical,WORD2)==word);
    }
TEST_CASE("assertion horizontaly"){
    Board Board;
        string word= "saleem";
        Board.post(0,0,Direction::Horizontal,word);
        Board.post(0,0,Direction::Horizontal,word);
        CHECK(Board.read(0,0,Direction::Horizontal,WORD6)==word);
    }
TEST_CASE("assertion horizontaly"){
    Board Board;
        string word= "lama";
        Board.post(0,0,Direction::Horizontal,word);
        string str2 = "lama";
        Board.post(0,0,Direction::Horizontal,str2);
        word.replace(0,str2.length(),str2);
        CHECK(Board.read(0,0,Direction::Horizontal,WORD4)==word);
    }
TEST_CASE("assertion verticaly"){
    Board Board;
        string word= "koko";
        Board.post(0,0,Direction::Vertical,word);
        string str2 = "koko";
        Board.post(0,0,Direction::Vertical,str2);
        word.replace(0,str2.length(),str2);
        CHECK(Board.read(0,0,Direction::Vertical,WORD4)==word);
    }
TEST_CASE("insert 2 words with different length and columns"){
    Board Board;
        string FirstWord= "malik";
        string SecWord= "malikkkk";
        Board.post(1,0,Direction::Horizontal,FirstWord);
        Board.post(0,0,Direction::Horizontal,SecWord);
        
        CHECK(Board.read(1,0,Direction::Horizontal,12)==FirstWord);
        CHECK(Board.read(0,0,Direction::Horizontal,12)==SecWord+"___");
    }
TEST_CASE("insert 2 words with different length and columns"){
    Board Board;
        string FirstWord= "lamabasaam";
        string SecWord= "lamabasaamshawahny";
          Board.post(0,1,Direction::Vertical,FirstWord);
        Board.post(0,0,Direction::Vertical,SecWord);
      
        CHECK(Board.read(0,0,Direction::Vertical,12)==SecWord+"___");
        CHECK(Board.read(0,1,Direction::Vertical,12)==FirstWord);
    }
TEST_CASE("insert 2 words with different length and columns"){
    Board Board;
        string FirstWord= "ameer";
        string SecWord= "aviveee";
         Board.post(0,1,Direction::Vertical,FirstWord);
        Board.post(0,0,Direction::Vertical,SecWord);
       
        CHECK(Board.read(0,0,Direction::Vertical,12)==SecWord+"___");
        CHECK(Board.read(0,1,Direction::Vertical,12)==FirstWord);
    }    
