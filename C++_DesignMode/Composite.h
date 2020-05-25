
#pragma once

#include <iostream>
#include <list>
#include <string>

class IFile
{
public:
	IFile();
	~IFile();

public:
	virtual void Display() = 0;
	virtual int Add(IFile* iFile) = 0;
	virtual int Remove(IFile* iFile) = 0;
	virtual std::list<IFile*>* GetChild() = 0;

private:

};

IFile::IFile()
{
}

IFile::~IFile()
{
}

class File : public IFile
{
public:
	File(std::string name):m_name(name){}
	~File();

public:
	virtual void Display()
	{
		std::cout << m_name << std::endl;
	}

	virtual int Add(IFile* iFile)
	{
		return -1;
	}

	virtual int Remove(IFile* iFile)
	{
		return -1;
	}

	virtual std::list<IFile*>* GetChild()
	{
		return NULL;
	}

private:
	std::string m_name;
};

File::~File()
{
}

class Dir : public IFile
{
public:
	Dir(std::string name) : m_name(name)
	{
		m_list = new std::list<IFile*>();
	}
	~Dir();

public:
	virtual void Display()
	{
		std::cout << m_name << std::endl;
	}

	virtual int Add(IFile* iFile)
	{
		m_list->push_back(iFile);
		return 0;
	}

	virtual int Remove(IFile* iFile)
	{
		m_list->remove(iFile);
		return 0;
	}

	virtual std::list<IFile*>* GetChild()
	{
		return m_list;
	}

private:
	std::string m_name;
	std::list<IFile*>* m_list;
};

Dir::~Dir()
{
}

void showTree(IFile* root, int level)
{
	if (root == NULL)
	{
		return;
	}
	for (int i = 0; i < level; i++)
	{
		std::cout << "\t";
	}
	root->Display();
	std::list<IFile*>* list1 = root->GetChild();
	if (list1 != NULL)
	{
		for (std::list<IFile*>::iterator iter = list1->begin(); iter != list1->end(); iter++)
		{
			if ((*iter)->GetChild() == NULL)
			{
				for (int i = 0; i < level; i++)
				{
					std::cout << "\t";
				}
				(*iter)->Display();
			}
			else
			{
				showTree(*iter, level + 1);
			}
		}
	}
}

void CompositeModeTest()
{
	Dir* root = new Dir("C:");
	Dir* dir1 = new Dir("Program Files");
	Dir* dir2 = new Dir("windows");

	File* file1 = new File("a.txt");
	File* file2 = new File("1.c");

	root->Add(dir1);
	root->Add(file1);
	dir1->Add(file2);
	dir1->Add(dir2);

	std::list<IFile*>* list1 = root->GetChild();
	showTree(root, 0);
}
