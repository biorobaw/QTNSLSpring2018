#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_qt_canvas.h"
#include "xlib_qt_canvascontrol.h"

xnsl_qt_canvas::xnsl_qt_canvas() : xnsl_qt_widget(), xpos(0), masterFrame(NULL)
{
	set_type("canvas");
}

xnsl_qt_canvas::~xnsl_qt_canvas()
{
}

int xnsl_qt_canvas::clear_area(xnsl_widget* xwidget,int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
	//canvas is a draw area inside the frame so clear area should be called by any child widgets with a pixmap
	//since canvas is effectively just a frame, clear area neednt be called here
	return 1;
}
void  xnsl_qt_canvas::redraw() //called every step of a simulation -bn7
{
	widget->repaint();
}

xnsl_widget*  xnsl_qt_canvas::create_widget(const char   *wname,
	xnsl_widget     *pxnsl_widget, int, int,
	int width, int height, int, int, int, int, int, int,
	const char* side, const char*) // side taken from label
{
     strcpy(_wname,wname);
     _width = width;
     _height = height;

     xnsl_qt_frame *frame = (xnsl_qt_frame*)pxnsl_widget;


     if (frame == NULL)
     {
    	 cmd_error("XNSL QT CANVAS: NULL PARENT");
    	 widget = NULL;
     }

     else //configure canvas
     {
    	 QWidget *qparent = frame->GetWidget();

    	 if (qparent == NULL)
    	 {
    		 cmd_error("XNSL QT CANVAS: NULL PARENT WIDGET");
    		 widget = NULL;
    		 return NULL;
    	 }

    	 	masterFrame = frame; //need to point to the actual window for paint events
    		xlib_qt_framecontrol *qframe = (xlib_qt_framecontrol*)qparent;

    		xpos = qframe->GetNextChildPos();

    		qframe->NewChildEvent(height, width);

    		QLabel *label = new QLabel(qparent);
    		label->move(2, xpos);
    		label->resize(width - 2, height - 2);
    		label->setFrameStyle(QFrame::Panel | QFrame::Plain);
    		label->setLineWidth(1);
    		label->show();
    		widget = label;
     }

   	 return (this);
}

xnsl_widget *xnsl_qt_canvas::make_widget()
{
	return new xnsl_qt_canvas();
}
