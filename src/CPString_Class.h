#ifndef CROSS_PLATFORM_STRING_CONTAINER_H
#define CROSS_PLATFORM_STRING_CONTAINER_H

	#include "CPString.h"

	namespace CrossPlatformString
	{
		class string
		{

			    ////////////////////////////////////////////////////////////////////////////////////////////
			    // Arduino

			        #if defined(ARDUINO)
						String _string;
			        #endif
			    //
			    ////////////////////////////////////////////////////////////////////////////////////////////
			    // PSoC Creator
			    
			        #if defined(PSOC_CREATOR)
						uint16_t _size;
						char* _buffer;
			        #endif
			    //
			    ////////////////////////////////////////////////////////////////////////////////////////////
			    // Desktop C++
			    
			        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
						std::string _string;
			        #endif
			    //
			    ////////////////////////////////////////////////////////////////////////////////////////////

			public:

				////////////////////////////////////////////////////////////////////////////////////////////
				// Constructors, Destructor and Clear 

					string();
					~string();

					void clear();
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Copy Constructor and assignment operator

					////////////////////////////////////////////////////////////////////////////////////////
					// string

						string(const string& Source);
						string& operator=(const string& Source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// std::string

						#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
							explicit string(const std::string& Source);
							string& operator=(const std::string& Source);
						#endif
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// Arduino String

						#if defined(ARDUINO)
							explicit string(const String& Source);
							string& operator=(const String& Source);
						#endif
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// char *
						explicit string(const char* Source);
						string(const char* Source, unsigned int Size);
						string& operator=(const char* Source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// int

						////////////////////////////////////////////////////////////////////////////////////
						// unsigned int

							string(const uint8_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint8_t Source, const char* format, unsigned int Size);
							string& operator=(const uint8_t Source);

							string(const uint16_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint16_t Source, const char* format, unsigned int Size);
							string& operator=(const uint16_t Source);

							string(const uint32_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint32_t Source, const char* format, unsigned int Size);
							string& operator=(const uint32_t Source);

							string(const uint64_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);
							string(const uint64_t Source, const char* format, unsigned int Size);
							string& operator=(const uint64_t Source);
						//
						////////////////////////////////////////////////////////////////////////////////////
						// signed int

							string(const int8_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool Absolute = CPString::IntFormat::Mode);
							string(const int8_t Source, const char* format, unsigned int Size);
							string& operator=(const int8_t Source);

							string(const int16_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool Absolute = CPString::IntFormat::Mode);
							string(const int16_t Source, const char* format, unsigned int Size);
							string& operator=(const int16_t Source);

							string(const int32_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool Absolute = CPString::IntFormat::Mode);
							string(const int32_t Source, const char* format, unsigned int Size);
							string& operator=(const int32_t Source);

							string(const int64_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool Absolute = CPString::IntFormat::Mode);
							string(const int64_t Source, const char* format, unsigned int Size);
							string& operator=(const int64_t Source);
						//
						////////////////////////////////////////////////////////////////////////////////////
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// float

						explicit string(const float Source);
						string(const float Source, uint8_t precision);
						string& operator=(const float Source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// double
						
						//explicit string(const double Source);
						//string(const double Source, uint8_t precision);
						//string& operator=(const double Source);
					//
					////////////////////////////////////////////////////////////////////////////////////////
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// Operators

					////////////////////////////////////////////////////////////////////////////////////////
					// Cast Operators

						////////////////////////////////////////////////////////////////////////////////////
						// std::string

							#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                operator std::string() const;
							#endif
						//
						////////////////////////////////////////////////////////////////////////////////////
						// Arduino String

							#if defined(ARDUINO)
								String& operator String() const;
							#endif
						//
						////////////////////////////////////////////////////////////////////////////////////
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// Equality and Inequality Operator

						bool operator==(const string& rhs) const;
						bool operator!=(const string& rhs) const;
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// Addition and Substraction Operator

						////////////////////////////////////////////////////////////////////////////////////
						// string

							string& operator+=(const string& rhs);
							//string& operator-=(const string& rhs);

							string operator+(const string& rhs) const;
							//string operator-(const string& rhs) const;
						//
						////////////////////////////////////////////////////////////////////////////////////
						// char*
							string& operator+=(const char* rhs);
							//string& operator-=(const string& rhs);

							string operator+(const char* rhs) const;
							//string operator-(const string& rhs) const;
						//
						////////////////////////////////////////////////////////////////////////////////////
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
							////////////////////////////////////////////////////////////////////////////////////
						//
						////////////////////////////////////////////////////////////////////////////////////
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// Subsctipt Array Operator

						char& operator[](const unsigned int i);
						const char& operator[](const unsigned int i) const;
					//
					////////////////////////////////////////////////////////////////////////////////////////
					// Streams
						
						#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                            friend std::ostream& operator<<(std::ostream& os, const CPString::string& String);
						#endif
					//
					////////////////////////////////////////////////////////////////////////////////////////
				//
				////////////////////////////////////////////////////////////////////////////////////////////
				// std::string Cross Compatible Methods

					unsigned int size() const;
					unsigned int length() const;
					const char* c_str() const;
					const char& at(uint16_t n) const;
					void resize(unsigned int Size, char new_chars = ' ');
				//
				////////////////////////////////////////////////////////////////////////////////////////////
			
			private:
			
				void _BaseConversion_uint8 (const uint8_t  Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);
				void _BaseConversion_uint16(const uint16_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);
				void _BaseConversion_uint32(const uint32_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);
				void _BaseConversion_uint64(const uint64_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode);

			
				void _BaseConversion_int8 (const int8_t  Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool IntFormat = CPString::IntFormat::Signed);
				void _BaseConversion_int16(const int16_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool IntFormat = CPString::IntFormat::Signed);
				void _BaseConversion_int32(const int32_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool IntFormat = CPString::IntFormat::Signed);
				void _BaseConversion_int64(const int64_t Source, uint8_t Base = 10, bool LetterCase = CPString::LetterCase::Mode, bool IntFormat = CPString::IntFormat::Signed);

		};
	}


#endif//CROSS_PLATFORM_STRING_CONTAINER_H
