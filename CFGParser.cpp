#include "CFGParser.hpp"
#include <algorithm>
#include <chrono>
#include <future>


//#define DEBUG


CFGParser::CFGParser(const std::string& cfg_file) : 
	_ptype(KEY),
	_line(0),
	_cfg_base_path("")
{
#ifdef DEBUG
		auto& start = std::chrono::high_resolution_clock::now();
#endif	
	this->process_file(cfg_file);
#ifdef DEBUG
		auto& finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> elapsed = finish - start;
		std::cout << "Elapsed Time: " << elapsed.count() << " seconds" << std::endl;
#endif
}


CFGParser::~CFGParser()
{
	_buffer.clear();
}


const bool CFGParser::getBool(const std::string& section, const std::string& key, const bool& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		if(str == "true" || str == "on" || str == "yes" || str == "1") //Of course, you can add you own values...
		{
			return true;
		}
		else if(str == "false" || str == "off" || str == "no" || str == "0")
		{
			return false;
		}
		else
		{
			std::cout << "Unknown boolean value!" << "\n}" << std::endl;
			return default_value;
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const char CFGParser::getChar(const std::string& section, const std::string& key, const char& default_value) const
{
	char value = 0;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;

		std::istringstream stream(str);
		if (stream.fail() || stream.bad())
		{
			std::cout << "Can't convert string \"" << str << "\" to value! Return to default value..." << "\n}" << std::endl;
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
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const unsigned char CFGParser::getUChar(const std::string& section, const std::string& key, const unsigned char& default_value) const
{
	unsigned char value = 0;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;

		std::istringstream stream(str);
		if (stream.fail() || stream.bad())
		{
			std::cout << "Can't convert string \"" << str << "\" to value! Return to default value..." << "\n}" << std::endl;
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
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const short CFGParser::getShort(const std::string& section, const std::string& key, const short& default_value) const
{
	short value = 0;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;

		std::istringstream stream(str);
		if (stream.fail() || stream.bad())
		{
			std::cout << "Can't convert string \"" << str << "\" to value! Return to default value..." << "\n}" << std::endl;
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
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const unsigned short CFGParser::getUShort(const std::string& section, const std::string& key, const unsigned short& default_value) const
{
	unsigned short value = 0;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;

		std::istringstream stream(str);
		if (stream.fail() || stream.bad())
		{
			std::cout << "Can't convert string \"" << str << "\" to value! Return to default value..." << "\n}" << std::endl;
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
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const int CFGParser::getInt(const std::string& section, const std::string& key, const int& default_value) const
{
	int value = 0;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stoi(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const unsigned int CFGParser::getUInt(const std::string& section, const std::string& key, const unsigned int& default_value) const
{
	unsigned int value = 0U;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;

		std::istringstream stream(str);
		if (stream.fail() || stream.bad())
		{
			std::cout << "Can't convert string \"" << str << "\" to value! Return to default value..." << "\n}" << std::endl;
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
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const long CFGParser::getLong(const std::string& section, const std::string& key, const long& default_value) const
{
	long value = 0L;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stol(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const unsigned long CFGParser::getULong(const std::string& section, const std::string& key, const unsigned long& default_value) const
{
	unsigned long value = 0UL;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stoul(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const long long CFGParser::getLLong(const std::string& section, const std::string& key, const long long& default_value) const
{
	long long value = 0LL;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stoll(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const unsigned long long CFGParser::getULLong(const std::string& section, const std::string& key, const unsigned long long& default_value) const
{
	unsigned long long value = 0ULL;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stoull(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const float CFGParser::getFloat(const std::string& section, const std::string& key, const float& default_value) const
{
	float value = 0.0f;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stof(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const double CFGParser::getDouble(const std::string& section, const std::string& key, const double& default_value) const
{
	double value = 0.0;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stod(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const long double CFGParser::getLDouble(const std::string& section, const std::string& key, const long double& default_value) const
{
	long double value = 0.0;

	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return std::stold(str);
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec2 CFGParser::getVec2f(const std::string& section, const std::string& key, const Vec2& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
				case ',':
					vec.push_back(svalue);
					svalue.clear();
				break;

				default:
					svalue += ch;
				break;
			}
		}

		vec.push_back(svalue);
		svalue.clear();

		const std::size_t vsize = vec.size();

		if (vsize < 2U)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 2 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 2U)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 2 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec2(std::stof(vec[0]), std::stof(vec[1]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec2i CFGParser::getVec2i(const std::string& section, const std::string& key, const Vec2i& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		const std::size_t vsize = vec.size();

		if (vsize < 2U)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 2 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 2U)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 2 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec2i(std::stoi(vec[0]), std::stoi(vec[1]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec2u CFGParser::getVec2u(const std::string& section, const std::string& key, const Vec2u& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		const std::size_t vsize = vec.size();

		if (vsize < 2U)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 2 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 2U)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 2 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec2u(static_cast<unsigned int>(std::stoul(vec[0])), static_cast<unsigned int>(std::stoul(vec[1])));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec3 CFGParser::getVec3f(const std::string& section, const std::string& key, const Vec3& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		vec.push_back(svalue);
		svalue.clear();

		const std::size_t vsize = vec.size();

		if (vsize < 3u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 3 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 3u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 3 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec3(std::stof(vec[0]), std::stof(vec[1]), std::stof(vec[2]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec3i CFGParser::getVec3i(const std::string& section, const std::string& key, const Vec3i& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		vec.push_back(svalue);
		svalue.clear();

		const std::size_t vsize = vec.size();

		if (vsize < 3u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 3 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 3u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 3 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec3i(std::stoi(vec[0]), std::stoi(vec[1]), std::stoi(vec[2]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec3u CFGParser::getVec3u(const std::string& section, const std::string& key, const Vec3u& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		vec.push_back(svalue);
		svalue.clear();

		const std::size_t vsize = vec.size();

		if (vsize < 3u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 3 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 3u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 3 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec3u(std::stoul(vec[0]), std::stoul(vec[1]), std::stoul(vec[2]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec4 CFGParser::getVec4f(const std::string& section, const std::string& key, const Vec4& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		vec.push_back(svalue);
		svalue.clear();

		const std::size_t vsize = vec.size();

		if (vsize < 4u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 4 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 4u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 4 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec4(std::stof(vec[0]), std::stof(vec[1]), std::stof(vec[2]), std::stof(vec[3]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec4i CFGParser::getVec4i(const std::string& section, const std::string& key, const Vec4i& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		vec.push_back(svalue);
		svalue.clear();

		const std::size_t vsize = vec.size();

		if (vsize < 4u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 4 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 4u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 4 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec4i(std::stoi(vec[0]), std::stoi(vec[1]), std::stoi(vec[2]), std::stoi(vec[3]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const Vec4u CFGParser::getVec4u(const std::string& section, const std::string& key, const Vec4u& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		std::string svalue;
		std::vector<std::string> vec;

		for (std::size_t i = 0U; i < str.size(); ++i)
		{
			const char& ch = str[i];
			switch (ch)
			{
			case ',':
				vec.push_back(svalue);
				svalue.clear();
				break;

			default:
				svalue += ch;
				break;
			}
		}

		vec.push_back(svalue);
		svalue.clear();

		const std::size_t vsize = vec.size();

		if (vsize < 4u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have less than 4 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else if (vsize > 4u)
		{
			std::cout << "Section \"" << section << "\" key \"" << key << "\" have greater than 4 parameters! Return default value..." << "\n}" << std::endl;
			return default_value;
		}
		else
		{
			return Vec4u(std::stoul(vec[0]), std::stoul(vec[1]), std::stoul(vec[2]), std::stoul(vec[3]));
		}
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const std::string& CFGParser::getString(const std::string& section, const std::string& key, const std::string& default_value) const
{
	if (this->isSectionKeyExist(section, key))
	{
		const std::string& str = _buffer.at(section).at(key).value;
		return str;
	}
	else
	{
		std::cout << "Section \"" << section << "\" or key \"" << key << "\" doesn't exist!" << "\n}" << std::endl;
		return default_value;
	}
}


const std::size_t CFGParser::getSectionNum() const
{
	return _buffer.size();
}


const std::size_t CFGParser::getConfigNum(const std::string& section) const
{
	if(this->isSectionExist(section))
	{
		return _buffer.at(section).size();
	}
	else
	{
		std::cout << "Section \"" << section << "\" doesn't exist!" << "\n}" << std::endl;
		return 0U;
	}
}


void CFGParser::setBaseConfigPath(const std::string& path)
{
	_cfg_base_path = path;
}


const std::string& CFGParser::getBaseConfigPath() const
{
	return _cfg_base_path;
}


void CFGParser::debug()
{
	for (section_map::const_iterator it = _buffer.begin(); it != _buffer.end(); ++it)
	{
		std::cout << "[" << (*it).first << "]" << std::endl;
		for (value_map::const_iterator itr = (*it).second.begin(); itr != (*it).second.end(); ++itr)
		{
			std::cout << (*itr).first << " = " << (*itr).second.value << std::endl;
		}
		
		std::cout << "\n" << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////
//protected functions
/////////////////////////////////////////////////////////////////////////////////

void CFGParser::process_file(const std::string& cfg_file)
{
	std::fstream _file;
	
	_file.open(cfg_file, std::ios::in);
	if (_file.good())
	{
		std::string temp, section, preprocess, inherit_name, key, value;

		while (!_file.eof())
		{
			_line++;
			std::getline(_file, temp);

			if (temp.empty() || temp[0] == ';') continue;

			if (temp.find("#include") != std::string::npos)
			{
				std::string path;

				for (auto& ch : temp.substr(8u, temp.length() - 8u))
				{
					if (ch == ' ' || ch == '\t' || ch == '\"' || ch == '<' || ch == '>') continue;
					else
					{
						path += ch;
					}
				}
				
				this->process_file(_cfg_base_path + path);
			}

			_ptype = KEY;

			const std::size_t line_length = temp.size();

			for (std::size_t i = 0; i < line_length; ++i)
			{
				const char& chr = temp[i];
				switch (chr)
				{
					case '[':
						if (_ptype == STRING) value += '[';
						else
						{
							_ptype = SECTION;
							section.clear();
						}
					break;

					case ']':
						if (_ptype == STRING) value += ']';
					break;

					case '#':
						if (_ptype == STRING) value += '#';
						else
						{
							_ptype = PREPROCESSOR;
							preprocess.clear();
						}
					break;
	/*
					case '<':
						if (_ptype == PREPROCESSOR)
						{

							for (std::size_t nm = i; nm < line_length; nm++)
							{
								if (temp.at(nm) == '>')
								{
									break;
								}
								else
								{

								}
							}

							i = (line_length - 1U);
						}
					break;

					case '>':

					break;
	*/
					case ':':
						if (_ptype == SECTION)
						{
							_ptype = INHERIT;//Если у нас все еще секция, то можно наследовать конфиги
#ifdef DEBUG
							std::cout << "Inheriting from \"";// << std::std::endl;
#endif
						}
						else if (_ptype == STRING)
						{
							value += ':';
						}
					break;

					case '=':
						if (_ptype == STRING) value += '=';
						else _ptype = VALUE;
					break;

					case ';':
						if (_ptype == STRING) value += ';';
						else i = (line_length - 1U);
					break;

					case '\"':
						if (_ptype == VALUE)
						{
							_ptype = STRING;
						}
						else if(_ptype == STRING)
						{
							_ptype = KEY;
						}
					break;

					case ' ':
						if (_ptype == STRING) value += ' ';
					break;

					case '\t':
						if (_ptype == STRING) value += '\t';
					break;

					case '\\':
						if (_ptype == STRING && (temp.size() > (i + 1)))
						{				
							const char& next_char = temp[i + 1];

							switch (next_char)
							{
								case 'n':
									value += '\n';
								break;

								case 't':
									value += '\t';
								break;

								case '\"':
									value += '\"';
								break;

								case '\'':
									value += '\'';
								break;

								case '\\':
									value += '\\';
								break;

								default:
									std::cout << "Unknown escape character! Line: " << _line << "\n}" << std::endl;
								break;
							}

							i++;
						}
					break;

					default:
					{
						switch (_ptype)
						{
							case SECTION:
								section += chr;
							break;

							case KEY:
								key += chr;
							break;

							case VALUE:
								value += chr;
							break;

							case STRING:
								value += chr;
							break;

							case PREPROCESSOR:
								preprocess += chr;
							break;

							case INHERIT:
								inherit_name += chr;
							break;
						}
					}
					break;
				}
			}

			//////////////////////////////////////////////////////
			//Errors check
			//////////////////////////////////////////////////////
			
			const bool section_empty = section.empty();
			const bool inherit_empty = inherit_name.empty();
			const bool key_empty = key.empty();
			const bool value_empty = value.empty();
			const bool preproces_empty = preprocess.empty();

			if (section_empty && _ptype == SECTION) std::cout << "Syntax error! Section name is empty at line " << _line << "!" << "\n}" << std::endl;
			if (inherit_empty && _ptype == INHERIT) std::cout << "Syntax error! Inherit name is empty at line " << _line << "!" << "\n}" << std::endl;
			if (key_empty && _ptype == KEY && _ptype != SECTION) std::cout << "Syntax error! Key string is empty at line " << _line << "!" << "\n}" << std::endl;
			if (value_empty && _ptype == KEY) std::cout << "Syntax error! Line doesn't have a \'=\' symbol at line " << _line << "!" << "\n}" << std::endl;
			if (value_empty && _ptype == VALUE) std::cout << "Can't find value at line " << _line << "!" << "\n}" << std::endl;
			if (preproces_empty && _ptype == PREPROCESSOR) std::cout << "Syntax error! Preprocessor command is empty at line " << _line << "!" << "\n}" << std::endl;
			//////////////////////////////////////////////////////

			if (_ptype == PREPROCESSOR && !preproces_empty)
			{

			}

			if (_ptype == INHERIT && !inherit_empty)
			{
#ifdef DEBUG
				std::cout << inherit_name << "\" to section \"" << section << "\"..." << std::endl;
#endif

				if (this->isSectionExist(inherit_name))
				{
					for (value_map::const_iterator itr = _buffer.at(inherit_name).begin(); itr != _buffer.at(inherit_name).end(); ++itr)
					{
						value_data data;
						data.value = (*itr).second.value;
						data.line = _line;
						const std::string& key_name = (*itr).first;
						_buffer[section][key_name] = data;
					}
				}
				else
				{
					std::cout << "Inherited section \"" << inherit_name << "\" not exist!" << "\n}" << std::endl;
				}

				inherit_name.clear();
				_ptype = KEY;
			}

			value_data data;
			data.value = value;
			data.line = _line;

			if (!section_empty && _ptype != SECTION && !key_empty)
			{
				_buffer[section][key] = data; // Errors check?

				key.clear();
				value.clear();
			}
		}	
	}
	else
	{
		std::cout << "File \"" << cfg_file << "\" not be opened!" << "\n" << std::endl;
	}
	
	_file.close();	
	
}
