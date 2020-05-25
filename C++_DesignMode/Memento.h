
#pragma once

#include <iostream>
#include <string>

class Memento
{
public:
	Memento(std::string word):m_strWord(word){}

private:
	friend class OriginalWord;
	std::string GetWords()
	{
		return m_strWord;
	}

private:
	std::string m_strWord;
};

class OriginalWord
{
public:
	OriginalWord(std::string word):m_strWord(word){}

public:
	Memento* SaveWords()
	{
		return new Memento(m_strWord);
	}

	void RecycleWords(Memento* pMemento)
	{
		m_strWord = pMemento->GetWords();
		std::cout << "存档恢复成功" << std::endl;
	}

	void ShowWords()
	{
		std::cout << m_strWord << std::endl;
	}

private:
	std::string m_strWord;
};

//设置快照，获得快照
class Caretake
{
public:
	Caretake();
	~Caretake();

public:
	void SetMemento(Memento* pMe)
	{
		m_pMemento = pMe;
	}

	Memento* GetMemento()
	{
		return m_pMemento;
	}

private:
	Memento* m_pMemento;
};

Caretake::Caretake()
{
}

Caretake::~Caretake()
{
}

void MementoModeTest()
{
	OriginalWord* pWordFst = new OriginalWord("XiaoHG");
	std::cout << "first msg" << std::endl;
	pWordFst->ShowWords();

	Caretake* pCT = new Caretake();
	pCT->SetMemento(pWordFst->SaveWords());
	std::cout << "保存了当前Fst的快照" << std::endl;

	OriginalWord* pWordSec = new OriginalWord("哈哈哈哈哈");
	std::cout << "second msg" << std::endl;
	pWordSec->ShowWords();
}
