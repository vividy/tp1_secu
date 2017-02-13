#include <iostream>
#include <fstream>

class	getNextLine : public std::fstream{
	private:
		std::string		_str;
		std::string		_fileName;
	public:
		inline getNextLine(std::string fileName) :_fileName(fileName) {
			std::cout << "file \"" << _fileName << "\" is open!";
		}

		inline virtual ~getNextLine(){
			std::cout << "file \"" << _fileName << "\" is close";
		}

		inline std::string next(){
			std::string str;

			std::getline(fs, str);
			return (str);
		}
};
