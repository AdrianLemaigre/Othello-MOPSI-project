#include "GraphicsCaseItem.h"
#include "game.h"

// Constructeur
GraphicsCaseItem::GraphicsCaseItem(coord *cCoord,QColor cColor,game *pGame)
{
	caseColor= cColor;
	caseCoord = cCoord;
	caseGame = pGame;
}

GraphicsCaseItem::GraphicsCaseItem(coord *cCoord,QColor cColor)
{
	caseColor= cColor;
	caseCoord = cCoord;
}

// Destructeur
GraphicsCaseItem::~GraphicsCaseItem(){};

/* Méthodes */

// Retourne la forme de la case (item)
QPainterPath GraphicsCaseItem::shape() const
{
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

// Zone du rectangle à représenter
QRectF GraphicsCaseItem::boundingRect() const
{
	return QRectF(55*caseCoord->getx(), 55*caseCoord->gety(), 55, 55);
}

// Fonction virtuelle de QGraphicsItem appelée par QGraphicsView
void GraphicsCaseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setBrush(caseColor);
	painter->drawRect(55*(caseCoord->getx()),55*(caseCoord->gety()), 55, 55);
}

// Fonction qui appelle focus à la reception d'un clique gauche
void GraphicsCaseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() != Qt::LeftButton)
		return;

	caseGame->focus(caseCoord);

	QGraphicsItem::mousePressEvent(event);
}

// Fonction qui renvoie la couleur de la case
QColor GraphicsCaseItem::getColor()
{
	return caseColor;
}

// Fonction qui définie une nouvelle couleur pour la case et mets à jour l'affichage
void GraphicsCaseItem::setColor(QColor color)
{
	caseColor = color;
	update();
}
