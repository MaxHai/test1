
#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__

#include <iostream>
#include <string>
#include <vector>

enum PieceColor {
	BLACK,
	WHTIE
};

struct PiecePos
{
	int m_x;
	int m_y;
	PiecePos(int a, int b) :m_x(a), m_y(b) {}
};

class Piece
{
public:
	Piece(PieceColor color) :m_color(color) {}
	~Piece();

public:
	virtual void Draw() {}

protected:
	PieceColor m_color;

private:

};

Piece::~Piece()
{
}

class BlackPiece : public Piece
{
public:
	BlackPiece(PieceColor color) :Piece(color) {}
	~BlackPiece();

public:
	void Draw()
	{
		std::cout << "draw a black" << std::endl;
	}

private:

};

BlackPiece::~BlackPiece()
{
}

class WhitePiece : public Piece
{
public:
	WhitePiece(PieceColor color) :Piece(color) {}
	~WhitePiece();

public:
	void Draw()
	{
		std::cout << "draw a white" << std::endl;
	}

private:

};

WhitePiece::~WhitePiece()
{
}

class PieceBoard
{
public:
	PieceBoard(std::string black, std::string white) :m_blackName(black), m_whiteName(white)
	{
		m_pBlackPiece = nullptr;
		m_pWhitePiece = nullptr;
	}
	~PieceBoard();

public:
	void SetPiece(PieceColor color, PiecePos pos)
	{
		Piece* pPiece = nullptr;
		if (color == BLACK)
		{
			if (m_pBlackPiece == nullptr)
			{
				m_pBlackPiece = new BlackPiece(color);
			}
			std::cout << m_blackName << " in " << pos.m_x << "," << pos.m_y << " add one" << std::endl;
			m_pBlackPiece->Draw();
		}
		else
		{
			if (m_pWhitePiece == nullptr)
			{
				m_pWhitePiece = new WhitePiece(color);
			}
			std::cout << m_whiteName << " in " << pos.m_x << "," << pos.m_y << " add one" << std::endl;
			m_pWhitePiece->Draw();
		}
		m_vecPiece.push_back(pos);
	}

private:
	void clear()
	{
		delete m_pBlackPiece;
		delete m_pWhitePiece;
	}

private:
	std::vector<PiecePos> m_vecPiece;
	std::string m_blackName;
	std::string m_whiteName;
	Piece* m_pBlackPiece;
	Piece* m_pWhitePiece;
};

PieceBoard::~PieceBoard()
{
	clear();
}

void FlyWeightModeTest()
{
	PieceBoard pieceBoard("laoxia", "laoding");
	pieceBoard.SetPiece(BLACK, PiecePos(44, 37));
	pieceBoard.SetPiece(WHTIE, PiecePos(19, 70));
	pieceBoard.SetPiece(BLACK, PiecePos(1, 1));
	pieceBoard.SetPiece(WHTIE, PiecePos(2, 3));
}

#endif // !__FLYWEIGHT_H__
