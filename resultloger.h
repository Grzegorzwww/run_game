#ifndef RESULTLOGER_H
#define RESULTLOGER_H
#include "iostream"
#include "fstream"
#include "map"
#include <algorithm>
#include "defines.hpp"


class ResultLoger
{
public:
    ResultLoger(std::string filename);


    void openFile();
    void addScore(std::string str, int score);
    std::map <std::string , int > & showScore();


private:

      enum {MAX_RESULTS = 6};
      FILE* fp;

      std::map <std::string , int > result_data;
      std::string file_name;
      std::fstream fout;
      std::streampos pos;
       bool file_exist;

      void readData(void);
      void saveData();
      bool file_exists(const std::string& name);





};


#endif // RESULTLOGER_H
