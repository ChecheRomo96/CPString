#ifndef CROSS_PLATFORM_STRING_CONTAINER_H
#define CROSS_PLATFORM_STRING_CONTAINER_H

	#include "CPString.h"

	namespace CrossPlatformString
	{
		class string
		{
			uint16_t _size;
			char* _buffer;

			public:

				////////////////////////////////////////////////////////////////////////////////////////////
				// Constructors, Destructor and Clear 
					string();
					~string();
					void Clear();
					void clear();
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Copy Constructor and assignment operator

					////////////////////////////////////////////////////////////////////////////////////////
					// string
						string(const string& source);
						string& operator=(const string& source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// char *
						explicit string(const char* source);
						string(const char* source, uint16_t size);
						string& operator=(const char* source);
					////////////////////////////////////////////////////////////////////////////////////////
					// int

						////////////////////////////////////////////////////////////////////////////////////
						// unsigned int

							explicit string(const uint8_t source);
							string(const uint8_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint8_t source, const char* format, uint16_t size);
							string& operator=(const uint8_t source);

							explicit string(const uint16_t source);
							string(const uint16_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint16_t source, const char* format, uint16_t size);
							string& operator=(const uint16_t source);

							explicit string(const uint32_t source);
							string(const uint32_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint32_t source, const char* format, uint16_t size);
							string& operator=(const uint32_t source);

							explicit string(const uint64_t source);
							string(const uint64_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint64_t source, const char* format, uint16_t size);
							string& operator=(const uint64_t source);
						//
						////////////////////////////////////////////////////////////////////////////////////
						// signed int

							explicit string(const int8_t source);
							string(const int8_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode, bool absolute = CPString::IntFormat::Mode);
							string(const int8_t source, const char* format, uint16_t size);
							string& operator=(const int8_t source);

							explicit string(const int16_t source);
							string(const int16_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode, bool absolute = CPString::IntFormat::Mode);
							string(const int16_t source, const char* format, uint16_t size);
							string& operator=(const int16_t source);

							explicit string(const int32_t source);
							string(const int32_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode, bool absolute = CPString::IntFormat::Mode);
							string(const int32_t source, const char* format, uint16_t size);
							string& operator=(const int32_t source);

							explicit string(const int64_t source);
							string(const int64_t source, uint8_t base, bool LetterCase = CPString::LetterCase::Mode, bool absolute = CPString::IntFormat::Mode);
							string(const int64_t source, const char* format, uint16_t size);
							string& operator=(const int64_t source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// float
						explicit string(const float source);
						string(const float source, uint8_t precision);
						string& operator=(const float source);
					////////////////////////////////////////////////////////////////////////////////////////
					// double
						explicit string(const double source);
						string(const double source, uint8_t precision);
						string& operator=(const double source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// string
						#if defined(ARDUINO)
							explicit string(const CPString::string& source);
							string& operator=(const CPString::string& source);
						#endif
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Equality and Inequality Operator

					bool operator==(const string& rhs) const;
					bool operator!=(const string& rhs) const;
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Addition and Substraction Operator

					////////////////////////////////////////////////////////////////////////////////////////
					// string
						string& operator+=(const string& rhs);
						//string& operator-=(const string& rhs);

						string operator+(const string& rhs) const;
						//string operator-(const string& rhs) const;
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// char*
						string& operator+=(const char* rhs);
						//string& operator-=(const string& rhs);

						string operator+(const char* rhs) const;
						//string operator-(const string& rhs) const;
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// Integers

						////////////////////////////////////////////////////////////////////////////////////
						// unsigned int

							string& operator+=(const uint8_t rhs);
							string operator+(const uint8_t rhs) const;

							string& operator+=(const uint16_t rhs);
							string operator+(const uint16_t rhs) const;

							string& operator+=(const uint32_t rhs);
							string operator+(const uint32_t rhs) const;

							string& operator+=(const uint64_t rhs);
							string operator+(const uint64_t rhs) const;
						//
						////////////////////////////////////////////////////////////////////////////////////
						// signed int

							string& operator+=(const int8_t rhs);
							string operator+(const int8_t rhs) const;

							string& operator+=(const int16_t rhs);
							string operator+(const int16_t rhs) const;

							string& operator+=(const int32_t rhs);
							string operator+(const int32_t rhs) const;

							string& operator+=(const int64_t rhs);
							string operator+(const int64_t rhs) const;
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
				//string Cross Compatible Methods

					char* c_str() const;
					uint16_t length() const;
					char CharAt(uint16_t n) const;
					void resize(uint16_t size, char c = '\0');
				//
				////////////////////////////////////////////////////////////////////////////////////////////
			
			private:
			

		};
	}


#endif//CROSS_PLATFORM_STRING_CONTAINER_H