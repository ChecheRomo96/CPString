#include "EmbeddedString.h"

#include <string.h>
#include <math.h>

//////////////////////////////////////////////////////
// Constructor, Destructor and Clear
	
	//////////////////////////////////////////////////
	// Constructor
		EString::String::String()
		{
			_buffer = NULL;
			_size = 0;
		}
	//
	//////////////////////////////////////////////////
	// Destructor
		EString::String::~String()
		{
			Clear();
		}
	//
	//////////////////////////////////////////////////
	// Clear

		void EString::String::Clear()
		{
			if(_buffer != NULL)
			{
				delete _buffer;
				_buffer = NULL;
				_size = 0;
			}
		}

		void EString::String::clear()
		{
			if(_buffer != NULL)
			{
				delete _buffer;
				_buffer = NULL;
				_size = 0;
			}
		}
//
//////////////////////////////////////////////////////
// Copy Constructor and Equality Operator

	////////////////////////////////////////////////////
    // String

		EString::String::String(const String& source)
		{
			_buffer = NULL;
			_size = 0;

			resize(source.Size());
			for(uint16_t i = 0; i < _size; i++)
			{
				_buffer[i] = source[i];
			}
		}

		EString::String& EString::String::operator=(const String& source)
	    {
	        if(this != &source)
	        {
	        	resize(source.Size());
				for(uint16_t i = 0; i < _size; i++)
				{
					_buffer[i] = source[i];
				}
	        }
	        return *this;
	    }
	//
    ////////////////////////////////////////////////////
    // char *

		EString::String::String(const char* source)
		{
			_buffer = NULL;
			_size = 0;

			if(source == NULL){(*this) = "";}
			else
			{
				resize(strlen(source)+1);
				for(uint16_t i = 0; i < _size; i++)
				{
					_buffer[i] = source[i];
				}
			}
		}


		EString::String::String(const char* source, uint16_t size)
		{
			_buffer = NULL;
			_size = 0;
			
			if(source == NULL){(*this) = "";}
			else
			{
				bool flag = 0;

				if(source[size-1] != '\0'){flag = 1;}

				resize(size+flag);

				for(uint16_t i = 0; i < size; i++)
				{
					_buffer[i] = source[i];
				}

				if(flag)
				{
					_buffer[size] = '\0';
				}
			}
		}
		
		EString::String& EString::String::operator=(const char* source)
	    {
	    	if(source == NULL){(*this) = "";}
			else
			{
		    	resize(strlen(source)+1);
				for(uint16_t i = 0; i < _size; i++)
				{
					_buffer[i] = source[i];
				}
			}
	        return *this;
	    }
	//
    ////////////////////////////////////////////////////
	// int

	    ////////////////////////////////////////////////////
	    // unsigned int

		    ////////////////////////////////////////////////
		    // uint8_t

				EString::String::String(const uint8_t source)
				{
			    	(*this) = String(source,10,EString::UpperCase);
				}

				EString::String::String(const uint8_t source, uint8_t base, bool LetterCase)
				{
					char StringBases[base];
					Flash::CopyBaseChars(StringBases,base,LetterCase);

					char buffer[9];
					uint8_t counter = 0;
					uint8_t x = source;
					
					while(x > 0)
					{
						buffer[counter] = StringBases[x%base];
						counter++;
						x/=base;
					}

					resize(counter+1);

					for(uint8_t i = 0; i < counter; i++)
					{
						_buffer[i] = buffer[(counter-1)-i];
					}
					_buffer[counter] = '\0';
				}

				EString::String::String(const uint8_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const uint8_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase);
			        return *this;
			    }
			//
			////////////////////////////////////////////////
		    // uint16_t

				EString::String::String(const uint16_t source)
				{
			    	(*this) = String(source,10,EString::UpperCase);
				}

				EString::String::String(const uint16_t source, uint8_t base, bool LetterCase)
				{
					char StringBases[base];
					Flash::CopyBaseChars(StringBases,base,LetterCase);

					char buffer[17];
					uint8_t counter = 0;
					uint16_t x = source;
					
					while(x > 0)
					{
						buffer[counter] = StringBases[x%base];
						counter++;
						x/=base;
					}

					resize(counter+1);

					for(uint8_t i = 0; i < counter; i++)
					{
						_buffer[i] = buffer[(counter-1)-i];
					}
					_buffer[counter] = '\0';
				}

				EString::String::String(const uint16_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const uint16_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase);
			        return *this;
			    }
			//
			////////////////////////////////////////////////
		    // uint32_t

				EString::String::String(const uint32_t source)
				{
			    	(*this) = String(source,10,EString::UpperCase);
				}

				EString::String::String(const uint32_t source, uint8_t base, bool LetterCase)
				{
					char StringBases[base];
					Flash::CopyBaseChars(StringBases,base,LetterCase);

					char buffer[33];
					uint8_t counter = 0;
					uint32_t x = source;
					
					while(x > 0)
					{
						buffer[counter] = StringBases[x%base];
						counter++;
						x/=base;
					}

					resize(counter+1);

					for(uint8_t i = 0; i < counter; i++)
					{
						_buffer[i] = buffer[(counter-1)-i];
					}
					_buffer[counter] = '\0';
				}

				EString::String::String(const uint32_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const uint32_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase);
			        return *this;
			    }
			//
			////////////////////////////////////////////////
		    // uint64_t

				EString::String::String(const uint64_t source)
				{
			    	(*this) = String(source,10,EString::UpperCase);
				}

				EString::String::String(const uint64_t source, uint8_t base, bool LetterCase)
				{
					char StringBases[base];
					Flash::CopyBaseChars(StringBases,base,LetterCase);

					char buffer[65];
					uint8_t counter = 0;
					uint64_t x = source;
					
					while(x > 0)
					{
						buffer[counter] = StringBases[x%base];
						counter++;
						x/=base;
					}

					resize(counter+1);

					for(uint8_t i = 0; i < counter; i++)
					{
						_buffer[i] = buffer[(counter-1)-i];
					}
					_buffer[counter] = '\0';
				}

				EString::String::String(const uint64_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const uint64_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase);
					return *this;
			    }
		//
	    ////////////////////////////////////////////////////
	    // signed int

		    ////////////////////////////////////////////////
		    // int8_t

				EString::String::String(const int8_t source)
				{
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
				}

				EString::String::String(const int8_t source, uint8_t base, bool LetterCase, bool absolute)
				{
					if(absolute == EString::IntAbsolute)
					{
						(*this)=String((uint8_t)source,base,LetterCase);
					}
					else
					{
						char StringBases[base];
						Flash::CopyBaseChars(StringBases,base,LetterCase);

						char buffer[base];
						uint8_t counter = 0;
						int8_t x = source;
						bool flag = 0;
					
						if(x<0)
						{
							if(source == INT8_MIN)
							{
								(*this) = "-128";
								return;
							}
							flag = 1;
							x*=-1;
						}

						while(x > 0)
						{
							buffer[counter] = StringBases[x%base];
							counter++;
							x/=base;
						}

						resize(counter+flag+1);

						if(flag){_buffer[0] = '-';}

						for(uint8_t i = 0; i < counter; i++)
						{
							_buffer[i+flag] = buffer[(counter-1)-i];
						}
						_buffer[counter+flag] = '\0';
					}
				}

				EString::String::String(const int8_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const int8_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
					return *this;
			    }
			//
			////////////////////////////////////////////////
		    // int16_t

				EString::String::String(const int16_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
			    }

				EString::String::String(const int16_t source, uint8_t base, bool LetterCase, bool absolute)
				{

					if(absolute == EString::IntAbsolute)
					{
						(*this)=String((uint16_t)source,base,LetterCase);
					}
					else
					{
						char StringBases[base];
						Flash::CopyBaseChars(StringBases,base,LetterCase);

						char buffer[base];
						uint8_t counter = 0;
						int16_t x = source;
						bool flag = 0;
					
						if(x<0)
						{
							if(source == INT16_MIN)
							{
								(*this) = "-32768";
								return;
							}
							flag = 1;
							x*=-1;
						}

						while(x > 0)
						{
							buffer[counter] = StringBases[x%base];
							counter++;
							x/=base;
						}

						resize(counter+flag+1);

						if(flag){_buffer[0] = '-';}

						for(uint8_t i = 0; i < counter; i++)
						{
							_buffer[i+flag] = buffer[(counter-1)-i];
						}
						_buffer[counter+flag] = '\0';
					}
				}

				EString::String::String(const int16_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const int16_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
					return *this;
			    }
			//
			////////////////////////////////////////////////
		    // int32_t

				EString::String::String(const int32_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
			    }

				EString::String::String(const int32_t source, uint8_t base, bool LetterCase, bool absolute)
				{

					if(absolute == EString::IntAbsolute)
					{
						(*this)=String((uint32_t)source,base,LetterCase);
					}
					else
					{
						char StringBases[base];
						Flash::CopyBaseChars(StringBases,base,LetterCase);

						char buffer[base];
						uint8_t counter = 0;
						int32_t x = source;
						bool flag = 0;
					
						if(x<0)
						{
							if(source == INT32_MIN)
							{
								(*this) = "-2147483648";
								return;
							}
							flag = 1;
							x*=-1;
						}

						while(x > 0)
						{
							buffer[counter] = StringBases[x%base];
							counter++;
							x/=base;
						}

						resize(counter+flag+1);

						if(flag){_buffer[0] = '-';}

						for(uint8_t i = 0; i < counter; i++)
						{
							_buffer[i+flag] = buffer[(counter-1)-i];
						}
						_buffer[counter+flag] = '\0';
					}
				}

				EString::String::String(const int32_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const int32_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
					return *this;
			    }
			//
			////////////////////////////////////////////////
		    // int64_t

				EString::String::String(const int64_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
			    }

				EString::String::String(const int64_t source, uint8_t base, bool LetterCase, bool absolute)
				{
					if(absolute == EString::IntAbsolute)
					{
						(*this)=String((uint64_t)source,base,LetterCase);
					}
					else
					{
						char StringBases[base];
						Flash::CopyBaseChars(StringBases,base,LetterCase);

						char buffer[21];
						uint8_t counter = 0;
						int64_t x = source;
						bool flag = 0;
					
						if(x<0)
						{
							if(source == INT64_MIN)
							{
								(*this) = "-9223372036854775808";
								return;
							}
							flag = 1;
							x*=-1;
						}

						while(x > 0)
						{
							buffer[counter] = StringBases[x%base];
							counter++;
							x/=base;
						}

						resize(counter+flag+1);

						if(flag){_buffer[0] = '-';}

						for(uint8_t i = 0; i < counter; i++)
						{
							_buffer[i+flag] = buffer[(counter-1)-i];
						}
						_buffer[counter+flag] = '\0';
					}
				}

				EString::String::String(const int64_t source, const char* format, uint16_t size)
				{
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EString::String& EString::String::operator=(const int64_t source)
			    {
			    	(*this) = String(source,10,EString::UpperCase,EString::IntSigned);
					return *this;
			    }
	//
	////////////////////////////////////////////////////
    // float

		EString::String::String(const float source)
		{

			#if defined(PSOC_CREATOR)
		    
		        uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		        
		        uint8_t len = left_size+5;
		        char buff[len];
		        
		        resize(sprintf(buff,"%f",source));
		        
		        for(uint16_t i = 0; i < _size; i++)
		        {
		        	_buffer[i] = buff[i];
		        }

		    #elif defined (ARDUINO)

		      	uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		      
			    // +2 for '\n' and '.' , +3 for precision 
			    int len = left_size+5; 
			    char buff[len];

		      	dtostrf(source,left_size,3,buff);

		      	buff[len-1] = '\0';
				
				resize(len);
				
				for(uint8_t i = 0; i < _size; i++)
				{
					_buffer[i] = buff[i];
				}
		    
		    #endif
		}

		EString::String::String(const float source, uint8_t precision)
		{

			#if defined(PSOC_CREATOR)
		    
		        uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		        
		        uint8_t len = left_size+precision+2;
		        char buff[len];
		        char _format[10];
		        
		        _format[0] = '%';  _format[1] = ' ';
		        
		        String *str = NULL;
		        str = new String(left_size);
		        
		        int offset = 2;
		        
		        for(uint8_t i = 0; i < str->length(); i++)
		        {
		            _format[offset+i] = str->CharAt(i);
		        }
		        
		        offset += str->length();
		        _format[offset++] = '.';
		        
		        delete str;
		        str = new String(precision);
		        
		        for(uint8_t i = 0; i < str->length(); i++)
		        {
		            _format[offset+i] = str->CharAt(i);
		        }
		        
		        offset += str->length();
		        _format[offset++] = 'f';
		        _format[offset++] = '\0';
		        
		        resize(sprintf(buff,_format,source));
				
				for(uint8_t i = 0; i < _size; i++)
				{
					_buffer[i] = buff[i];
				}		        
		    
		    #elif defined (ARDUINO)

		        uint8_t left_size  = log10(source);
		        if(source<0){left_size++;}
		      
		        // +2 for '\n' and '.'
		        int len = left_size+precision+3; 
		    	char buff[len];
		      
		      	dtostrf(source,left_size,precision,buff);
		      	
		      	buff[len-1] = '\0';
				
				resize(len);
				
				for(uint8_t i = 0; i < _size; i++)
				{
					_buffer[i] = buff[i];
				}

		    #endif
		}

		EString::String& EString::String::operator=(const float source)
		{
			(*this) = String(source,3);

			return (*this);
		}
	//
	////////////////////////////////////////////////////
    // double

		EString::String::String(const double source)
		{

			#if defined(PSOC_CREATOR)
		    
		        uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		        
		        uint8_t len = left_size+5;
		        char buff[len];
		        
		        resize(sprintf(buff,"%d",source));
		        
		        for(uint16_t i = 0; i < _size; i++)
		        {
		        	_buffer[i] = buff[i];
		        }
		      
		    #elif defined (ARDUINO)

		      	uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		      
			    // +2 for '\n' and '.' , +3 for precision 
			    int len = left_size+5; 
			    char buff[len];

		      	(*this) = dtostrf(source,left_size,3,buff);
		    
		    #endif
		}

		EString::String::String(const double source, uint8_t precision)
		{

			#if defined(PSOC_CREATOR)
		    
		        uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		        
		        uint8_t len = left_size+precision+2;
		        char buff[len];
		        char _format[10];
		        
		        _format[0] = '%';  _format[1] = ' ';
		        
		        String *str = NULL;
		        str = new String(left_size);
		        
		        int offset = 2;
		        
		        for(uint8_t i = 0; i < str->length(); i++)
		        {
		            _format[offset+i] = str->CharAt(i);
		        }
		        
		        offset += str->length();
		        _format[offset++] = '.';
		        
		        delete str;
		        str = new String(precision);
		        
		        for(uint8_t i = 0; i < str->length(); i++)
		        {
		            _format[offset+i] = str->CharAt(i);
		        }
		        
		        offset += str->length();
		        _format[offset++] = 'd';
		        _format[offset++] = '\0';
		        
		        resize(sprintf(buff,"%d",source));
		        
		        for(uint16_t i = 0; i < _size; i++)
		        {
		        	_buffer[i] = buff[i];
		        }
		    
		    #elif defined (ARDUINO)

		        uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		      
		        // +2 for '\n' and '.'
		        int len = left_size+precision+2; 
		    	char buff[len];
		      
		      	(*this) = dtostrf(source,left_size,precision,buff);	

		    #endif
		}

		EString::String& EString::String::operator=(const double source)
		{
			(*this) = String(source);
			return (*this);
		}
	//
    ////////////////////////////////////////////////////
    // String
		#if defined(ARDUINO)

			EString::String::String(const ::String& source)
			{
				_buffer = NULL;
				_size = 0;

				resize(source.length()+1);
				for(uint16_t i = 0; i < _size; i++)
				{
					_buffer[i] = source[i];
				}
			}
			
			EString::String& EString::String::operator=(const ::String& source)
		    {
		    	resize(source.length()+1);
				for(uint16_t i = 0; i < _size; i++)
				{
					_buffer[i] = source[i];
				}
		        return *this;
		    }
		#endif
//
//////////////////////////////////////////////////////
// Operators

    ////////////////////////////////////////////////////
    // Cast Operators
		
		EString::String::operator char*() const{return _buffer;}
	//
    ////////////////////////////////////////////////////
    // Equality and Inequality Operators
		
		bool EString::String::operator==(const String& rhs) const
		{
			if(strcmp(_buffer,rhs)==0){return 1;}
			else{return 0;}
		}

		bool EString::String::operator!=(const String& rhs) const
		{
			if(strcmp(_buffer,rhs)==0){return 0;}
			else{return 1;}
		}
	//
    ////////////////////////////////////////////////////
    // Addition Operators

		/////////////////////////////////////////////////////////
		// String

			EString::String& EString::String::operator+=(const EString::String& rhs)
			{
				uint16_t a = _size-1;
				resize(_size + rhs.Size()-1);
				memcpy(_buffer+a,rhs,rhs.Size());
				return (*this);
			}

			EString::String EString::String::operator+(const EString::String& rhs) const
			{
				//tmp += rhs;
				return String(*this) += rhs;
			}
		//
		/////////////////////////////////////////////////////////
		// Char *

			EString::String& EString::String::operator+=(const char* rhs)
			{
				uint16_t a = _size-1;
				String tmp(rhs);
				resize(_size + tmp.Size()-1);
				memcpy(_buffer+a,tmp,tmp.Size());
				return (*this);
			}

			EString::String EString::String::operator+(const char* rhs) const
			{
				//tmp += rhs;
				return String(*this) += rhs;
			}
		//
		/////////////////////////////////////////////////////////
		// 	int

			/////////////////////////////////////////////////////
			// unsigned int

				/////////////////////////////////////////////////
				// uint8_t

					EString::String& EString::String::operator+=(const uint8_t rhs)
					{
						uint16_t a = _size-1;

						EString::String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const uint8_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EString::String& EString::String::operator+=(const uint16_t rhs)
					{
						uint16_t a = _size-1;

						String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const uint16_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EString::String& EString::String::operator+=(const uint32_t rhs)
					{
						uint16_t a = _size-1;

						String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const uint32_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint64_t

					EString::String& EString::String::operator+=(const uint64_t rhs)
					{
						uint16_t a = _size-1;

						String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const uint64_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
			//
			/////////////////////////////////////////////////////
			// signed int

				/////////////////////////////////////////////////
				// int8_t

					EString::String& EString::String::operator+=(const int8_t rhs)
					{
						uint16_t a = _size-1;

						String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const int8_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EString::String& EString::String::operator+=(const int16_t rhs)
					{
						uint16_t a = _size-1;

						String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const int16_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EString::String& EString::String::operator+=(const int32_t rhs)
					{
						uint16_t a = _size-1;

						String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const int32_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint16_t6_t

					EString::String& EString::String::operator+=(const int64_t rhs)
					{
						uint16_t a = _size-1;

						String tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EString::String EString::String::operator+(const int64_t rhs) const
					{
						//tmp += rhs;
						return String(*this) += rhs;
					}
//
//////////////////////////////////////////////////////
// Getters

	uint16_t EString::String::Size() const{return _size;}
	uint16_t EString::String::size() const{return _size;}

	// String Cross Compatible Methods
	uint16_t EString::String::length() const{return _size-1;}
	char* EString::String::c_str() const{return _buffer;}


	char EString::String::CharAt(uint16_t n) const
	{
		if(n < _size)
		{
			return _buffer[n];
		}
        return '\n';
	}
//
//////////////////////////////////////////////////////
// Private Methods

	void EString::String::resize(uint16_t size, char c)
	{
		if(size==_size){return;}

		char tmp[size];
        uint16_t minimum = _size;
        
        if(size>_size){minimum = size;}

		for(uint16_t i = 0; i < minimum; i++)
		{
			tmp[i] = _buffer[i];
		}

		if(size > _size)
		{
			for(uint16_t i = _size; i < size; i++)
			{
				tmp[i] = c;
			}
		}
        
        Clear();
        _buffer = new char[size];

		for(uint16_t i = 0; i < minimum; i++)
		{
			_buffer[i] = tmp[i];
		}
        
        _size=size;
	}
