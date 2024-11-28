#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // Para std::sort

std::string TransformLetters2Digits(const std::string& cadena);
std::string TransformLetters2Digits2(const std::string& cadena);
std::string replace(const std::string& original, const std::string& buscar, const std::string& reemplazar);
void SortVector(std::vector<int>& vec);

int main() {
    //54885
	std::string cadena;
	std::ifstream inFile;    
    long suma(0);

	inFile.open("dia01.txt");
	if (!inFile) {
		std::cout << "Unable to open file";
		return EXIT_FAILURE;  // terminate with error
	}    
    
	while(std::getline(inFile, cadena))
	{	    
        char digitFirst = 0;
        char digitLast = 0;         
        std::string newString(TransformLetters2Digits(cadena));
	    for (int i = 0; i<newString.size(); i++)
        {            
            char character = newString[i];            
            if (character >=48 && character <= 57) 
            {                  
                if (digitFirst == 0)
                {
                    digitFirst = character;
                }
                digitLast = character;
            }            
        }
        std::string twoDigits;
        twoDigits = digitFirst == 0 ? '0' : digitFirst;
        twoDigits = twoDigits + (digitLast == 0 ? '0' : digitLast);
        int num = std::stoi(twoDigits);
        suma += num;
    }   
	inFile.close();
	std::cout << "Sum = " << suma << std::endl;	
    return EXIT_SUCCESS;
}   
std::string TransformLetters2Digits(const std::string& cadena)
{
    std::string newString(cadena);    
    std::vector<std::string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};    
    
    for (int i = 0; i<newString.size(); i++)
    {   
        for (int w=0; w<words.size(); w++)
        {
            std::string word = words[w];
            if (newString.substr(i, word.size()) == word)
            {
                newString.replace(i, word.size()-1, std::to_string(w));
                break;
            }
        }        
    }
    return newString;
}
std::string TransformLetters2Digits2(const std::string& cadena)
{
    std::string newString("");    
    std::vector<std::string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};    
    
    for (int i = 0; i<cadena.size(); i++)
    {   
        std::string letter(&cadena[i], 1);
        for (int w=0; w<words.size(); w++)
        {
            std::string word = words[w];
            if (cadena.substr(i, word.size()) == word)
            {                
                letter = std::to_string(w);                
                break;
            }            
        } 
        newString += letter;       
    }
    return newString;
}
