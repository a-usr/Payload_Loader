#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <vector>
#include <string>
void FindAndReplaceVectorByMarker(std::vector<unsigned char> &vector, std::string replace, bool insert = false ,const char marker[] = "Z_MaRKER"){
    int markersize = sizeof(&marker);
    int replsize = sizeof(replace);
    bool is = false;
    int i = 0;
    int count = 0;
    int countf = 0;
    for(unsigned char& c : vector){
        if(i == 0){
            if(c == marker[0]){
                countf = count;
                i++;
            }
        }
        else{
            if(i < markersize - 1){
                if(c == marker[i]){
                    i++;
                }
                else{
                    countf = 0;
                    i = 0;
                }

            }
            else{
                break;
            }
        }
        count++;
    }
    i = 0;
    count = 0;
    for(unsigned char &c : vector){
        if(count >= countf){
            if(i < markersize - 1){
                c = replace[i];
                i++;
            }
            else{
                if(insert){
                    if(i < replsize){
                        c = replace[i];
                        i++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        count++;
    }
}
int getsizeofVector(std::vector<unsigned char> v){
    int size = 0;
    for(unsigned char c : v){
        size++;
    }
    return size;
}
std::vector<unsigned char> Vector_of_VectorDefinition(std::vector<unsigned char> v){
    std::vector<unsigned char> vec;
    int lenght = sizeof(v);
    int i = 1;
    for(unsigned char c : v){
        vec.push_back('\'');
        if(c=='\\'){
            vec.push_back('\\');
        }
        else if(c=='\0'){
            vec.push_back('\0');
        }
        else{
            vec.push_back(c);
        }
        vec.push_back('\'');
        if(i<lenght){
            vec.push_back(',');
            vec.push_back(' ');
        }
    }
    return vec;
}
void FindAndReplaceVectorWithVectorByMarker(std::vector<unsigned char>& vector, std::vector<unsigned char> replace, bool insert = false, const char marker[] = "Z_MaRKER") {
    int markersize = sizeof(&marker);
    int replsize = sizeof(replace);
    bool is = false;
    int i = 0;
    int count = 0;
    int countf = 0;
    for (unsigned char& c : vector) {
        if (i == 0) {
            if (c == marker[0]) {
                countf = count;
                i++;
            }
        }
        else {
            if (i < markersize - 1) {
                if (c == marker[i]) {
                    i++;
                }
                else {
                    countf = 0;
                    i = 0;
                }

            }
            else {
                break;
            }
        }
        count++;
    }
    i = 0;
    count = 0;
    for (unsigned char& c : vector) {
        if (count >= countf) {
            if (i < markersize - 1) {
                c = replace[i];
                i++;
            }
            else {
                if (insert) {
                    if (i < replsize) {
                        c = replace[i];
                        i++;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        count++;
    }
}
#endif
