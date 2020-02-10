/**
	Copyright (c) 2020 Kazim Kamilov

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgment in the product documentation would be
	appreciated but is not required.
	
	2. Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.
	
	3. This notice may not be removed or altered from any source distribution. 
*/

#ifndef _INI_PARSER_HPP_
#define _INI_PARSER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

#ifdef USE_GLM
  #include "glm/vec2.hpp"
  #include "glm/vec3.hpp"
  #include "glm/vec4.hpp"

  typedef Vec2 Vec2;
  typedef Vec3 Vec3;
  typedef Vec4 Vec4;
  typedef Vec2i Vec2i;
  typedef Vec3i Vec3i;
  typedef Vec4i Vec4i;
  typedef Vec2u Vec2u;
  typedef Vec3u Vec3u;
  typedef glm::uvec4 Vec4u;
#else
  #include "vector.hpp"
#endif


/**
	@brief class for parsing CFG configs in ini-style.
	
	Allow:
	- Boolean variables can be specified as "true" and "false", "on" and "off", "yes" and "no", "1" and "0".
	- Single-line strings with escape sequence characters.
	- Single-line commenting with the symbol ';'
	- Vector values are separated by commas(64, 128, 255).
	- Section inheritance is supported(single for now).
	- File inclde is supported.
	
	The syntax is simple:
	@code
	#include "path_of_the_file_to_include"
	
	[section_name]
	key = value
	key_string = "some text"
	key_vector = 53.74, 632.83, 146.013
	
	[section_name] : inherited_section_name
	key = value
	@endcode
*/
class CFGParser
{
public:

	/**
		@brief Constructor.
		@param Config file path.
	*/
	CFGParser(const std::string& cfg_file);
	
	/**
		@brief Destructor.
	*/
	virtual ~CFGParser();

	/**
		@brief Return bool value. Otherwise return default value.
	*/
	const bool getBool(const std::string& section, const std::string& key, const bool& default_value = false) const;
	
	/**
		@brief Return char value. Otherwise return default value.
	*/
	const char getChar(const std::string& section, const std::string& key, const char& default_value = 0) const;
	
	/**
		@brief Return unsigned char value. Otherwise return default value.
	*/
	const unsigned char getUChar(const std::string& section, const std::string& key, const unsigned char& default_value = 0U) const;
	
	/**
		@brief Return short value. Otherwise return default value.
	*/
	const short getShort(const std::string& section, const std::string& key, const short& default_value = 0) const;
	
	/**
		@brief Return unsigned short value. Otherwise return default value.
	*/
	const unsigned short getUShort(const std::string& section, const std::string& key, const unsigned short& default_value = 0U) const;
	
	/**
		@brief Return int value. Otherwise return default value.
	*/
	const int getInt(const std::string& section, const std::string& key, const int& default_value = 0) const;
	
	/**
		@brief Return unsigned int value. Otherwise return default value.
	*/
	const unsigned int getUInt(const std::string& section, const std::string& key, const unsigned int& default_value = 0U) const;
	
	/**
		@brief Return long value. Otherwise return default value.
	*/
	const long getLong(const std::string& section, const std::string& key, const long& default_value = 0L) const;
	
	/**
		@brief Return unsigned long value. Otherwise return default value.
	*/
	const unsigned long getULong(const std::string& section, const std::string& key, const unsigned long& default_value = 0UL) const;
	
	/**
		@brief Return long long value. Otherwise return default value.
	*/
	const long long getLLong(const std::string& section, const std::string& key, const long long& default_value = 0LL) const;
	
	/**
		@brief Return unsigned long long value. Otherwise return default value.
	*/
	const unsigned long long getULLong(const std::string& section, const std::string& key, const unsigned long long& default_value = 0ULL) const;
	
	/**
		@brief Return float value. Otherwise return default value.
	*/
	const float getFloat(const std::string& section, const std::string& key, const float& default_value = 0.0f) const;
	
	/**
		@brief Return double value. Otherwise return default value.
	*/
	const double getDouble(const std::string& section, const std::string& key, const double& default_value = 0.0) const;
	
	/**
		@brief Return long double value. Otherwise return default value.
	*/
	const long double getLDouble(const std::string& section, const std::string& key, const long double& default_value = 0.0) const;

	/**
		@brief Return string value. Otherwise return default value.
	*/
	const std::string& getString(const std::string& section, const std::string& key, const std::string& default_value = "empty_string") const;

	/**
		@brief Return Vec2f value. Otherwise return default value.
	*/
	const Vec2 getVec2f(const std::string& section, const std::string& key, const Vec2& default_value = Vec2(0.0f)) const;
	
	/**
		@brief Return Vec2i value. Otherwise return default value.
	*/
	const Vec2i getVec2i(const std::string& section, const std::string& key, const Vec2i& default_value = Vec2i(0)) const;
	
	/**
		@brief Return Vec2u value. Otherwise return default value.
	*/
	const Vec2u getVec2u(const std::string& section, const std::string& key, const Vec2u& default_value = Vec2u(0U)) const;

	/**
		@brief Return Vec3f value. Otherwise return default value.
	*/
	const Vec3 getVec3f(const std::string& section, const std::string& key, const Vec3& default_value = Vec3(0.0f)) const;
	
	/**
		@brief Return Vec3i value. Otherwise return default value.
	*/
	const Vec3i getVec3i(const std::string& section, const std::string& key, const Vec3i& default_value = Vec3i(0)) const;
	
	/**
		@brief Return Vec3u value. Otherwise return default value.
	*/
	const Vec3u getVec3u(const std::string& section, const std::string& key, const Vec3u& default_value = Vec3u(0U)) const;

	/**
		@brief Return Vec4f value. Otherwise return default value.
	*/
	const Vec4 getVec4f(const std::string& section, const std::string& key, const Vec4& default_value = Vec4(0.0f)) const;
	
	/**
		@brief Return Vec4i value. Otherwise return default value.
	*/
	const Vec4i getVec4i(const std::string& section, const std::string& key, const Vec4i& default_value = Vec4i(0)) const;
	
	/**
		@brief Return Vec4u value. Otherwise return default value.
	*/
	const Vec4u getVec4u(const std::string& section, const std::string& key, const Vec4u& default_value = Vec4u(0U)) const;

	/**
		@brief Template function. With this you can get any numeric value(nothing more!). Work with std::istringstream SEAL_CLASS_ALIGN class.
	*/
	template<typename T> const T get(const std::string& section, const std::string& key, const T& default_value = 0)
	{
		T value = 0;
		
		if (this->isSectionKeyExist(section, key))
		{
			const std::string& str = _buffer.at(section).at(key).value;

			std::istringstream stream(str);
			if (stream.fail() || stream.bad())
			{
				std::cout << "Can't convert string \"" << str << "\" to value! Return to default value..." << std::endl;
				return default_value;
			}
			else
			{
				stream >> value;
				return value;
			}
		}
		else
		{
			std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << std::endl;
			return default_value;
		}
	}

	/**
		@brief Return number of sections.
	*/
	const std::size_t getSectionNum() const;
	
	/**
		@brief Return number of configs inside section.
	*/
	const std::size_t getConfigNum(const std::string& section) const;

	/**
		@brief Sets the path relative to which files are included.
	*/
	void setBaseConfigPath(const std::string& path);

	/**
		@brief Return the path relative to which files are included.
	*/
	const std::string& getBaseConfigPath() const;

	/**
		@brief Short check, exist section or not.
	*/
	inline const bool isSectionExist(const std::string& section) const
	{
		return (_buffer.find(section) != _buffer.end()) ? true : false;
	}

	/**
		@brief Short check, exist key in section or not.
	*/
	inline const bool isSectionKeyExist(const std::string& section, const std::string& key) const
	{
		return (_buffer.find(section) != _buffer.end()) ? ((_buffer.at(section).find(key) != _buffer.at(section).end()) ? true : false) : false;
	}

	/**
		@brief For debug only. Prints all configs to console.
	*/
	void debug();

protected:

	enum ProcessType
	{
		SECTION = 0x01,
		KEY = 0x02,
		VALUE = 0x03,
		INHERIT = 0x04,
		STRING = 0x05,
		PREPROCESSOR = 0x06
	};

	struct value_data
	{
		std::string value;
		std::size_t line;
	};

	typedef std::unordered_map<std::string, value_data> value_map;
	typedef std::unordered_map<std::string, value_map> section_map;

	void process_file(const std::string& cfg_file);

private:
	section_map _buffer;
	std::string _cfg_base_path;
	ProcessType _ptype;
	std::size_t _line;

};

#endif
