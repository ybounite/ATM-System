#include "./includes/ATM_Simulation.hpp"
namespace StringUtils
{
	string	Tabs(short Counter)
	{
		string  tab;
		tab = "";
		for (int i = 0; i < Counter; i++)
			tab += "\t";
		return (tab);
	}

	vector <string>    SplitString(string _str, string delim)
	{
		vector <string> vString;
		size_t   Pos;
		string  Word;

		while ((Pos = _str.find(delim)) != std::string::npos)
		{
			Word = _str.substr(0 , Pos);
			if (!Word.empty())
				vString.push_back(Word);
			_str.erase(0, Pos + delim.length());
		}
		if (!_str.empty())
			vString.push_back(_str);
		return vString;
	}

	string JoinString(vector <string> vString, string delim)
	{
		string  S1 = "";
		for (string &vS : vString)
			S1 += (vS + delim);

		return S1.substr(0, S1.length() - delim.length());
	}
}
