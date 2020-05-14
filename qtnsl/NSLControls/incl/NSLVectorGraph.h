#ifndef _NSLVECTORGRAPH_H
#define _NSLVECTORGRAPH_H
#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtWidgets/QMainWindow>
#include <QPicture>
#include <QPainter>
#include "../../QtCustomPlot/qcustomplot.h"

class NSLVectorGraph
{
private:
	QMainWindow Canvas;
	QWidget *drawRef;
	QCustomPlot **graph;
	QVector<double> *xdata;
	QVector<double> *ydata;
	char *labels;

	int X, Y, cellX, cellY;
	float xmax, xmin, ymax, ymin;
	int vectorSize;
	int charcount;

	float Xscale, Yscale;

public:
	void Draw();
	void Refresh();
	void Refresh(int);
	void show();
	void AddPoint(int, float);
	void ConfigureCell(int, int);
	void AddLabel(const char *, int);

	explicit NSLVectorGraph(QWidget *W = 0);
	NSLVectorGraph(QWidget *, int, int, int, int, int, float, float, float, float, float, float);
	~NSLVectorGraph();
};
#endif
