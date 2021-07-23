#ifndef EMBEDDED_STRING_CONTAINER_H
#define EMBEDDED_STRING_CONTAINER_H

	#include "EmbeddedString.h"
	#include "EmbeddedString_Definitions.h"

	namespace EString
	{
		class String
		{
			uint16_t _size;
			char* _buffer;

			public:

				////////////////////////////////////////////////////////////////////////////////////////////
				// Constructors, Destructor and Clear 
					String();
					~String();
					void Clear();
					void clear();
				////////////////////////////////////////////////////////////////////////////////////////////
				// Copy Constructor and assignment operator

					////////////////////////////////////////////////////////////////////////////////////////
					// String
						String(const String& source);
						String& operator=(const String& source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// char *
						explicit String(const char* source);
						String(const char* source, uint16_t size);
						String& operator=(const char* source);
					////////////////////////////////////////////////////////////////////////////////////////
					// int

						////////////////////////////////////////////////////////////////////////////////////
						// unsigned int

							explicit String(const uint8_t source);
							String(const uint8_t source, uint8_t base, bool LetterCase = EString::LowerCase);
							String(const uint8_t source, const char* format, uint16_t size);
							String& operator=(const uint8_t source);

							explicit String(const uint16_t source);
							String(const uint16_t source, uint8_t base, bool LetterCase = EString::LowerCase);
							String(const uint16_t source, const char* format, uint16_t size);
							String& operator=(const uint16_t source);

							explicit String(const uint32_t source);
							String(const uint32_t source, uint8_t base, bool LetterCase = EString::LowerCase);
							String(const uint32_t source, const char* format, uint16_t size);
							String& operator=(const uint32_t source);

							explicit String(const uint64_t source);
							String(const uint64_t source, uint8_t base, bool LetterCase = EString::LowerCase);
							String(const uint64_t source, const char* format, uint16_t size);
							String& operator=(const uint64_t source);
						//
						////////////////////////////////////////////////////////////////////////////////////
						// signed int

							explicit String(const int8_t source);
							String(const int8_t source, uint8_t base, bool LetterCase = EString::LowerCase, bool absolute = EString::IntSigned);
							String(const int8_t source, const char* format, uint16_t size);
							String& operator=(const int8_t source);

							explicit String(const int16_t source);
							String(const int16_t source, uint8_t base, bool LetterCase = EString::LowerCase, bool absolute = EString::IntSigned);
							String(const int16_t source, const char* format, uint16_t size);
							String& operator=(const int16_t source);

							explicit String(const int32_t source);
							String(const int32_t source, uint8_t base, bool LetterCase = EString::LowerCase, bool absolute = EString::IntSigned);
							String(const int32_t source, const char* format, uint16_t size);
							String& operator=(const int32_t source);

							explicit String(const int64_t source);
							String(const int64_t source, uint8_t base, bool LetterCase = EString::LowerCase, bool absolute = EString::IntSigned);
							String(const int64_t source, const char* format, uint16_t size);
							String& operator=(const int64_t source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// float
						explicit String(const float source);
						String(const float source, uint8_t precision);
						String& operator=(const float source);
					////////////////////////////////////////////////////////////////////////////////////////
					// double
						explicit String(const double source);
						String(const double source, uint8_t precision);
						String& operator=(const double source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// String
						#if defined(ARDUINO)
							explicit String(const ::String& source);
							String& operator=(const ::String& source);
						#endif
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Equality and Inequality Operator

					bool operator==(const String& rhs) const;
					bool operator!=(const String& rhs) const;
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Addition and Substraction Operator

					////////////////////////////////////////////////////////////////////////////////////////
					// String
						String& operator+=(const String& rhs);
						//String& operator-=(const String& rhs);

						String operator+(const String& rhs) const;
						//String operator-(const String& rhs) const;
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// char*
						String& operator+=(const char* rhs);
						//String& operator-=(const String& rhs);

						String operator+(const char* rhs) const;
						//String operator-(const String& rhs) const;
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// Integers

						////////////////////////////////////////////////////////////////////////////////////
						// unsigned int

							String& operator+=(const uint8_t rhs);
							String operator+(const uint8_t rhs) const;

							String& operator+=(const uint16_t rhs);
							String operator+(const uint16_t rhs) const;

							String& operator+=(const uint32_t rhs);
							String operator+(const uint32_t rhs) const;

							String& operator+=(const uint64_t rhs);
							String operator+(const uint64_t rhs) const;
						//
						////////////////////////////////////////////////////////////////////////////////////
						// signed int

							String& operator+=(const int8_t rhs);
							String operator+(const int8_t rhs) const;

							String& operator+=(const int16_t rhs);
							String operator+(const int16_t rhs) const;

							String& operator+=(const int32_t rhs);
							String operator+(const int32_t rhs) const;

							String& operator+=(const int64_t rhs);
							String operator+(const int64_t rhs) const;
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Subsctipt Array Operator
					char& operator[](const int i){return _buffer[i];}
					const char& operator[](const int i) const{return _buffer[i];}
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Cast Operators

					operator char*() const;
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Getters

					uint16_t Size() const;
					uint16_t size() const;
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				//String Cross Compatible Methods

					char* c_str() const;
					uint16_t length() const;
					char CharAt(uint16_t n) const;
					void resize(uint16_t size, char c = '\0');
				//
				////////////////////////////////////////////////////////////////////////////////////////////
			
			private:
			

		};
	}


#endif//EMBEDDED_STRING_CONTAINER_H