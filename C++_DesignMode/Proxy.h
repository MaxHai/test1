
#ifndef __PROXY_H__
#define __PROXY_H__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<std::string> getBugs(std::string words)
{
	std::vector<std::string> results;
	std::istringstream ss(words);
	while (!ss.eof())
	{
		std::string word;
		std::getline(ss, word, '|');
		results.push_back(word);
	}
	return results;
}
std::map<int, std::vector<std::string>> Logs;
bool getLogs()
{
	std::ifstream in("E:\\tmp\\XiaoHG.txt");
	if (!in)
	{
		std::cerr << "Open file failed" << std::endl;
		return false;
	}

	std::string line;
	int i = 0;
	while (std::getline(in, line))
	{
		Logs[i] = getBugs(line);
		i++;
	}
	in.close();
	return true;
}



void ProxyModeTest()
{
	getLogs();
	for (int i = 0; i < Logs.size(); i++)
	{
		std::cout << "No." << i << " is";
		for (std::vector<std::string>::iterator iter = Logs[i].begin(); iter != Logs[i].end(); iter++)
		{
			std::cout << (*iter) << std::endl;
		}
	}
}

#endif // !__PROXY_H__
