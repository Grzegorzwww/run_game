#include "resultloger.h"

ResultLoger::ResultLoger(std::string filename = "results.txt")
{
    file_name = filename;
    result_data.insert(result_data.end(), std::pair<std::string, int>("empty", 0));
    readData();



}


void ResultLoger::openFile(){
    fout.open(file_name , std::ios_base::in | std::ios_base::out  );
}
std::map <std::string , int > & ResultLoger::showScore() {
     readData();
    return result_data;
}


void ResultLoger::addScore(std::string str, int score){
    result_data.insert(result_data.end(), std::pair<std::string, int>(str, score));
    saveData();
}

void ResultLoger::readData(void){
    if(file_exists(file_name)){
        std::string readed_string;
        fout.open(file_name,   std::ios_base::in);
        while(std::getline (fout,readed_string)){
            std::stringstream temp(readed_string);
            std::vector<std::string > result;
            while(temp)
            {
                std::string substr;
                std::getline( temp, substr, '|' );
                result.push_back( substr);
            }
            if(result.size()> 1){
                result_data.insert(result_data.end(), std::pair<std::string, int>(result.at(0), std::atoi(result.at(1).c_str())));
                result.clear();
            }else{
                std::cerr <<"file format error"<<std::endl;
            }
        }
        for(std::map <std::string , int > ::iterator it = result_data.begin(); it != result_data.end(); it++ ) {
            std::cout << it->first<<", score  = "<<it->second<<std::endl;
        }
        fout.close();
    }
    else {
        std::cout << "plik istnieje"<<std::endl;
    }
}

void ResultLoger::saveData(){
    fout.open(file_name,    std::ios_base::ate | std::ios_base::out);
    if(fout.is_open()){
        for(std::map <std::string , int > ::iterator it = result_data.begin(); it != result_data.end(); it++ ) {
            fout << it->first<<"   |   "<<it->second<<std::endl;
        }
    }
    fout.close();
}

bool ResultLoger::file_exists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

