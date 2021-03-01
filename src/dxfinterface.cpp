/*
  ZIMA-libqdxf
  http://www.zima-engineering.cz/projekty/ZIMA-libqdxf

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "dxfinterface.h"
#include "spline.h"
#include <iostream>
#include <QPen>
#include <QDebug>
#include "scene_items.h"

DXFInterface::DXFInterface(QString filename)
{

    dxfRW *rw = new dxfRW(filename.toUtf8());
    rw->read(this, false);

    QRectF bound = QRectF(minx, miny, maxx-minx, maxy-miny);

    this->dxf_item = new DxfItem(QColor(255,255,255),&this->linesF, &this->pointsF, &this->circlesF, bound);

    //mScene.setBackgroundBrush(QBrush(Qt::black));
}

DXFInterface::DXFInterface(){}
DXFInterface::~DXFInterface(){}

void DXFInterface::iniDXF(QString filename){

    dxfRW *rw = new dxfRW(filename.toUtf8());
    rw->read(this, false);
    QRectF bound = QRectF(minx, miny, maxx-minx, maxy-miny);
    this->dxf_item = new DxfItem(QColor(255,255,255),&this->linesF, &this->pointsF, &this->circlesF, bound);

}


void DXFInterface::addArc(const DRW_Arc &data){}

void DXFInterface::addCircle(const DRW_Circle &data)
{
    set_boundary(data.basePoint.x - data.radious, data.basePoint.y - data.radious);
    set_boundary(data.basePoint.x + data.radious, data.basePoint.y + data.radious);
    this->circlesF.append(QRectF(data.basePoint.x - data.radious,
                                 data.basePoint.y - data.radious,
                                 data.radious*2,
                                 data.radious*2));
    //circles.append(data);
    //return mScene.addEllipse(data.basePoint.x-data.radious, data.basePoint.y-data.radious, 2*data.radious, 2*data.radious, attributesToPen(&data));
}



void DXFInterface::addEllipse(const DRW_Ellipse &data)
{

    //ellipses.append(data);

    //this->ellipses.append(DRW_Ellipse(data));


    DRW_Ellipse *el = new DRW_Ellipse(data);
    DRW_Polyline *pl = new DRW_Polyline();
    el->toPolyline(pl);
    drawPolyline(pl->vertlist);
}

void DXFInterface::addLayer(const DRW_Layer &data){}



void DXFInterface::addLine(const DRW_Line &data)
{
    set_boundary(data.basePoint.x, data.basePoint.y);
    set_boundary(data.secPoint.x, data.secPoint.y);
    linesF.append(QLineF(data.basePoint.x, data.basePoint.y,
                         data.secPoint.x, data.secPoint.y));
}

void DXFInterface::addLWPolyline(const DRW_LWPolyline &data)
{


    for(unsigned int i = 1; i < data.vertlist.size(); i++)
    {
        DRW_Vertex2D *verta = data.vertlist[i-1];
        DRW_Vertex2D *vertb = data.vertlist[i];
        set_boundary(verta->x, verta->y);
        set_boundary(vertb->x, vertb->y);
        linesF.append(QLineF(verta->x, verta->y,
                             vertb->x, vertb->y));
    }
}


void DXFInterface::addPoint(const DRW_Point &data)
{
    set_boundary(data.basePoint.x, data.basePoint.y);
    pointsF.append(QPointF(data.basePoint.x, data.basePoint.y));
}

void DXFInterface::addPolyline(const DRW_Polyline &data)
{
    drawPolyline(data.vertlist);
}

void DXFInterface::addSpline(const DRW_Spline *data)
{
    QList<QLineF> qlines;
    Spline sp(data);
    sp.update(qlines);

    foreach(QLineF line, qlines)
    {
        set_boundary(double(line.p1().x()), double(line.p1().y()));
        set_boundary(double(line.p2().x()), double(line.p2().y()));
        linesF.append(QLineF(double(line.p1().x()),
                             double(line.p1().y()),
                             double(line.p2().x()),
                             double(line.p2().y())
                             )
                      );
    }
}


void DXFInterface::drawPolyline(std::vector<DRW_Vertex*> vertlist)
{
    for(unsigned int i = 1; i < vertlist.size(); i++)
    {
        DRW_Vertex *verta = vertlist[i-1];
        DRW_Vertex *vertb = vertlist[i];
        set_boundary(verta->basePoint.x, verta->basePoint.y);
        set_boundary(vertb->basePoint.x, vertb->basePoint.y);
        linesF.append(QLineF(verta->basePoint.x,
                             verta->basePoint.y,
                             vertb->basePoint.x,
                             vertb->basePoint.y
                             )
                      );
    }
}

QGraphicsScene * DXFInterface::scene()
{
    return nullptr;
}

void DXFInterface::set_boundary(double x, double y)
{
    if( x < this->minx)
        minx = x;
    if(x > this->maxx)
        maxx = x;
    if(y < this->miny)
        miny = y;
    if(y > this->maxy)
        maxy = y;
}

void DXFInterface::add3dFace(const DRW_3Dface & /*data*/){}
void DXFInterface::addBlock(const DRW_Block & /*data*/){}
void DXFInterface::setBlock(const int /*handle*/){}
void DXFInterface::addComment(const char * /*comment*/){}
void DXFInterface::addDimAlign(const DRW_DimAligned * /*data*/){}
void DXFInterface::addDimAngular(const DRW_DimAngular * /*data*/){}
void DXFInterface::addDimAngular3P(const DRW_DimAngular3p * /*data*/){}
void DXFInterface::addDimDiametric(const DRW_DimDiametric * /*data*/){}
void DXFInterface::addDimLinear(const DRW_DimLinear * /*data*/){}
void DXFInterface::addDimOrdinate(const DRW_DimOrdinate * /*data*/){}
void DXFInterface::addDimRadial(const DRW_DimRadial * /*data*/){}
void DXFInterface::addDimStyle(const DRW_Dimstyle & /*data*/){}
void DXFInterface::addHatch(const DRW_Hatch * /*data*/){}
void DXFInterface::addHeader(const DRW_Header * /*data*/){}
void DXFInterface::addImage(const DRW_Image * /*data*/){}
void DXFInterface::addInsert(const DRW_Insert & /*data*/){}
void DXFInterface::addKnot(const DRW_Entity & /*data*/){}
void DXFInterface::addLeader(const DRW_Leader * /*data*/){}
void DXFInterface::addLType(const DRW_LType & /*data*/){}
void DXFInterface::addMText(const DRW_MText & /*data*/){}
void DXFInterface::addRay(const DRW_Ray & /*data*/){}
void DXFInterface::addSolid(const DRW_Solid & /*data*/){}
void DXFInterface::addText(const DRW_Text & /*data*/){}
void DXFInterface::addTextStyle(const DRW_Textstyle & /*data*/){}
void DXFInterface::addTrace(const DRW_Trace & /*data*/){}
void DXFInterface::addViewport(const DRW_Viewport & /*data*/){}
void DXFInterface::addVport(const DRW_Vport & /*data*/){}
void DXFInterface::addXline(const DRW_Xline & /*data*/){}
void DXFInterface::endBlock(){}
void DXFInterface::linkImage(const DRW_ImageDef * /*data*/){}
void DXFInterface::writeBlockRecords(){}
void DXFInterface::writeBlocks(){}
void DXFInterface::writeDimstyles(){}
void DXFInterface::writeEntities(){}
void DXFInterface::writeHeader(DRW_Header & /*data*/){}
void DXFInterface::writeLayers(){}
void DXFInterface::writeLTypes(){}
void DXFInterface::writeTextstyles(){}
void DXFInterface::writeVports(){}
