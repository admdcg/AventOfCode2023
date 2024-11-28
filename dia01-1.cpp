#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

int main() {
    //54697	
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
	    for (auto character : cadena)
        {            
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