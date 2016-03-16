#ifndef GRAPHICSCASEITEM_H
#define GRAPHICSCASEITEM_H

#include <QtGui>
#include "coord.h"

class game;

class GraphicsCaseItem:public QGraphicsRectItem
{
	/* Variables */

	// Couleur de la case
	QColor caseColor ;
	// Coordonnées de la case
	coord *caseCoord ;
	// Pointeur sur la partie
	game *caseGame;

	/* Méthodes */

	// Retourne la forme de la case (item)
	QPainterPath shape() const;
	// Zone du rectangle à représenter
	QRectF boundingRect() const;
	// Fonction virtuelle de QGraphicsItem appelée par QGraphicsView
	void paint(QPainter*,const QStyleOptionGraphicsItem*,QWidget*);

	protected:
	// Fonction qui appelle focus à la reception d'un clique gauche
	void mousePressEvent(QGraphicsSceneMouseEvent*);

	public:
	// Constructeur
	GraphicsCaseItem(coord*,QColor,game*);
	GraphicsCaseItem(coord*,QColor);
	// Destructeur
	~GraphicsCaseItem();
	QColor getColor();
	void setColor(QColor);
};

#endif // GRAPHICSCASEITEM_H
