#ifndef VARIABLE_H
#define VARIABLE_H

#include <vector>

class Variable {

	private :
		std::vector <int>         intValue        ;
		std::vector <float>       floatValue      ;
		std::vector <char>        charValue       ;
		std::vector <std::string> stringValue     ;
		std::vector <std::string> intValueName    ;
		std::vector <std::string> floatValueName  ;
		std::vector <std::string> charValueName   ;
		std::vector <std::string> stringValueName ;
	public :

		//constructor
		Variable () {}

		//get methods
		int         getIntValue    (std::string ) ;
		float       getFloatValue  (std::string ) ;
		char        getCharValue   (std::string ) ;
		std::string getStringValue (std::string ) ;
		
		//set methods
		bool        setIntValue    (std::string , int         ) ;
		bool        setFloatValue  (std::string , float       ) ;
		bool        setCharValue   (std::string , char        ) ;
		bool        setStringValue (std::string , std::string ) ;
		
		//tool methods
		bool        addIntValue    (std::string , int         ) ;
		bool        addFloatValue  (std::string , float       ) ;
		bool        addCharValue   (std::string , char        ) ;
		bool        addStringValue (std::string , std::string ) ;
		bool        isMultiDef     (std::string               ) ;
		std::string getType        (std::string               ) ;
		
};

#endif