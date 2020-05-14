#include "xkernel.h"
#include "nsl_kernel.h"
#include "xnsl_qt_graph.h"
#include <QPainter>

xnsl_qt_graph::xnsl_qt_graph() : xnsl_qt_widget(), myCanvas(NULL), gflags(0)
{
        set_type("graph");
        set_abstract_type("graph");
}
xnsl_qt_graph::~xnsl_qt_graph()
{

}

xnsl_widget* xnsl_qt_graph::make_widget()
{
	return new xnsl_qt_graph;
}

int xnsl_qt_graph::display()
{
	widget->repaint();
	return 1;
}

int xnsl_qt_graph::xflush()
{
	return 1;
}

int xnsl_qt_graph::clear_area(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
	//clear area means clear the area between the rectangle x0, y0, x1, y1
    QLabel *graph_area = (QLabel*)(this->widget);
    const QPixmap *other = graph_area->pixmap();

    QPainter paint(drawmap);

	//draw stage
    QRectF rect(wx0, wy0, wx1, wy1);

    if (other != NULL)
    	paint.drawPixmap(other->rect(), *other);

    paint.drawRect(rect);
	paint.fillRect(rect, Qt::white);
    //end draw

    graph_area->setPixmap(*drawmap);

	return 1;
}

int xnsl_qt_graph::fill_rectangle(xnsl_widget* xwidget,int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
    QLabel *graph_area = (QLabel*)(this->widget);
    const QPixmap *other = graph_area->pixmap();

	QPainter paint(drawmap);

    QRectF rect(wx0, wy0, wx1, wy1);

    //cout << "RECT: x0 " << wx0 << " y0 " << wy0 << " x1 " << wx1 << " y1 " << wy1 << endl;

	//draw stage
	if (other != NULL)
	paint.drawPixmap(other->rect(), *other);

    if (pos == 1) //fill black
    {
    	paint.drawRect(rect);
    	paint.fillRect(rect, Qt::black);
    }

    else paint.drawRect(rect);
    //end draw

    graph_area->setPixmap(*drawmap);

	return 1;
}

int xnsl_qt_graph::draw_line(xnsl_widget* xwidget,int wx0,int wy0,int wx1,int wy1,
	int tt,int ni,int nj,int pos,const char* color,int fg)
{
    QLabel *graph_area = (QLabel*)(this->widget);
    const QPixmap *other = graph_area->pixmap();

	QPainter paint(drawmap);

	wy0 = _height - wy0;
	wy1 = _height - wy1;

	//list of colors
	char *colorname[] {
			"black",
	        "white",
	        "darkGray",
	        "gray",
	        "lightGray",
	        "red",
	        "green",
	        "blue",
	        "cyan",
	        "magenta",
	        "yellow" };

	int cnum = -1;

	//find the correct color and match it to the qt id
	for (int i = 0; i < 10; i++)
		if (strcmp(color, colorname[i]) == 0)
		{
			cnum = i;
			break;
		}

	if (cnum == -1)
		cnum = 2;

	else cnum += 2; //offsets to black or higher (qt enum)

	//draw stage
	if (other != NULL)
	paint.drawPixmap(other->rect(), *other);

    paint.setBrush(QBrush(cnum));
    paint.drawLine(wx0,wy0,wx1,wy1);
	//end draw

   // cout << widget << " pos: " << pos << " Line: x0: " << wx0 << " y0: " << wy0 << " x1: " << wx1 << " y1 " << wy1 << endl;

    graph_area->setPixmap(*drawmap);

	return 1;
}

int xnsl_qt_graph::draw_grid(xnsl_widget* xwidget,int wx0,int wy0,int wx1,int wy1,
	int wxs,int wys,num_type x0, num_type y0, num_type x1, num_type y1,
	num_type xs, num_type ys,int fg)
{
		for (int x = wx0; x <= wx1; x += wxs)
   			draw_line(xwidget,x,wy0,x,wy1,0,0,0,1,"black",0);
		for (int y = wy1; y >= wy0; y -= wys)
			draw_line(xwidget,wx0,y,wx1,y,0,0,0,1,"black",0);

	return 1;
}
int xnsl_qt_graph::draw_text(xnsl_widget* ,int x,int y,const char*  str)
{
	QPainter painter( drawmap );
	painter.setFont( QFont("Arial") );
	painter.drawText( QPoint(x, y), str );

	return 1;
}

xnsl_widget* xnsl_qt_graph::create_widget(const char *wname,
	xnsl_widget* pxnsl_widget,int x,int y,int w,int h,
	int,int,int,int,int,int,const char*,const char*)
{
	strcpy(_wname,wname);
	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

	xnsl_qt_canvas *canvas = (xnsl_qt_canvas*)pxnsl_widget;

	if (canvas == NULL || canvas->GetWidget() == NULL)
	{
		cmd_error("XNSL QT GRAPH: NULL PARENT");
		widget = NULL;
		return this;
	}

	xnsl_qt_frame *frame = canvas->GetFrame();

	if (frame == NULL)
	{
		cmd_error("XNSL QT GRAPH: NULL PARENT FRAME");
		widget = NULL;
		return this;
	}

	drawmap = new QPixmap(w, h);
	drawmap->fill(QColor("transparent"));

	widget = canvas->GetWidget(); //we would have just retrieved this often so assign it to this->widget

	//fill_rectangle(this, 5, 5, 5, 5, 5, 5, 1, 5); test to fill rectangles

	return this;
}

int xnsl_qt_graph::print(ostream&) const //empty ...
{
	return 1;
}


