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

#ifndef DXFINTERFACE_H
#define DXFINTERFACE_H
#include "../libdxfrw/src/drw_interface.h"
#include <QList>
#include <QLineF>
#include <QPen>
#include <QGraphicsScene>
#include "scene_items.h"
#include "../dxfitem.h"

class DXFInterface : public DRW_Interface
{
public:
    DXFInterface(QString filename);
    DXFInterface();
    ~DXFInterface();
    //QGraphicsScene mScene;

    void iniDXF(QString filename);

    /** Called when header is parsed.  */
    void addHeader(const DRW_Header *);

    /** Called for every line Type.  */
    void addLType(const DRW_LType &);
    /** Called for every layer. */
    void addLayer(const DRW_Layer& data);
    /** Called for every dim style. */
    void addDimStyle(const DRW_Dimstyle &);
    /** Called for every VPORT table. */
    void addVport(const DRW_Vport &);
    /** Called for every text style. */
    void addTextStyle(const DRW_Textstyle &);

    /**
     * Called for every block. Note: all entities added after this
     * command go into this block until endBlock() is called.
    *
     * @see endBlock()
     */
    void addBlock(const DRW_Block &);

    /**
     * In DWG called when the following entities corresponding to a
     * block different from the current. Note: all entities added after this
     * command go into this block until setBlock() is called already.
     *
     * int handle are the value of DRW_Block::handleBlock added with addBlock()
     */

    void setBlock(const int);

    /** Called to end the current block */
    void endBlock();

    /** Called for every point */
    void addPoint(const DRW_Point& data);

    /** Called for every line */
    void addLine(const DRW_Line& data);

    /** Called for every ray */
    void addRay(const DRW_Ray &);

    /** Called for every xline */
    void addXline(const DRW_Xline &);

    /** Called for every arc */
    void addArc(const DRW_Arc& data);

    /** Called for every circle */
    //QGraphicsEllipseItem* addCircle(const DRW_Circle& data);
    void addCircle(const DRW_Circle& data);

    /** Called for every ellipse */
    void addEllipse(const DRW_Ellipse& data);

    /** Called for every lwpolyline */
    void addLWPolyline(const DRW_LWPolyline& data);

    /** Called for every polyline start */
    void addPolyline(const DRW_Polyline& data);

    /** Called for every spline */
    void addSpline(const DRW_Spline* data);

    /** Called for every spline knot value */
    void addKnot(const DRW_Entity &);

    /** Called for every insert. */
    void addInsert(const DRW_Insert &);

    /** Called for every trace start */
    void addTrace(const DRW_Trace &);

    /** Called for every 3dface start */
    void add3dFace(const DRW_3Dface &);

    /** Called for every solid start */
    void addSolid(const DRW_Solid &);


    /** Called for every Multi Text entity. */
    void addMText(const DRW_MText&);

    /** Called for every Text entity. */
    void addText(const DRW_Text&);

    /**
     * Called for every aligned dimension entity.
     */
    void addDimAlign(const DRW_DimAligned *);
    /**
     * Called for every linear or rotated dimension entity.
     */
    void addDimLinear(const DRW_DimLinear *);

    /**
     * Called for every radial dimension entity.
     */
    void addDimRadial(const DRW_DimRadial *);

    /**
     * Called for every diametric dimension entity.
     */
    void addDimDiametric(const DRW_DimDiametric *);

    /**
     * Called for every angular dimension (2 lines version) entity.
     */
    void addDimAngular(const DRW_DimAngular *);

    /**
     * Called for every angular dimension (3 points version) entity.
     */
    void addDimAngular3P(const DRW_DimAngular3p *);

    /**
     * Called for every ordinate dimension entity.
     */
    void addDimOrdinate(const DRW_DimOrdinate *);

    /**
     * Called for every leader start.
     */
    void addLeader(const DRW_Leader *data);

    /**
     * Called for every hatch entity.
     */
    void addHatch(const DRW_Hatch *);

    /**
     * Called for every viewport entity.
     */
    void addViewport(const DRW_Viewport &);

    /**
     * Called for every image entity.
     */
    void addImage(const DRW_Image *);

    /**
     * Called for every image definition.
     */
    void linkImage(const DRW_ImageDef *);

    /**
     * Called for every comment in the DXF file (code 999).
     */
    void addComment(const char *);

    void writeHeader(DRW_Header &);
    void writeBlocks();
    void writeBlockRecords();
    void writeEntities();
    void writeLTypes();
    void writeLayers();
    void writeTextstyles();
    void writeVports();
    void writeDimstyles();


    void drawPolyline(std::vector<DRW_Vertex*> vertlist);
    QGraphicsScene * scene();

    DxfItem *dxf_item;
    QList<QPointF> pointsF;
    QList<QLineF> linesF;
    QList<QRectF> circlesF;

private:
    // sets min / max points of x and y
    void set_boundary(double x, double y);
    double minx, miny, maxx, maxy;

    //QList<DRW_Layer> layers;
    //QList<SceneArc*> arches;

    //QList<DRW_Arc> arcs;
    //QList<DRW_Circle> circles;
    //QList<DRW_Line> lines;
    //QList<DRW_Point> points;





};

#endif // DXFINTERFACE_H
