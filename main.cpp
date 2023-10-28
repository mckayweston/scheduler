#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(){
    std::vector<int> schedules;
    std::vector<int> durations;
    std::string output;
    std::string input;
    std::string conversion;
    int time_needed;
    int hours;
    int minutes;
    int min;
    int max;
    int counter = 0;
    bool valid = false;
    bool success = false;
    std::string test;
    std::ifstream infile;
    infile.open("Input.txt");
        while(infile>>input){
            test = input [0];
            if (test == "["){
                if(input.size() == 9){
                    conversion = input[3];
                    hours = stoi(conversion);
                    conversion = input [5];
                    conversion.push_back(input[6]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    schedules.push_back(minutes);
                } else if (input.size() == 10){
                    conversion = input[3];
                    conversion.push_back(input[4]);
                    hours = stoi(conversion);
                    conversion = input [6];
                    conversion.push_back(input[7]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    schedules.push_back(minutes);
                }
                infile >> input;
                if (input.size() == 8){
                    conversion = input[1];
                    hours = stoi(conversion);
                    conversion = input[3];
                    conversion.push_back(input[4]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    durations.push_back(minutes);
                } else if (input.size() == 9){
                    conversion = input[1];
                    conversion.push_back(input[2]);
                    hours = stoi(conversion);
                    conversion = input [4];
                    conversion.push_back(input[5]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    durations.push_back(minutes);
                }
                infile >> input;
                test = input [0];
                while (test == "["){
                if(input.size() == 8){
                    conversion = input[2];
                    hours = stoi(conversion);
                    conversion = input [4];
                    conversion.push_back(input[5]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    schedules.push_back(minutes);
                } else if (input.size() == 9){
                    conversion = input[2];
                    conversion.push_back(input[3]);
                    hours = stoi(conversion);
                    conversion = input [5];
                    conversion.push_back(input[6]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    schedules.push_back(minutes);
                }
                    infile >> input;
                if (input.size() == 8){
                    conversion = input[1];
                    hours = stoi(conversion);
                    conversion = input[3];
                    conversion.push_back(input[4]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    durations.push_back(minutes);
                } else if (input.size() == 9){
                    conversion = input[1];
                    conversion.push_back(input[2]);
                    hours = stoi(conversion);
                    conversion = input [4];
                    conversion.push_back(input[5]);
                    minutes = stoi(conversion);
                    minutes = hours * 60 + minutes;
                    durations.push_back(minutes);
                }
                    infile >> input;
                    test = input [0];
                }
            } 
            if (input.size() == 16) {
                test = input[8];
                if (test == "D") {
                    test = input[6];
                    if (test == "1"){
                        infile >> input;
                        infile >> input;
                        if(input.size() == 8){
                            conversion = input[2];
                            hours = stoi(conversion);
                            conversion = input[4];
                            conversion.push_back(input[5]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                            min = minutes;
                        } else if (input.size() == 9){
                            conversion = input[2];
                            conversion.push_back(input[3]);
                            hours = stoi(conversion);
                            conversion = input [5];
                            conversion.push_back(input[6]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                            min = minutes;
                        }
                        infile >> input;
                        if(input.size() == 7){
                            conversion = input[1];
                            hours = stoi(conversion);
                            conversion = input[3];
                            conversion.push_back(input[4]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                            max = minutes;
                        } else if (input.size() == 8){
                            conversion = input[1];
                            conversion.push_back(input[2]);
                            hours = stoi(conversion);
                            conversion = input [4];
                            conversion.push_back(input[5]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                            max = minutes;
                        }
                    } else if (test == "2") {
                        infile >> input;
                        infile >> input;
                        if(input.size() == 8){
                            conversion = input[2];
                            hours = stoi(conversion);
                            conversion = input[4];
                            conversion.push_back(input[5]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                            max = minutes;
                        if (minutes < min){
                            min = minutes;
                        }
                        } else if (input.size() == 9){
                            conversion = input[1];
                            conversion.push_back(input[2]);
                            hours = stoi(conversion);
                            conversion = input [4];
                            conversion.push_back(input[5]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                        if (minutes < min){
                            min = minutes;
                        }
                        }
                        infile >> input;
                        if(input.size() == 7){
                            conversion = input[1];
                            hours = stoi(conversion);
                            conversion = input[3];
                            conversion.push_back(input[4]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                            max = minutes;
                            if (minutes > max){
                            max = minutes;
                            }
                        } else if (input.size() == 8){
                            conversion = input[1];
                            conversion.push_back(input[2]);
                            hours = stoi(conversion);
                            conversion = input [4];
                            conversion.push_back(input[5]);
                            minutes = stoi(conversion);
                            minutes = hours * 60 + minutes;
                            if (minutes > max){
                                max = minutes;
                            }
                        }
                        infile >> input;
                        infile >> input;
                        infile >> input;
                        infile >> input;
                        time_needed = stoi(input);
                        for (int i = min; i < max; i++){
                            valid = true;
                            for (int j = 0; j < schedules.size(); j++){
                                if (i >= schedules[j] && i <= durations[j]){
                                    counter = 0;
                                    valid = false;
                                } 
                            }
                            if (valid == true){
                                counter++;
                            }
                            if (counter == time_needed){
                                minutes = (i - counter) % 60;
                                hours = ((i - counter) - minutes) / 60;
                                if (success == true){
                                    output += ", ";
                                } else {
                                    output += "[";
                                }
                                if (minutes < 10){
                                    output += "['";
                                    conversion = std::to_string(hours);
                                    output += conversion;
                                    output += ":0";
                                    conversion = std::to_string(minutes);
                                    output += conversion;
                                    output += "', ";
                                } else {
                                    output += "['";
                                    conversion = std::to_string(hours);
                                    output += conversion;
                                    output += ":";
                                    conversion = std::to_string(minutes);
                                    output += conversion;
                                    output += "', ";
                                }
                                minutes = i % 60;
                                hours = (i - minutes) / 60;
                                if (minutes < 10){
                                    output += "'";
                                    conversion = std::to_string(hours);
                                    output += conversion;
                                    output += ":0";
                                    conversion = std::to_string(minutes);
                                    output += conversion;
                                    output += "']";
                                } else {
                                    output += "'";
                                    conversion = std::to_string(hours);
                                    output += conversion;
                                    output += ":";
                                    conversion = std::to_string(minutes);
                                    output += conversion;
                                    output += "']";
                                }
                                success = true;
                                counter = 0;
                            }
                        }
                        if (success == false){
                        output += "There was not enough time available.";
                        } else {
                            output += "]";
                        }
                    output += "\n";
                    success = false;
                    schedules.clear();
                    durations.clear();
                    }
                }
            }
        }
    infile.close();
    std::ofstream outfile;
    outfile.open ("Output.txt");
    outfile << output;
    outfile.close();
    return 0;
}
