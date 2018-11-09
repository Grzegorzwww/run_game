#include "resultloger.h"

ResultLoger::ResultLoger(std::string filename = "results")
{
    file_name = filename;
    //result_data.insert(result_data.end(), std::pair<std::string, int>(0, "empty"));
    readData();



}


void ResultLoger::openFile(){
    fout.open(file_name , std::ios_base::in | std::ios_base::out  );
}
results_data_t & ResultLoger::showScore() {
    readData();
    return result_data;
}


void ResultLoger::addScore(std::string str, int score){
    result_data.insert(result_data.end(), std::pair<int, std::string>(score, str));

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
                result_data.insert(result_data.end(), std::pair<int, std::string >(std::atoi(result.at(1).c_str()), result.at(0) ));
                result.clear();
            }else{
                std::cerr <<"file format error"<<std::endl;
            }
        }
//        for(std::map <int, std::string > ::iterator it = result_data.begin(); it != result_data.end(); it++ ) {
//            std::cout << it->second<<", score  = "<<it->first<<std::endl;
//        }
        fout.close();
    }
    else {
        std::cout << "plik istnieje"<<std::endl;
    }
}

void ResultLoger::saveData(){
    fout.open(file_name,    /*std::ios_base::ate | */std::ios_base::out);
    fout.setf(std::ios_base::left , std::ios_base::adjustfield) ;
    if(fout.is_open()){
        for(std::map<int, std::string>::iterator it = result_data.begin(); it != result_data.end(); it++ ) {
           fout.width(25);
           fout << it->second;
           fout.width(3);
           fout<<" | ";
           fout.width(10);
           fout<<it->first<<" metrow"<<std::endl;
        }
    }
    fout.close();
}

bool ResultLoger::file_exists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

