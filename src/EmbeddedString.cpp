#include "EmbeddedString.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

bool EmbeddedString::LetterCase::Mode = EmbeddedString::LetterCase::Upper;
bool EmbeddedString::IntFormat::Mode = EmbeddedString::IntFormat::Mode;

//////////////////////////////////////////////////////
// Global Methods

	void EmbeddedString::SetLetterCase(bool Mode)
	{
		EmbeddedString::LetterCase::Mode = Mode;
	}

	void EmbeddedString::SetLetterCase_Upper()
	{
		EmbeddedString::LetterCase::Mode = EmbeddedString::LetterCase::Upper;
	}

	void EmbeddedString::SetLetterCase_Lower()
	{
		EmbeddedString::LetterCase::Mode = EmbeddedString::LetterCase::Lower;
	}

	void EmbeddedString::SetIntFormat(bool Mode)
	{
		EmbeddedString::IntFormat::Mode = Mode;
	}

	void EmbeddedString::SetIntFormat_Signed()
	{
		EmbeddedString::IntFormat::Mode = EmbeddedString::IntFormat::Signed;
	}

	void EmbeddedString::SetIntFormat_Absolute()
	{
		EmbeddedString::IntFormat::Mode = EmbeddedString::IntFormat::Absolute;
	}
//
//////////////////////////////////////////////////////
// Constructor, Destructor and Clear
	
	//////////////////////////////////////////////////
	// Constructor
		EmbeddedString::string::string()
		{
			_buffer = NULL;
			_size = 0;
		}
	//
	//////////////////////////////////////////////////
	// Destructor
		EmbeddedString::string::~string()
		{
			Clear();
		}
	//
	//////////////////////////////////////////////////
	// Clear

		void EmbeddedString::string::Clear()
		{
			if(_buffer != NULL)
			{
				delete _buffer;
				_buffer = NULL;
				_size = 0;
			}
		}

		void EmbeddedString::string::clear()
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
    // string

		EmbeddedString::string::string(const string& source)
		{
			_buffer = NULL;
			_size = 0;

			resize(source.Size());
			for(uint16_t i = 0; i < _size; i++)
			{
				_buffer[i] = source[i];
			}
		}

		EmbeddedString::string& EmbeddedString::string::operator=(const string& source)
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

		EmbeddedString::string::string(const char* source)
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


		EmbeddedString::string::string(const char* source, uint16_t size)
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
		
		EmbeddedString::string& EmbeddedString::string::operator=(const char* source)
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

				EmbeddedString::string::string(const uint8_t source)
				{
					_buffer = NULL;
					_size = 0;

			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
				}

				EmbeddedString::string::string(const uint8_t source, uint8_t base, bool LetterCase)
				{
                    _buffer = NULL;
                    _size = 0;
                    
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

				EmbeddedString::string::string(const uint8_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;

					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const uint8_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
			        return *this;
			    }
			//
			////////////////////////////////////////////////
		    // uint16_t

				EmbeddedString::string::string(const uint16_t source)
				{
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
				}

				EmbeddedString::string::string(const uint16_t source, uint8_t base, bool LetterCase)
				{
					_buffer = NULL;
					_size = 0;

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

				EmbeddedString::string::string(const uint16_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;

					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const uint16_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
			        return *this;
			    }
			//
			////////////////////////////////////////////////
		    // uint32_t

				EmbeddedString::string::string(const uint32_t source)
				{
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
				}

				EmbeddedString::string::string(const uint32_t source, uint8_t base, bool LetterCase)
				{
					_buffer = NULL;
					_size = 0;

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

				EmbeddedString::string::string(const uint32_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;
					
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const uint32_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
			        return *this;
			    }
			//
			////////////////////////////////////////////////
		    // uint64_t

				EmbeddedString::string::string(const uint64_t source)
				{
					_buffer = NULL;
					_size = 0;
					
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
				}

				EmbeddedString::string::string(const uint64_t source, uint8_t base, bool LetterCase)
				{
					_buffer = NULL;
					_size = 0;
					
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

				EmbeddedString::string::string(const uint64_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;
					
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const uint64_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode);
					return *this;
			    }
		//
	    ////////////////////////////////////////////////////
	    // signed int

		    ////////////////////////////////////////////////
		    // int8_t

				EmbeddedString::string::string(const int8_t source)
				{
					_buffer = NULL;
					_size = 0;
					
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
				}

				EmbeddedString::string::string(const int8_t source, uint8_t base, bool LetterCase, bool absolute)
				{
					_buffer = NULL;
					_size = 0;
					
					if(absolute == EmbeddedString::IntFormat::Absolute)
					{
						(*this)=string((uint8_t)source,base,LetterCase);
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

				EmbeddedString::string::string(const int8_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;
					
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const int8_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
					return *this;
			    }
			//
			////////////////////////////////////////////////
		    // int16_t

				EmbeddedString::string::string(const int16_t source)
			    {
					_buffer = NULL;
					_size = 0;
					
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
			    }

				EmbeddedString::string::string(const int16_t source, uint8_t base, bool LetterCase, bool absolute)
				{
					_buffer = NULL;
					_size = 0;
					
					if(absolute == EmbeddedString::IntFormat::Absolute)
					{
						(*this)=string((uint16_t)source,base,LetterCase);
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

				EmbeddedString::string::string(const int16_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;
					
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const int16_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
					return *this;
			    }
			//
			////////////////////////////////////////////////
		    // int32_t

				EmbeddedString::string::string(const int32_t source)
			    {
					_buffer = NULL;
					_size = 0;
					
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
			    }

				EmbeddedString::string::string(const int32_t source, uint8_t base, bool LetterCase, bool absolute)
				{
					_buffer = NULL;
					_size = 0;
					
					if(absolute == EmbeddedString::IntFormat::Absolute)
					{
						(*this)=string((uint32_t)source,base,LetterCase);
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

				EmbeddedString::string::string(const int32_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;
					
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const int32_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
					return *this;
			    }
			//
			////////////////////////////////////////////////
		    // int64_t

				EmbeddedString::string::string(const int64_t source)
			    {
					_buffer = NULL;
					_size = 0;
					
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
			    }

				EmbeddedString::string::string(const int64_t source, uint8_t base, bool LetterCase, bool absolute)
				{
					_buffer = NULL;
					_size = 0;
					
					if(absolute == EmbeddedString::IntFormat::Absolute)
					{
						(*this)=string((uint64_t)source,base,LetterCase);
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

				EmbeddedString::string::string(const int64_t source, const char* format, uint16_t size)
				{
					_buffer = NULL;
					_size = 0;
					
					char buffer[size];
					sprintf(buffer,format,source);
					resize(size);

					for(uint16_t i = 0; i < _size; i++)
					{
						_buffer[i] = buffer[i];
					}
				}
				
				EmbeddedString::string& EmbeddedString::string::operator=(const int64_t source)
			    {
			    	(*this) = string(source,10,EmbeddedString::LetterCase::Mode,EmbeddedString::IntFormat::Mode);
					return *this;
			    }
	//
	////////////////////////////////////////////////////
    // float

		EmbeddedString::string::string(const float source)
		{
			_buffer = NULL;
			_size = 0;
					
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

		EmbeddedString::string::string(const float source, uint8_t precision)
		{
			_buffer = NULL;
			_size = 0;
					
			#if defined(PSOC_CREATOR)
		    
		        uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		        
		        uint8_t len = left_size+precision+2;
		        char buff[len];
		        char _format[10];
		        
		        _format[0] = '%';  _format[1] = ' ';
		        
		        string *str = NULL;
		        str = new string(left_size);
		        
		        int offset = 2;
		        
		        for(uint8_t i = 0; i < str->length(); i++)
		        {
		            _format[offset+i] = str->CharAt(i);
		        }
		        
		        offset += str->length();
		        _format[offset++] = '.';
		        
		        delete str;
		        str = new string(precision);
		        
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

		EmbeddedString::string& EmbeddedString::string::operator=(const float source)
		{
			(*this) = string(source,3);

			return (*this);
		}
	//
	////////////////////////////////////////////////////
    // double

		EmbeddedString::string::string(const double source)
		{
			_buffer = NULL;
			_size = 0;
					
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

		      	(*this) = dtostrf(source,left_size,3,buff);
		    
		    #endif
		}

		EmbeddedString::string::string(const double source, uint8_t precision)
		{
			_buffer = NULL;
			_size = 0;
					
			#if defined(PSOC_CREATOR)
		    
		        uint8_t left_size  = log10(source)+1;
		        if(source<0){left_size++;}
		        
		        uint8_t len = left_size+precision+2;
		        char buff[len];
		        char _format[10];
		        
		        _format[0] = '%';  _format[1] = ' ';
		        
		        string *str = NULL;
		        str = new string(left_size);
		        
		        int offset = 2;
		        
		        for(uint8_t i = 0; i < str->length(); i++)
		        {
		            _format[offset+i] = str->CharAt(i);
		        }
		        
		        offset += str->length();
		        _format[offset++] = '.';
		        
		        delete str;
		        str = new string(precision);
		        
		        for(uint8_t i = 0; i < str->length(); i++)
		        {
		            _format[offset+i] = str->CharAt(i);
		        }
		        
		        offset += str->length();
		        _format[offset++] = 'f';
		        _format[offset++] = '\0';
		        
		        resize(sprintf(buff,_format,source));
		        
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

		EmbeddedString::string& EmbeddedString::string::operator=(const double source)
		{
			(*this) = string(source);
			return (*this);
		}
	//
    ////////////////////////////////////////////////////
    // string
		#if defined(ARDUINO)

			EmbeddedString::string::string(const ::string& source)
			{
				_buffer = NULL;
				_size = 0;

				resize(source.length()+1);
				for(uint16_t i = 0; i < _size; i++)
				{
					_buffer[i] = source[i];
				}
			}
			
			EmbeddedString::string& EmbeddedString::string::operator=(const ::string& source)
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
		
		EmbeddedString::string::operator char*() const{return _buffer;}
	//
    ////////////////////////////////////////////////////
    // Equality and Inequality Operators
		
		bool EmbeddedString::string::operator==(const string& rhs) const
		{
			if(strcmp(_buffer,rhs)==0){return 1;}
			else{return 0;}
		}

		bool EmbeddedString::string::operator!=(const string& rhs) const
		{
			if(strcmp(_buffer,rhs)==0){return 0;}
			else{return 1;}
		}
	//
    ////////////////////////////////////////////////////
    // Addition Operators

		/////////////////////////////////////////////////////////
		// string

			EmbeddedString::string& EmbeddedString::string::operator+=(const EmbeddedString::string& rhs)
			{
				uint16_t a = _size-1;
				resize(_size + rhs.Size()-1);
				memcpy(_buffer+a,rhs,rhs.Size());
				return (*this);
			}

			EmbeddedString::string EmbeddedString::string::operator+(const EmbeddedString::string& rhs) const
			{
				//tmp += rhs;
				return string(*this) += rhs;
			}
		//
		/////////////////////////////////////////////////////////
		// Char *

			EmbeddedString::string& EmbeddedString::string::operator+=(const char* rhs)
			{
				uint16_t a = _size-1;
				string tmp(rhs);
				resize(_size + tmp.Size()-1);
				memcpy(_buffer+a,tmp,tmp.Size());
				return (*this);
			}

			EmbeddedString::string EmbeddedString::string::operator+(const char* rhs) const
			{
				//tmp += rhs;
				return string(*this) += rhs;
			}
		//
		/////////////////////////////////////////////////////////
		// 	int

			/////////////////////////////////////////////////////
			// unsigned int

				/////////////////////////////////////////////////
				// uint8_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const uint8_t rhs)
					{
						uint16_t a = _size-1;

						EmbeddedString::string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const uint8_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const uint16_t rhs)
					{
						uint16_t a = _size-1;

						string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const uint16_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const uint32_t rhs)
					{
						uint16_t a = _size-1;

						string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const uint32_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint64_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const uint64_t rhs)
					{
						uint16_t a = _size-1;

						string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const uint64_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
			//
			/////////////////////////////////////////////////////
			// signed int

				/////////////////////////////////////////////////
				// int8_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const int8_t rhs)
					{
						uint16_t a = _size-1;

						string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const int8_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const int16_t rhs)
					{
						uint16_t a = _size-1;

						string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const int16_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint8_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const int32_t rhs)
					{
						uint16_t a = _size-1;

						string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const int32_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
				//
				/////////////////////////////////////////////////
				// uint16_t6_t

					EmbeddedString::string& EmbeddedString::string::operator+=(const int64_t rhs)
					{
						uint16_t a = _size-1;

						string tmp(rhs);

						resize(_size + tmp.Size()-1);
						memcpy(_buffer+a,tmp,tmp.Size());
						return (*this);
					}

					EmbeddedString::string EmbeddedString::string::operator+(const int64_t rhs) const
					{
						//tmp += rhs;
						return string(*this) += rhs;
					}
//
//////////////////////////////////////////////////////
// Getters

	uint16_t EmbeddedString::string::Size() const{return _size;}
	uint16_t EmbeddedString::string::size() const{return _size;}

	// string Cross Compatible Methods
	uint16_t EmbeddedString::string::length() const{return _size-1;}
	char* EmbeddedString::string::c_str() const{return _buffer;}


	char EmbeddedString::string::CharAt(uint16_t n) const
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

	void EmbeddedString::string::resize(uint16_t size, char c)
	{
		if(size==_size){return;}

		char tmp[size];
        uint16_t minimum = _size;
        
        if(size<_size){minimum = size;}

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
